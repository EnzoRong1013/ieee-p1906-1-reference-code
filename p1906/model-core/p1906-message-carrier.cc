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
#include "ns3/packet.h"
#include "p1906-message-carrier.h"


namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906MessageCarrier");

TypeId P1906MessageCarrier::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906MessageCarrier")
    .SetParent<Object> ();
  return tid;
}

P1906MessageCarrier::P1906MessageCarrier ()
{
  NS_LOG_FUNCTION (this);
  m_message = 0;
}

P1906MessageCarrier::~P1906MessageCarrier ()
{
  NS_LOG_FUNCTION (this);
  m_message = 0;
}

void
P1906MessageCarrier::SetMessage (Ptr<Packet> message)
{
  NS_LOG_FUNCTION (this);
  m_message = message;
}

Ptr<Packet>
P1906MessageCarrier::GetMessage ()
{
  NS_LOG_FUNCTION (this);
  return m_message;
}


} // namespace ns3
