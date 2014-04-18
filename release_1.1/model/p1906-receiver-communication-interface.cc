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

#include "ns3/log.h"

#include "p1906-receiver-communication-interface.h"
#include "p1906-net-device.h"
#include <ns3/packet.h>
#include "p1906-specificity.h"
#include "p1906-message-carrier.h"
#include "p1906-communication-interface.h"
#include "p1906-medium.h"
#include "p1906-net-device.h"


namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906ReceiverCommunicationInterface");

TypeId P1906ReceiverCommunicationInterface::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906ReceiverCommunicationInterface")
    .SetParent<Object> ();
  return tid;
}

P1906ReceiverCommunicationInterface::P1906ReceiverCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
  SetP1906NetDevice (0);
  m_specificity = 0;
}

P1906ReceiverCommunicationInterface::~P1906ReceiverCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
  SetP1906NetDevice (0);
  m_specificity = 0;
}

void
P1906ReceiverCommunicationInterface::SetP1906Specificity (Ptr<P1906Specificity> s)
{
  NS_LOG_FUNCTION (this);
  m_specificity = s;
}

Ptr<P1906Specificity>
P1906ReceiverCommunicationInterface::GetP1906Specificity ()
{
  NS_LOG_FUNCTION (this);
  return m_specificity;
}

void
P1906ReceiverCommunicationInterface::HandleReception (Ptr<P1906MessageCarrier> message)
{
  NS_LOG_FUNCTION (this);

  /*
   * In this part of the code, the received should use the
   * Specificity component to realize if the message can be
   * received or not.
   */

  bool isRxOk = GetP1906Specificity ()->CheckRxCompatibility (message);
  if (isRxOk)
    {
	  //elaborate the message carrier
	  Ptr<Packet> p = message->GetMessage ();
	  //xxx forward to upper layer
    }
  else
    {
	  //ignore the message carrier
    }

}

void
P1906ReceiverCommunicationInterface::SetP1906CommunicationInterface (Ptr<P1906CommunicationInterface> i)
{
  NS_LOG_FUNCTION (this);
  m_p1906CommunicationInterface = i;
}

Ptr<P1906CommunicationInterface>
P1906ReceiverCommunicationInterface::GetP1906CommunicationInterface (void)
{
  NS_LOG_FUNCTION (this);
  return m_p1906CommunicationInterface;
}

void
P1906ReceiverCommunicationInterface::SetP1906NetDevice (Ptr<P1906NetDevice> d)
{
  NS_LOG_FUNCTION (this);
  m_dev = d;
}

Ptr<P1906NetDevice>
P1906ReceiverCommunicationInterface::GetP1906NetDevice ()
{
  NS_LOG_FUNCTION (this);
  return m_dev;
}

void
P1906ReceiverCommunicationInterface::SetP1906Medium (Ptr<P1906Medium> m)
{
  NS_LOG_FUNCTION (this);
  m_medium = m;
}

Ptr<P1906Medium>
P1906ReceiverCommunicationInterface::GetP1906Medium ()
{
  NS_LOG_FUNCTION (this);
  return m_medium;
}

} // namespace ns3
