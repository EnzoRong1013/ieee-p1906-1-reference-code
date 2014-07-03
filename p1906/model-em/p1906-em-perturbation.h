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


#ifndef P1906_EM_PERTURBATION
#define P1906_EM_PERTURBATION

#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include "../model-core/p1906-perturbation.h"

namespace ns3 {

/**
 * \ingroup P1906 framework
 *
 * \class P1906EMPerturbation
 *
 * \brief Base class implementing the Perturbation component of
 * the P1906 framework
 */

class P1906EMPerturbation : public P1906Perturbation
{
public:
  static TypeId GetTypeId (void);

  P1906EMPerturbation ();
  virtual ~P1906EMPerturbation ();

  virtual Ptr<P1906MessageCarrier> CreateMessageCarrier (Ptr<Packet> p);

  void SetPowerTransmission (double ptx);
  double GetPowerTransmission (void);
  void SetPulseDuration (Time t);
  Time GetPulseDuration (void);
  void SetPulseInterval (Time t);
  Time GetPulseInterval (void);

  void SetCentralFrequency (double f);
  double GetCentralFrequency (void);
  void SetBandwidth (double b);
  double GetBandwidth (void);
  void SetSubChannel (double c);
  double GetSubChannel (void);


private:
  double m_powerTx;
  Time m_pulseDuration;
  Time m_pulseInterval;
  double m_centralFrequency;
  double m_bandwidth;
  double m_subChannel;
};

}

#endif /* P1906_EM_PERTURBATION */
