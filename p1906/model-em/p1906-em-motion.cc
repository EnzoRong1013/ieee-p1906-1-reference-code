/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 *  Copyright © 2014 by IEEE.
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

#include "ns3/log.h"

#include "p1906-em-motion.h"
#include "ns3/p1906-communication-interface.h"
#include "ns3/p1906-message-carrier.h"
#include "ns3/p1906-field.h"
#include "ns3/mobility-model.h"
#include "ns3/p1906-net-device.h"
#include <ns3/spectrum-value.h>
#include "p1906-em-message-carrier.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("P1906EMMotion");

TypeId P1906EMMotion::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::P1906EMMotion")
    .SetParent<P1906Motion> ();
  return tid;
}

P1906EMMotion::P1906EMMotion ()
{
  NS_LOG_FUNCTION (this);
}

P1906EMMotion::~P1906EMMotion ()
{
  NS_LOG_FUNCTION (this);
}


double
P1906EMMotion::ComputePropagationDelay (Ptr<P1906CommunicationInterface> src,
		                                Ptr<P1906CommunicationInterface> dst,
		                                Ptr<P1906MessageCarrier> message,
		                                Ptr<P1906Field> field)
{
  NS_LOG_FUNCTION (this);

  Ptr<MobilityModel> srcMobility = src->GetP1906NetDevice ()->GetNode ()->GetObject<MobilityModel> ();
  Ptr<MobilityModel> dstMobility = dst->GetP1906NetDevice ()->GetNode ()->GetObject<MobilityModel> ();

  double distance = dstMobility->GetDistanceFrom (srcMobility);
  double delay = distance/GetWaveSpeed ();

  NS_LOG_FUNCTION (this << "[d,speed,delay]" << distance << GetWaveSpeed() << delay);

  return delay;
}


Ptr<P1906MessageCarrier>
P1906EMMotion::CalculateReceivedMessageCarrier(Ptr<P1906CommunicationInterface> src,
		                                       Ptr<P1906CommunicationInterface> dst,
		                                       Ptr<P1906MessageCarrier> message,
		                                       Ptr<P1906Field> field)
{
  NS_LOG_FUNCTION (this << "Compute the path loss model through Akram's contribution");

  double distances[20] = {
  0.0001, 0.0002, 0.0003, 0.0004, 0.0005, 0.0006, 0.0007, 0.0008, 0.0009, 0.001, 0.0011, 0.0012, 0.0013, 0.0014, 0.0015, 0.0016, 0.0017, 0.0018, 0.0019, 0.002
   };

  double pathloss[20][11] = {
   {
  12.3394, 14.5749, 15.9138, 17.291, 18.314, 19.4465, 20.9262, 21.8993, 23.0291, 24.3247, 24.2721
   },
  {
  20.7503, 23.6377, 24.9766, 26.5711, 27.5941, 28.9439, 31.0755, 32.2659, 33.8303, 35.7778, 35.0733
   },
  {
  26.6624, 30.2017, 31.5406, 33.3524, 34.3754, 35.9425, 38.726, 40.1337, 42.1327, 44.7321, 43.3757
   },
  {
  31.5515, 35.7427, 37.0816, 39.1106, 40.1337, 41.918, 45.3535, 46.9785, 49.4121, 52.6634, 50.655
   },
  {
  35.8799, 40.7231, 42.062, 44.3083, 45.3314, 47.333, 51.4204, 53.2626, 56.1309, 60.0341, 57.3738
   },
  {
  39.8539, 45.3489, 46.6878, 49.1514, 50.1745, 52.3934, 57.1327, 59.1923, 62.4951, 67.0502, 63.738
   },
  {
  43.5831, 49.73, 51.0689, 53.7499, 54.7729, 57.2092, 62.6003, 64.8772, 68.6146, 73.8216, 69.8576
   },
  {
  47.1332, 53.932, 55.271, 58.1692, 59.1923, 61.8458, 67.8888, 70.383, 74.555, 80.4139, 75.798
   },
  {
  50.5466, 57.9973, 59.3362, 62.4517, 63.4748, 66.3456, 73.0406, 75.752, 80.3587, 86.8694, 81.6016
   },
  {
  53.852, 61.9546, 63.2935, 66.6264, 67.6494, 70.7376, 78.0844, 81.0132, 86.0544, 93.2171, 87.2974
   },
  {
  57.0702, 65.8247, 67.1636, 70.7137, 71.7368, 75.0422, 83.041, 86.187, 91.6628, 99.4774, 92.9058
   },
  {
  60.2162, 69.6226, 70.9616, 74.729, 75.752, 79.2748, 87.9254, 91.2888, 97.1992, 105.666, 98.4422
   },
  {
  63.3018, 73.3601, 74.699, 78.6837, 79.7068, 83.4468, 92.7493, 96.33, 102.675, 111.793, 103.918
   },
  {
  66.3357, 77.0459, 78.3849, 82.5869, 83.61, 87.5673, 97.5217, 101.32, 108.099, 117.87, 109.342
   },
  {
  69.3253, 80.6874, 82.0263, 86.4457, 87.4687, 91.6433, 102.25, 106.265, 113.479, 123.901, 114.722
   },
  {
  72.2762, 84.2902, 85.6291, 90.2657, 91.2888, 95.6807, 106.939, 111.171, 118.82, 129.894, 120.063
   },
  {
  75.193, 87.8589, 89.1979, 94.0518, 95.0748, 99.6841, 111.594, 116.044, 124.127, 135.853, 125.37
   },
  {
  78.0798, 91.3976, 92.7365, 97.8078, 98.8308, 103.657, 116.219, 120.887, 129.405, 141.782, 130.647
   },
  {
  80.9397, 94.9094, 96.2483, 101.537, 102.56, 107.604, 120.818, 125.702, 134.655, 147.685, 135.898
   },
  {
  83.7755, 98.3971, 99.7361, 105.242, 106.265, 111.526, 125.392, 130.494, 139.881, 153.563, 141.124
   },

   };


  Ptr<MobilityModel> srcMobility = src->GetP1906NetDevice ()->GetNode ()->GetObject<MobilityModel> ();
  Ptr<MobilityModel> dstMobility = dst->GetP1906NetDevice ()->GetNode ()->GetObject<MobilityModel> ();
  double distance = dstMobility->GetDistanceFrom (srcMobility);

  NS_LOG_FUNCTION (this << "[distance]" << distance);

  int index_d;
  if (distance <= distances [0])
	index_d = 0;
  else if (distance >= distances [19])
	  index_d = 19;
  else
    {
	  index_d = 0;
	  for (int i = 1; i < 20; i++)
	    {
		  if (distances [i] > distance)
		    {
			  index_d = i-1;
			  i=20;
		    }
	    }
    }

  //NS_LOG_FUNCTION (this << "[index,distance]" << index_d << distances [index_d]);

  Ptr<P1906EMMessageCarrier> m = message->GetObject <P1906EMMessageCarrier> ();
  Ptr<SpectrumValue> sv = m->GetSpectrumValue ();

  NS_LOG_FUNCTION (this << "[txPsd]" << *sv);
  for (int i=0; i<11; i++)
    {
      (*sv)[i] = pow(10., ((10*log10 ((*sv)[i])) - pathloss[index_d][i])/10.);
    }
  NS_LOG_FUNCTION (this << "[rxPsd]" << *sv);

  return message;
}



void
P1906EMMotion::SetWaveSpeed (double s)
{
  NS_LOG_FUNCTION (this << s);
  m_waveSpeed = s;
}

double
P1906EMMotion::GetWaveSpeed (void)
{
  NS_LOG_FUNCTION (this);
  return m_waveSpeed;
}


} // namespace ns3
