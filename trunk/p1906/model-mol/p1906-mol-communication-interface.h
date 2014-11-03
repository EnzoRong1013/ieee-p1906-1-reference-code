/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 *  Copyright � 2014 by IEEE.
 *
 *  This source file is an essential part of IEEE Std 1906.1,
 *  Recommended Practice for Nanoscale and Molecular
 *  Communication Framework.
 *  Verbatim copies of this source file may be used and
 *  distributed without restriction. Modifications to this source
 *  file as permitted in IEEE Std 1906.1 may also be made and
 *  distributed. All other uses require permission from the IEEE
 *  Standards Department (stds-ipr@ieee.org). All other rights
 *  reserved.
 *
 *  This source file is provided on an AS IS basis.
 *  The IEEE disclaims ANY WARRANTY EXPRESS OR IMPLIED INCLUDING
 *  ANY WARRANTY OF MERCHANTABILITY AND FITNESS FOR USE FOR A
 *  PARTICULAR PURPOSE.
 *  The user of the source file shall indemnify and hold
 *  IEEE harmless from any damages or liability arising out of
 *  the use thereof.
 *
 * Author: Giuseppe Piro - Telematics Lab Research Group
 *                         Politecnico di Bari
 *                         giuseppe.piro@poliba.it
 *                         telematics.poliba.it/piro
 */


#ifndef P1906_MOL__COMMUNICATION_INTERFACE
#define P1906_MOL__COMMUNICATION_INTERFACE

#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include "ns3/p1906-communication-interface.h"

namespace ns3 {


/**
 * \ingroup P1906 framework
 *
 * \class P1906MOLCommunicationInterface
 *
 * \brief Base class implementing a communication interface, which
 * is a container of the transmitter and the receiver entities, for
 * the MOLECULAR Example
 */

class P1906MOLCommunicationInterface : public P1906CommunicationInterface
{
public:
  static TypeId GetTypeId (void);

  P1906MOLCommunicationInterface ();
  virtual ~P1906MOLCommunicationInterface ();

private:
};

}

#endif /* P1906_MOL_COMMUNICATION_INTERFACE */
