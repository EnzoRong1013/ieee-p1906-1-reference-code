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

#ifndef P1906_EM_MOTION
#define P1906_EM_MOTION

#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include "../model-core/p1906-motion.h"

namespace ns3 {

/**
 * \ingroup P1906 framework
 *
 * \class P1906EMMotion
 *
 * \brief Base class implementing the Motion component of
 * the P1906 framework, dedicated to the EM example
 */

class P1906EMMotion : public P1906Motion
{
public:
  static TypeId GetTypeId (void);

  P1906EMMotion ();
  virtual ~P1906EMMotion ();

  virtual double ComputePropagationDelay (Ptr<P1906CommunicationInterface> src,
  		                                  Ptr<P1906CommunicationInterface> dst,
  		                                  Ptr<P1906MessageCarrier> message,
  		                                  Ptr<P1906Field> field);

  virtual Ptr<P1906MessageCarrier> CalculateReceivedMessageCarrier(Ptr<P1906CommunicationInterface> src,
  		                                                           Ptr<P1906CommunicationInterface> dst,
  		                                                           Ptr<P1906MessageCarrier> message,
  		                                                           Ptr<P1906Field> field);

  void SetWaveSpeed (double s);
  double GetWaveSpeed (void);

private:
  double m_waveSpeed;
};

}

#endif /* P1906_EM_MOTION */
