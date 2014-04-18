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

#ifndef P1906_COMMUNICATION_INTERFACE
#define P1906_COMMUNICATION_INTERFACE

#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"

namespace ns3 {

class P1906Medium;
class P1906NetDevice;
class P1906ReceiverCommunicationInterface;
class P1906TransmitterCommunicationInterface;
class Packet;


/**
 * \ingroup P1906 framework
 *
 * \class P1906CommunicationInterface
 *
 * \brief Base class implementing a communication interface, which
 * is a container of the transmitter and the receiver entities.
 */

class P1906CommunicationInterface : public Object
{
public:
  static TypeId GetTypeId (void);

  P1906CommunicationInterface ();
  virtual ~P1906CommunicationInterface ();

  void SetP1906TransmitterCommunicationInterface (Ptr<P1906TransmitterCommunicationInterface> tx);
  Ptr<P1906TransmitterCommunicationInterface> GetP1906TransmitterCommunicationInterface ();

  void SetP1906ReceiverCommunicationInterface (Ptr<P1906ReceiverCommunicationInterface> rx);
  Ptr<P1906ReceiverCommunicationInterface> GetP1906ReceiverCommunicationInterface ();

  void SetP1906NetDevice (Ptr<P1906NetDevice> d);
  Ptr<P1906NetDevice> GetP1906NetDevice ();

  void SetP1906Medium (Ptr<P1906Medium> m);
  Ptr<P1906Medium> GetP1906Medium ();

  bool HandleTransmission (Ptr<Packet> p);
  void HandleReception (Ptr<Packet> p);

private:
  Ptr<P1906NetDevice> m_dev;
  Ptr<P1906TransmitterCommunicationInterface> m_tx;
  Ptr<P1906ReceiverCommunicationInterface> m_rx;
  Ptr<P1906Medium> m_medium;
};

}

#endif /* P1906_COMMUNICATION_INTERFACE */
