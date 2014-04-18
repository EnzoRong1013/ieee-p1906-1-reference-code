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

#ifndef P1906_TRANSMITTER_COMMUNICATION_INTERFACE
#define P1906_TRANSMITTER_COMMUNICATION_INTERFACE

#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"

#include "p1906-communication-interface.h"

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
 * \class P1906TransmitterCommunicationInterface
 *
 * \brief Base class implementing the Transmitter entity in
 * the P1906 framework
 */

class P1906TransmitterCommunicationInterface : public Object
{
public:
  static TypeId GetTypeId (void);

  P1906TransmitterCommunicationInterface ();
  virtual ~P1906TransmitterCommunicationInterface();

  virtual bool HandleTransmission (Ptr<Packet> p);

  void SetP1906Perturbation (Ptr<P1906Perturbation> p);
  Ptr<P1906Perturbation> GetP1906Perturbation ();

  void SetP1906CommunicationInterface (Ptr<P1906CommunicationInterface> i);
  Ptr<P1906CommunicationInterface> GetP1906CommunicationInterface (void);

  void SetP1906Field (Ptr<P1906Field> f);
  Ptr<P1906Field> GetP1906Field ();

  void SetP1906NetDevice (Ptr<P1906NetDevice> d);
  Ptr<P1906NetDevice> GetP1906NetDevice ();

  void SetP1906Medium (Ptr<P1906Medium> m);
  Ptr<P1906Medium> GetP1906Medium ();


private:
  Ptr<P1906Perturbation> m_perturbation;
  Ptr<P1906Field> m_field;
  Ptr<P1906CommunicationInterface> m_p1906CommunicationInterface;
  Ptr<P1906NetDevice> m_dev;
  Ptr<P1906Medium> m_medium;
};

}

#endif /* P1906_TRANSMITTER_COMMUNICATION_INTERFACE */
