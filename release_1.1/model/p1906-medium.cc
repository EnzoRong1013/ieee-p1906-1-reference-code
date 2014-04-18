/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2014 TELEMATICS LAB, DEI - Politecnico di Bari
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Giuseppe Piro - Telematics Lab Research Group
 *                         peppe@giuseppepiro.com, g.piro@poliba.it
 *                         telematics.poliba.it/piro
 */

#include "ns3/object.h"
#include "ns3/packet.h"
#include "ns3/simulator.h"
#include "ns3/net-device.h"
#include "ns3/node.h"
#include "ns3/log.h"
#include "ns3/pointer.h"
#include "p1906-medium.h"
#include "p1906-communication-interface.h"
#include "p1906-field.h"
#include "p1906-force.h"
#include "p1906-message-carrier.h"
#include "p1906-receiver-communication-interface.h"
#include "p1906-specificity.h"


NS_LOG_COMPONENT_DEFINE ("P1906Medium");
namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (P1906Medium);

TypeId
P1906Medium::GetTypeId ()
{
  static TypeId tid = TypeId ("ns3::P1906Medium")
    .SetParent<Channel> ()
    .AddConstructor<P1906Medium> ()
  ;

  return tid;
}

P1906Medium::P1906Medium ()
  : Channel ()
{
  NS_LOG_FUNCTION (this);
  m_communicationInterfaces = new P1906CommunicationInterfaces ();
  m_force = 0;
}

P1906Medium::~P1906Medium ()
{
  NS_LOG_FUNCTION (this);
  m_communicationInterfaces = 0;
  m_force = 0;
}

void
P1906Medium::DoDispose ()
{
  Channel::DoDispose ();
  m_communicationInterfaces = 0;
  m_force = 0;
  NS_LOG_FUNCTION (this);
}

uint32_t
P1906Medium::GetNDevices () const
{
  NS_LOG_FUNCTION (this);
  return 0;//NOT USED IN P1906
}

Ptr<NetDevice>
P1906Medium::GetDevice (uint32_t i) const
{
  NS_LOG_FUNCTION (this);
  return 0; //NOT USED IN P1906
}

void
P1906Medium::SetP1906Force (Ptr<P1906Force> f)
{
  NS_LOG_FUNCTION (this);
  m_force = f;
}

Ptr<P1906Force>
P1906Medium::GetP1906Force ()
{
  NS_LOG_FUNCTION (this);
  return m_force;
}

void
P1906Medium::HandleTransmission (Ptr<P1906CommunicationInterface> src,
                                 Ptr<P1906MessageCarrier> message,
                                 Ptr<P1906Field> field)
{
  NS_LOG_FUNCTION (this);
  /*
   * XXX
   * In this part of the framework, the Medium should adopt components
   * Field and Force to properly deliver the massage to the destination node.
   * Its implementation depends from the use case. However, we should provide a generic
   * implementation of the function.
   * Basically, the Medium should evaluate the modification of the message carrier
   * by considering both Field and Force. In addition it should also compute the delivering delay.
   */
  std::vector< Ptr<P1906CommunicationInterface> >::iterator it;
  for (it = m_communicationInterfaces->begin (); it != m_communicationInterfaces->end (); it++)
    {
	  Ptr<P1906CommunicationInterface> dst = *it;
	  if (dst != src)
	    {
          Ptr<P1906MessageCarrier> receivedMessageCarrier;
          double delay;

          if (m_force)
            {
        	   delay = m_force->ComputePropagationDelay (src, dst, message, field);
               receivedMessageCarrier = m_force->CalculateReceivedMessageCarrier(src, dst, message, field);
            }
          else
            {
              NS_LOG_FUNCTION (this << "The force component has not been configured");
              receivedMessageCarrier = message;
              delay = 0.;
            }

          Simulator::Schedule(Seconds (delay), &P1906Medium::HandleReception, this, dst, receivedMessageCarrier);
	    }
    }
}

void
P1906Medium::HandleReception (Ptr<P1906CommunicationInterface> dst, Ptr<P1906MessageCarrier> message)
{
  NS_LOG_FUNCTION (this);
  Ptr<P1906ReceiverCommunicationInterface> rx = dst->GetP1906ReceiverCommunicationInterface ();
  if (rx->GetP1906Specificity ()->CheckRxCompatibility (message))
    {
	  //manage the packet
	  Ptr<Packet> p = message->GetMessage ();
	  dst->HandleReception (p);
    }
  else
    {
	  //ignore the received carrier message
    }
}

void
P1906Medium::AddP1906CommunicationInterface (Ptr<P1906CommunicationInterface> i)
{
  NS_LOG_FUNCTION (this);
  m_communicationInterfaces->push_back (i);
}



} // namespace ns3
