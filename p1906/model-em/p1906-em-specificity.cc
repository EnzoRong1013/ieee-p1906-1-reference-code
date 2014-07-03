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

#include "p1906-em-specificity.h"
#include "../model-core/p1906-specificity.h"
#include "p1906-em-message-carrier.h"
#include "../model-core/p1906-net-device.h"
#include "../model-core/p1906-perturbation.h"
#include "../model-core/p1906-receiver-communication-interface.h"
#include "../model-core/p1906-transmitter-communication-interface.h"
#include "p1906-em-perturbation.h"
#include "ns3/mobility-model.h"


namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906EMSpecificity");

TypeId P1906EMSpecificity::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906EMSpecificity")
    .SetParent<P1906Specificity> ();
  return tid;
}

P1906EMSpecificity::P1906EMSpecificity ()
{
  NS_LOG_FUNCTION (this << "EM Specificity Component");
}

P1906EMSpecificity::~P1906EMSpecificity ()
{
  NS_LOG_FUNCTION (this);
}

bool
P1906EMSpecificity::CheckRxCompatibility (Ptr<P1906CommunicationInterface> src, Ptr<P1906CommunicationInterface> dst, Ptr<P1906MessageCarrier> message)
{
  NS_LOG_FUNCTION (this);
  Ptr<P1906EMMessageCarrier> m = message->GetObject <P1906EMMessageCarrier>();

  double distances[20] = {
  0.0001, 0.0002, 0.0003, 0.0004, 0.0005, 0.0006, 0.0007, 0.0008, 0.0009, 0.001, 0.0011, 0.0012, 0.0013, 0.0014, 0.0015, 0.0016, 0.0017, 0.0018, 0.0019, 0.002
   };


  double molecularnoise[20][11] = {
   {
  131.214, 156.134, 156.134, 163.643, 163.643, 170.786, 190.19, 196.037, 206.889, 221.261, 206.889
   },
  {
  206.889, 233.63, 233.63, 240.902, 240.902, 247.482, 263.695, 268.105, 275.704, 284.598, 275.704
   },
  {
  250.533, 272.094, 272.094, 277.378, 277.378, 281.925, 292.104, 294.598, 298.593, 302.729, 298.593
   },
  {
  275.704, 291.186, 291.186, 294.598, 294.598, 297.392, 303.083, 304.338, 306.206, 307.919, 306.206
   },
  {
  290.221, 300.662, 300.662, 302.729, 302.729, 304.338, 307.327, 307.919, 308.738, 309.404, 308.738
   },
  {
  298.593, 305.365, 305.365, 306.567, 306.567, 307.457, 308.967, 309.235, 309.58, 309.829, 309.58
   },
  {
  303.421, 307.699, 307.699, 308.379, 308.379, 308.858, 309.601, 309.719, 309.86, 309.951, 309.86
   },
  {
  306.206, 308.858, 308.858, 309.235, 309.235, 309.487, 309.846, 309.897, 309.954, 309.986, 309.954
   },
  {
  307.812, 309.433, 309.433, 309.639, 309.639, 309.77, 309.94, 309.962, 309.985, 309.996, 309.985
   },
  {
  308.738, 309.719, 309.719, 309.829, 309.829, 309.897, 309.977, 309.986, 309.995, 309.999, 309.995
   },
  {
  309.272, 309.86, 309.86, 309.919, 309.919, 309.954, 309.991, 309.995, 309.998, 310, 309.998
   },
  {
  309.58, 309.931, 309.931, 309.962, 309.962, 309.979, 309.997, 309.998, 309.999, 310, 309.999
   },
  {
  309.758, 309.966, 309.966, 309.982, 309.982, 309.991, 309.999, 309.999, 310, 310, 310
   },
  {
  309.86, 309.983, 309.983, 309.992, 309.992, 309.996, 309.999, 310, 310, 310, 310
   },
  {
  309.919, 309.992, 309.992, 309.996, 309.996, 309.998, 310, 310, 310, 310, 310
   },
  {
  309.954, 309.996, 309.996, 309.998, 309.998, 309.999, 310, 310, 310, 310, 310
   },
  {
  309.973, 309.998, 309.998, 309.999, 309.999, 310, 310, 310, 310, 310, 310
   },
  {
  309.985, 309.999, 309.999, 310, 310, 310, 310, 310, 310, 310, 310
   },
  {
  309.991, 309.999, 309.999, 310, 310, 310, 310, 310, 310, 310, 310
   },
  {
  309.995, 310, 310, 310, 310, 310, 310, 310, 310, 310, 310
   },

   };

  Ptr<P1906EMPerturbation> perturbation = GetP1906CommunicationInterface ()->
		  GetP1906TransmitterCommunicationInterface ()->GetP1906Perturbation ()->
		  GetObject<P1906EMPerturbation> ();

  if (perturbation->GetBandwidth() == m->GetBandwidth() &&
      perturbation->GetSubChannel() == m->GetSubChannel() &&
      perturbation->GetCentralFrequency() == m->GetCentralFrequency ())
    {
	  NS_LOG_FUNCTION (this << "compatibility OK --> verify the respect of the Shannon bound");

	  double transmissionRate = 1. / m->GetPulseInterval ().GetSeconds ();

	  Ptr<MobilityModel> srcMobility = src->GetP1906NetDevice ()->GetNode ()->GetObject<MobilityModel> ();
	  Ptr<MobilityModel> dstMobility = dst->GetP1906NetDevice ()->GetNode ()->GetObject<MobilityModel> ();
	  double distance = dstMobility->GetDistanceFrom (srcMobility);


	  double channelCapacity = 0;

	  int index_d;
	  if (distance <= distances [0]) index_d = 0;
	  else if (distance >= distances [19]) index_d = 19;
	  else
	    for (int i = 0; i < 20; i++)
		  {
		    if (distance <= distances [i]) index_d = i;
		  }

	  Ptr<P1906EMMessageCarrier> m = message->GetObject <P1906EMMessageCarrier> ();
	  Ptr<SpectrumValue> sv = m->GetSpectrumValue ();
	  for (int i=0; i<11; i++)
	    {
		  double sinr_i = 10.*log10((*sv)[i]) - molecularnoise[index_d][i];
		  channelCapacity += m->GetSubChannel() * log(pow(10., sinr_i))/log(2);
	    }



	  if (channelCapacity >= transmissionRate)
	    {
		  NS_LOG_FUNCTION (this << "Shannon bound has been respected");
		  return true;
	    }
	  else
	    {
		  NS_LOG_FUNCTION (this << "Shannon bound has NOT been respected --> transmission faild");
		  return false;
	    }
    }
  else
    {
	  NS_LOG_FUNCTION (this << "check compatibility failed");
	  return false;
    }
}

} // namespace ns3
