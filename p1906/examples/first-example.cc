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


#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/p1906-helper.h"
#include "ns3/p1906-net-device.h"
#include "ns3/p1906-perturbation.h"
#include "ns3/p1906-field.h"
#include "ns3/p1906-motion.h"
#include "ns3/p1906-specificity.h"
#include "ns3/p1906-medium.h"
#include "ns3/p1906-communication-interface.h"
#include "ns3/p1906-transmitter-communication-interface.h"
#include "ns3/p1906-receiver-communication-interface.h"

using namespace ns3;


int main (int argc, char *argv[])
{	

  // Create P1906 Helper
  P1906Helper helper;
  helper.EnableLogComponents ();

  // Create nodes (typical operation of ns-3)
  NodeContainer n;
  NetDeviceContainer d;
  n.Create (2);

  // Create a medium and the Motion component
  Ptr<P1906Medium> medium = CreateObject<P1906Medium> ();
  Ptr<P1906Motion> motion = CreateObject<P1906Motion> ();
  medium->SetP1906Motion (motion);


  // Create Device 1 and related components/entities
  Ptr<P1906NetDevice> dev1 = CreateObject<P1906NetDevice> ();
  Ptr<P1906CommunicationInterface> c1 = CreateObject<P1906CommunicationInterface> ();
  Ptr<P1906Specificity> s1 = CreateObject<P1906Specificity> ();
  Ptr<P1906Field> fi1 = CreateObject<P1906Field> ();
  Ptr<P1906Perturbation> p1 = CreateObject<P1906Perturbation> ();

  // Create Device 2 and related components/entities
  Ptr<P1906NetDevice> dev2 = CreateObject<P1906NetDevice> ();
  Ptr<P1906CommunicationInterface> c2 = CreateObject<P1906CommunicationInterface> ();
  Ptr<P1906Specificity> s2 = CreateObject<P1906Specificity> ();
  Ptr<P1906Field> fi2 = CreateObject<P1906Field> ();
  Ptr<P1906Perturbation> p2 = CreateObject<P1906Perturbation> ();

  // Connect devices, nodes, medium, components and entities
  d.Add (dev1);
  d.Add (dev2);
  helper.Connect(n.Get (0),dev1,medium,c1,fi1, p1,s1);
  helper.Connect(n.Get (1),dev2,medium,c2,fi2, p2,s2);



  // Create a message to sent into the network
  int pktSize = 1; //bytes
  uint8_t *buffer  = new uint8_t[pktSize];
  for (int i = 0; i < pktSize; i++)
    {
	  buffer[i] = 0; //empty information
    }
  Ptr<Packet> message = Create<Packet>(buffer, pktSize);

  c1->HandleTransmission (message);


  Simulator::Stop (Seconds (0.01));
  Simulator::Run ();


  Simulator::Destroy ();
  return 0;
}
