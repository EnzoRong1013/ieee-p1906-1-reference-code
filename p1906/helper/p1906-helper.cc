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

#include "p1906-helper.h"
#include "ns3/simulator.h"
#include "ns3/packet.h"
#include "ns3/log.h"
#include "ns3/pointer.h"
#include <string>
#include "ns3/config.h"
#include "../model-core/p1906-net-device.h"
#include "../model-core/p1906-perturbation.h"
#include "../model-core/p1906-field.h"
#include "../model-core/p1906-specificity.h"
#include "../model-core/p1906-medium.h"
#include "../model-core/p1906-communication-interface.h"
#include "../model-core/p1906-transmitter-communication-interface.h"
#include "../model-core/p1906-receiver-communication-interface.h"

NS_LOG_COMPONENT_DEFINE ("P1906Helper");

namespace ns3 {

P1906Helper::P1906Helper (void)
{}

P1906Helper::~P1906Helper (void)
{}

void
P1906Helper::Connect (Ptr<Node> n, Ptr<P1906NetDevice> d, Ptr<P1906Medium> m, Ptr<P1906CommunicationInterface> c, Ptr<P1906Field> fi, Ptr<P1906Perturbation> p, Ptr<P1906Specificity> s)
{
  d->SetNode (n);
  n->AddDevice (d);
  c->SetP1906NetDevice (d);
  c->SetP1906Medium (m);
  c->GetP1906TransmitterCommunicationInterface ()->SetP1906Perturbation (p);
  c->GetP1906TransmitterCommunicationInterface ()->SetP1906Field (fi);
  c->GetP1906ReceiverCommunicationInterface ()->SetP1906Specificity (s);
  s->SetP1906CommunicationInterface (c);
  m->AddP1906CommunicationInterface (c);
}

void 
P1906Helper::EnableLogComponents (void)
{
  LogComponentEnable ("P1906CommunicationInterface", LOG_LEVEL_ALL);
  LogComponentEnable ("P1906Field", LOG_LEVEL_ALL);
  LogComponentEnable ("P1906Motion", LOG_LEVEL_ALL);
  LogComponentEnable ("P1906Medium", LOG_LEVEL_ALL);
  LogComponentEnable ("P1906MessageCarrier", LOG_LEVEL_ALL);
  LogComponentEnable ("P1906NetDevice", LOG_LEVEL_ALL);
  LogComponentEnable ("P1906Perturbation", LOG_LEVEL_ALL);
  LogComponentEnable ("P1906ReceiverCommunicationInterface", LOG_LEVEL_ALL);
  LogComponentEnable ("P1906Specificity", LOG_LEVEL_ALL);
  LogComponentEnable ("P1906TransmitterCommunicationInterface", LOG_LEVEL_ALL);

}


} // namespace ns3
