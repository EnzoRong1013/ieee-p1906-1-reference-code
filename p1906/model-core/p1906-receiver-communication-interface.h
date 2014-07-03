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

#ifndef P1906_RECEIVER_COMMUNICATION_INTERFACE
#define P1906_RECEIVER_COMMUNICATION_INTERFACE

#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"

#include "p1906-communication-interface.h"

namespace ns3 {

class Packet;
class P1906Specificity;
class P1906MessageCarrier;
class P1906CommunicationInterface;
class P1906Medium;
class P1906NetDevice;
class P1906Motion;

/**
 * \ingroup P1906 framework
 *
 * \class P1906ReceiverCommunicationInterface
 *
 * \brief Base class implementing a the Receiver entity
 * of the P1906 framework
 */

class P1906ReceiverCommunicationInterface : public Object
{
public:
  static TypeId GetTypeId (void);

  P1906ReceiverCommunicationInterface ();
  virtual ~P1906ReceiverCommunicationInterface();

  void SetP1906Specificity (Ptr<P1906Specificity> s);
  Ptr<P1906Specificity> GetP1906Specificity ();

  void SetP1906CommunicationInterface (Ptr<P1906CommunicationInterface> i);
  Ptr<P1906CommunicationInterface> GetP1906CommunicationInterface (void);

  virtual void HandleReception (Ptr<P1906CommunicationInterface> src, Ptr<P1906CommunicationInterface> dst, Ptr<P1906MessageCarrier> message);

  void SetP1906NetDevice (Ptr<P1906NetDevice> d);
  Ptr<P1906NetDevice> GetP1906NetDevice ();

  void SetP1906Medium (Ptr<P1906Medium> m);
  Ptr<P1906Medium> GetP1906Medium ();

private:
  Ptr<P1906Specificity> m_specificity;
  Ptr<P1906CommunicationInterface> m_p1906CommunicationInterface;
  Ptr<P1906NetDevice> m_dev;
  Ptr<P1906Medium> m_medium;
};

}

#endif /* P1906_RECEIVER_COMMUNICATION_INTERFACE */
