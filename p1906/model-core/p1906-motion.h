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

#ifndef P1906_MOTION
#define P1906_MOTION

#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"

namespace ns3 {


/**
 * \ingroup P1906 framework
 *
 * \class P1906Motion
 *
 * \brief Base class implementing the Force component of
 * the P1906 framework
 */

class P1906MessageCarrier;
class P1906CommunicationInterface;
class P1906Field;

class P1906Motion : public Object
{
public:
  static TypeId GetTypeId (void);

  P1906Motion ();
  virtual ~P1906Motion ();

  virtual double ComputePropagationDelay (Ptr<P1906CommunicationInterface> src,
  		                                  Ptr<P1906CommunicationInterface> dst,
  		                                  Ptr<P1906MessageCarrier> message,
  		                                  Ptr<P1906Field> field);

  virtual Ptr<P1906MessageCarrier> CalculateReceivedMessageCarrier(Ptr<P1906CommunicationInterface> src,
  		                                                           Ptr<P1906CommunicationInterface> dst,
  		                                                           Ptr<P1906MessageCarrier> message,
  		                                                           Ptr<P1906Field> field);

private:

};

}

#endif /* P1906_MOTION */
