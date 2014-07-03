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

#ifndef P1906_EM_TRANSMITTER_COMMUNICATION_INTERFACE
#define P1906_EM_TRANSMITTER_COMMUNICATION_INTERFACE

#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include "../model-core/p1906-communication-interface.h"
#include "../model-core/p1906-transmitter-communication-interface.h"

namespace ns3 {

class Packet;
class P1906Perturbation;
class P1906CommunicationInterface;
class P1906Field;
class P1906Force;
class P1906Medium;
class P1906NetDevice;


/**
 * \ingroup P1906 framework
 *
 * \class P1906EMTransmitterCommunicationInterface
 *
 * \brief Base class implementing the Transmitter entity in
 * the P1906 framework for the EM example
 */

class P1906EMTransmitterCommunicationInterface : public P1906TransmitterCommunicationInterface
{
public:
  static TypeId GetTypeId (void);

  P1906EMTransmitterCommunicationInterface ();
  virtual ~P1906EMTransmitterCommunicationInterface();

};

}

#endif /* P1906_EM_TRANSMITTER_COMMUNICATION_INTERFACE */
