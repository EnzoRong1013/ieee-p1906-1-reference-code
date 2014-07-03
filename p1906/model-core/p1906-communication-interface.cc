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

#include "p1906-communication-interface.h"
#include "p1906-transmitter-communication-interface.h"
#include "p1906-receiver-communication-interface.h"
#include <ns3/packet.h>
#include "p1906-medium.h"
#include "p1906-net-device.h"


namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906CommunicationInterface");

TypeId P1906CommunicationInterface::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906CommunicationInterface")
    .SetParent<Object> ();
  return tid;
}

P1906CommunicationInterface::P1906CommunicationInterface ()
{
  NS_LOG_FUNCTION (this << "aaa");
  m_dev = 0;
  m_tx = CreateObject<P1906TransmitterCommunicationInterface> ();
  m_rx = CreateObject<P1906ReceiverCommunicationInterface> ();

  m_tx->SetP1906CommunicationInterface (this);
  m_rx->SetP1906CommunicationInterface (this);

  m_medium = 0;
}

P1906CommunicationInterface::~P1906CommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
  m_dev = 0;
  m_tx = 0;
  m_rx = 0;
  m_medium = 0;
}

void
P1906CommunicationInterface::SetP1906NetDevice (Ptr<P1906NetDevice> d)
{
  NS_LOG_FUNCTION (this);
  m_dev = d;
}

Ptr<P1906NetDevice>
P1906CommunicationInterface::GetP1906NetDevice ()
{
  NS_LOG_FUNCTION (this);
  return m_dev;
}

void
P1906CommunicationInterface::SetP1906TransmitterCommunicationInterface (Ptr<P1906TransmitterCommunicationInterface> tx)
{
  NS_LOG_FUNCTION (this);
  m_tx = tx;
}

Ptr<P1906TransmitterCommunicationInterface>
P1906CommunicationInterface::GetP1906TransmitterCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
  return m_tx;
}
void
P1906CommunicationInterface::SetP1906ReceiverCommunicationInterface (Ptr<P1906ReceiverCommunicationInterface> rx)
{
  NS_LOG_FUNCTION (this);
  m_rx = rx;
}

Ptr<P1906ReceiverCommunicationInterface>
P1906CommunicationInterface::GetP1906ReceiverCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
  return m_rx;
}

bool
P1906CommunicationInterface::HandleTransmission (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this << "Transmitting a packet [id,size]" << p->GetUid() << p->GetSize ());
  return m_tx->HandleTransmission (p);
}

void P1906CommunicationInterface::HandleReception (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this << "Receiving a packet [id,size]" << p->GetUid() << p->GetSize ());
  //XXX: forward the message to upper layers
}

void
P1906CommunicationInterface::SetP1906Medium (Ptr<P1906Medium> m)
{
  NS_LOG_FUNCTION (this);
  m_medium = m;
  m_tx->SetP1906Medium (m);
  m_rx->SetP1906Medium (m);
}

Ptr<P1906Medium>
P1906CommunicationInterface::GetP1906Medium ()
{
  NS_LOG_FUNCTION (this);
  return m_medium;
}


} // namespace ns3
