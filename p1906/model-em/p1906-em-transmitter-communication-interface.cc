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

#include "p1906-em-transmitter-communication-interface.h"
#include "../model-core/p1906-net-device.h"
#include <ns3/packet.h>
#include "../model-core/p1906-perturbation.h"
#include "../model-core/p1906-field.h"
#include "../model-core/p1906-message-carrier.h"
#include "../model-core/p1906-communication-interface.h"
#include "../model-core/p1906-medium.h"
#include "ns3/packet.h"
#include "../model-core/p1906-medium.h"
#include "../model-core/p1906-net-device.h"




namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906EMTransmitterCommunicationInterface");

TypeId P1906EMTransmitterCommunicationInterface::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906EMTransmitterCommunicationInterface")
    .SetParent<P1906TransmitterCommunicationInterface> ();
  return tid;
}

P1906EMTransmitterCommunicationInterface::P1906EMTransmitterCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
}

P1906EMTransmitterCommunicationInterface::~P1906EMTransmitterCommunicationInterface ()
{
  NS_LOG_FUNCTION (this);
}



} // namespace ns3
