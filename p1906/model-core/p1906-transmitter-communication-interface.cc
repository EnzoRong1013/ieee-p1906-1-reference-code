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

#include "p1906-transmitter-communication-interface.h"
#include "p1906-net-device.h"
#include <ns3/packet.h>
#include "p1906-perturbation.h"
#include "p1906-field.h"
#include "p1906-message-carrier.h"
#include "p1906-communication-interface.h"
#include "p1906-medium.h"
#include "ns3/packet.h"
#include "p1906-medium.h"
#include "p1906-net-device.h"




namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906TransmitterCommunicationInterface");

TypeId P1906TransmitterCommunicationInterface::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906TransmitterCommunicationInterface")
    .SetParent<Object> ();
  return tid;
}

P1906TransmitterCommunicationInterface::P1906TransmitterCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
  SetP1906NetDevice (0);
  m_perturbation = 0;
  m_field = 0;
}

P1906TransmitterCommunicationInterface::~P1906TransmitterCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
  SetP1906NetDevice (0);
  m_perturbation = 0;
}

void
P1906TransmitterCommunicationInterface::SetP1906Perturbation (Ptr<P1906Perturbation> p)
{
  NS_LOG_FUNCTION (this);
  m_perturbation = p;
}

Ptr<P1906Perturbation>
P1906TransmitterCommunicationInterface::GetP1906Perturbation ()
{
  NS_LOG_FUNCTION (this);
  return m_perturbation;
}

void
P1906TransmitterCommunicationInterface::SetP1906CommunicationInterface (Ptr<P1906CommunicationInterface> i)
{
  NS_LOG_FUNCTION (this);
  m_p1906CommunicationInterface = i;
}

Ptr<P1906CommunicationInterface>
P1906TransmitterCommunicationInterface::GetP1906CommunicationInterface (void)
{
  NS_LOG_FUNCTION (this);
  return m_p1906CommunicationInterface;
}

void
P1906TransmitterCommunicationInterface::SetP1906Field (Ptr<P1906Field> f)
{
  NS_LOG_FUNCTION (this);
  m_field = f;
}

Ptr<P1906Field>
P1906TransmitterCommunicationInterface::GetP1906Field ()
{
  NS_LOG_FUNCTION (this);
  return m_field;
}

bool
P1906TransmitterCommunicationInterface::HandleTransmission (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this);
  Ptr<P1906MessageCarrier> carrier = m_perturbation->CreateMessageCarrier(p);

  GetP1906Medium ()->HandleTransmission(m_p1906CommunicationInterface,
		                                carrier,
		                                m_field);

  return true;
}

void
P1906TransmitterCommunicationInterface::SetP1906NetDevice (Ptr<P1906NetDevice> d)
{
  NS_LOG_FUNCTION (this);
  m_dev = d;
}

Ptr<P1906NetDevice>
P1906TransmitterCommunicationInterface::GetP1906NetDevice ()
{
  NS_LOG_FUNCTION (this);
  return m_dev;
}

void
P1906TransmitterCommunicationInterface::SetP1906Medium (Ptr<P1906Medium> m)
{
  NS_LOG_FUNCTION (this);
  m_medium = m;
}

Ptr<P1906Medium>
P1906TransmitterCommunicationInterface::GetP1906Medium ()
{
  NS_LOG_FUNCTION (this);
  return m_medium;
}

} // namespace ns3
