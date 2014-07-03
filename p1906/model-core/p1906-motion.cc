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

#include "p1906-motion.h"
#include "p1906-communication-interface.h"
#include "p1906-message-carrier.h"
#include "p1906-field.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906Motion");

TypeId P1906Motion::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906Motion")
    .SetParent<Object> ();
  return tid;
}

P1906Motion::P1906Motion ()
{
  NS_LOG_FUNCTION (this);
}

P1906Motion::~P1906Motion ()
{
  NS_LOG_FUNCTION (this);
}


double
P1906Motion::ComputePropagationDelay (Ptr<P1906CommunicationInterface> src,
		                             Ptr<P1906CommunicationInterface> dst,
		                             Ptr<P1906MessageCarrier> message,
		                             Ptr<P1906Field> field)
{
  NS_LOG_FUNCTION (this << "Return the defaul value: 0s");
  return 0.;
}


Ptr<P1906MessageCarrier>
P1906Motion::CalculateReceivedMessageCarrier(Ptr<P1906CommunicationInterface> src,
		                                    Ptr<P1906CommunicationInterface> dst,
		                                    Ptr<P1906MessageCarrier> message,
		                                    Ptr<P1906Field> field)
{
  NS_LOG_FUNCTION (this << "apply default behavior: do nothing");
  return message;
}


} // namespace ns3
