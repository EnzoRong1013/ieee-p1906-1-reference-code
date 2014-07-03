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

#ifndef P1906_EM_MESSAGE_CARRIER
#define P1906_EM_MESSAGE_CARRIER

#include "ns3/object.h"
#include "ns3/nstime.h"
#include "ns3/ptr.h"
#include "../model-core/p1906-message-carrier.h"
#include <ns3/spectrum-value.h>


namespace ns3 {

class SpectrumValue;

/**
 * \ingroup P1906 framework
 *
 * \class P1906MessageCarrier
 *
 * \brief Base class implementing the Message Carrier component of
 * the P1906 framework
 */

class P1906EMMessageCarrier : public P1906MessageCarrier
{
public:
  static TypeId GetTypeId (void);

  P1906EMMessageCarrier ();
  virtual ~P1906EMMessageCarrier ();

  void SetSpectrumValue (Ptr<SpectrumValue>);
  Ptr<SpectrumValue> GetSpectrumValue (void);

  void SetDuration (Time t);
  Time GetDuration (void);
  void SetPulseDuration (Time t);
  Time GetPulseDuration (void);
  void SetPulseInterval (Time t);
  Time GetPulseInterval (void);
  void SetStartTime (Time t);
  Time GetStartTime (void);

  void SetCentralFrequency (double f);
  double GetCentralFrequency (void);
  void SetBandwidth (double b);
  double GetBandwidth (void);
  void SetSubChannel (double c);
  double GetSubChannel (void);

private:
  Ptr<SpectrumValue> m_spectrumValue;
  Time m_duration;
  Time m_pulseDuration;
  Time m_pulseInterval;
  Time m_startTime;
  double m_centralFrequency;
  double m_bandwidth;
  double m_subChannel;
};

}

#endif /* P1906_EM_MESSAGE_CARRIER */
