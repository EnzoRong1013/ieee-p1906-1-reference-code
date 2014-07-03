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
#include "p1906-em-message-carrier.h"
#include "../model-core/p1906-message-carrier.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906EMMessageCarrier");

TypeId P1906EMMessageCarrier::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906EMMessageCarrier")
    .SetParent<P1906MessageCarrier> ();
  return tid;
}

P1906EMMessageCarrier::P1906EMMessageCarrier ()
{
  NS_LOG_FUNCTION (this);
  SetMessage (0);
}

P1906EMMessageCarrier::~P1906EMMessageCarrier ()
{
  NS_LOG_FUNCTION (this);
  SetMessage (0);
}


void
P1906EMMessageCarrier::SetSpectrumValue (Ptr<SpectrumValue> s)
{
  NS_LOG_FUNCTION (this << s);
  m_spectrumValue = s;
}

Ptr<SpectrumValue>
P1906EMMessageCarrier::GetSpectrumValue (void)
{
  NS_LOG_FUNCTION (this);
  return m_spectrumValue;
}

void
P1906EMMessageCarrier::SetDuration (Time t)
{
  NS_LOG_FUNCTION (this << t);
  m_duration = t;
}

Time
P1906EMMessageCarrier::GetDuration (void)
{
  NS_LOG_FUNCTION (this);
  return m_duration;
}

void
P1906EMMessageCarrier::SetPulseDuration (Time t)
{
  NS_LOG_FUNCTION (this << t);
  m_pulseDuration = t;
}

Time
P1906EMMessageCarrier::GetPulseDuration (void)
{
  NS_LOG_FUNCTION (this);
  return m_pulseDuration;
}

void
P1906EMMessageCarrier::SetPulseInterval (Time t)
{
  NS_LOG_FUNCTION (this << t);
  m_pulseInterval = t;
}

Time
P1906EMMessageCarrier::GetPulseInterval (void)
{
  NS_LOG_FUNCTION (this);
  return m_pulseInterval;
}

void
P1906EMMessageCarrier::SetStartTime (Time t)
{
  NS_LOG_FUNCTION (this << t);
  m_startTime = t;
}

Time
P1906EMMessageCarrier::GetStartTime (void)
{
  NS_LOG_FUNCTION (this);
  return m_startTime;
}

void
P1906EMMessageCarrier::SetCentralFrequency (double f)
{
  NS_LOG_FUNCTION (this << f);
  m_centralFrequency = f;
}

double
P1906EMMessageCarrier::GetCentralFrequency (void)
{
  NS_LOG_FUNCTION (this);
  return m_centralFrequency;
}

void
P1906EMMessageCarrier::SetBandwidth (double b)
{
  NS_LOG_FUNCTION (this << b);
  m_bandwidth = b;
}

double
P1906EMMessageCarrier::GetBandwidth (void)
{
  NS_LOG_FUNCTION (this);
  return m_bandwidth;
}

void
P1906EMMessageCarrier::SetSubChannel (double c)
{
  NS_LOG_FUNCTION (this << c);
  m_subChannel = c;
}

double
P1906EMMessageCarrier::GetSubChannel (void)
{
  NS_LOG_FUNCTION (this);
  return m_subChannel;
}

} // namespace ns3
