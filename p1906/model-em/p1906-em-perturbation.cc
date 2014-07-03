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


#include "ns3/log.h"
#include "ns3/packet.h"
#include "p1906-em-perturbation.h"
#include "../model-core/p1906-message-carrier.h"
#include "../model-core/p1906-perturbation.h"
#include "p1906-em-message-carrier.h"
#include "ns3/simulator.h"
#include "ns3/spectrum-value.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906EMPerturbation");

TypeId P1906EMPerturbation::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906EMPerturbation")
    .SetParent<P1906Perturbation> ();
  return tid;
}

P1906EMPerturbation::P1906EMPerturbation ()
{
  NS_LOG_FUNCTION (this);
}

P1906EMPerturbation::~P1906EMPerturbation ()
{
  NS_LOG_FUNCTION (this);
}

void
P1906EMPerturbation::SetPowerTransmission (double ptx)
{
  NS_LOG_FUNCTION (this << ptx);
  m_powerTx = ptx;
}

double
P1906EMPerturbation::GetPowerTransmission (void)
{
  NS_LOG_FUNCTION (this);
  return m_powerTx;
}

void
P1906EMPerturbation::SetPulseDuration (Time t)
{
  NS_LOG_FUNCTION (this << t);
  m_pulseDuration = t;
}

Time
P1906EMPerturbation::GetPulseDuration (void)
{
  NS_LOG_FUNCTION (this);
  return m_pulseDuration;
}

void
P1906EMPerturbation::SetPulseInterval (Time t)
{
  NS_LOG_FUNCTION (this << t);
  m_pulseInterval = t;
}

Time
P1906EMPerturbation::GetPulseInterval (void)
{
  NS_LOG_FUNCTION (this);
  return m_pulseInterval;
}

void
P1906EMPerturbation::SetCentralFrequency (double f)
{
  NS_LOG_FUNCTION (this << f);
  m_centralFrequency = f;
}

double
P1906EMPerturbation::GetCentralFrequency (void)
{
  NS_LOG_FUNCTION (this);
  return m_centralFrequency;
}

void
P1906EMPerturbation::SetBandwidth (double b)
{
  NS_LOG_FUNCTION (this << b);
  m_bandwidth = b;
}

double
P1906EMPerturbation::GetBandwidth (void)
{
  NS_LOG_FUNCTION (this);
  return m_bandwidth;
}

void
P1906EMPerturbation::SetSubChannel (double c)
{
  NS_LOG_FUNCTION (this << c);
  m_subChannel = c;
}

double
P1906EMPerturbation::GetSubChannel (void)
{
  NS_LOG_FUNCTION (this);
  return m_subChannel;
}

Ptr<P1906MessageCarrier>
P1906EMPerturbation::CreateMessageCarrier (Ptr<Packet> p)
{
  NS_LOG_FUNCTION (this);
  Ptr<P1906EMMessageCarrier> carrier = CreateObject<P1906EMMessageCarrier> ();

  double duration = m_pulseDuration.GetSeconds () * p->GetSize ();
  double now = Simulator::Now ().GetSeconds ();

  NS_LOG_FUNCTION (this << now << p->GetSize()
		  << m_pulseDuration.GetSeconds() << m_pulseInterval.GetSeconds()
		  << duration);

  //create the vector of frequencies
  std::vector<double> freqs;
  int nb_of_subchannels = GetBandwidth ()/GetSubChannel ();
  double startFrequency = GetCentralFrequency () - (GetSubChannel() * nb_of_subchannels/2);
  for (int i = 0; i < nb_of_subchannels; ++i)
    {
      freqs.push_back (startFrequency + (i*GetSubChannel ()));
    }
  Ptr<SpectrumModel> NanoSpectrumModel = Create<SpectrumModel> (freqs);

  Ptr<SpectrumValue> txPsd = Create <SpectrumValue> (NanoSpectrumModel);
  double txPowerDensity = (m_powerTx / txPsd->GetSpectrumModel ()->GetNumBands ())/
		  GetSubChannel ();
  (*txPsd) = txPowerDensity;

  carrier->SetPulseDuration (m_pulseDuration);
  carrier->SetPulseInterval (m_pulseInterval);
  carrier->SetDuration (Seconds(duration));
  carrier->SetCentralFrequency (GetCentralFrequency());
  carrier->SetBandwidth (GetBandwidth());
  carrier->SetSubChannel (GetSubChannel());
  carrier->SetSpectrumValue (txPsd);
  carrier->SetStartTime (Simulator::Now ());
  carrier->SetMessage (p);

  return carrier;
}

} // namespace ns3
