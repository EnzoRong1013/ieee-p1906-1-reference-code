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

#ifndef P1906_MEDIUM_H
#define P1906_MEDIUM_H

#include "ns3/net-device.h"
#include "ns3/channel.h"
#include "ns3/packet.h"


namespace ns3 {
class P1906CommunicationInterface;
class P1906MessageCarrier;
class P1906Field;
class P1906Force;


/**
 * \ingroup P1906 framework
 *
 * \class P1906Medium
 *
 * \brief This class implements the medium of the P1906 framework.
 */
class P1906Medium : public Channel
{
public:

  P1906Medium ();
  virtual ~P1906Medium ();

  static TypeId GetTypeId ();

  // Methods inherrited from base class
  virtual uint32_t GetNDevices (void) const;
  virtual Ptr<NetDevice> GetDevice (uint32_t i) const;

  /**
   * \param xxx add parameters
   * The metod is is charge of delivering the message to the destination node
   */
  void HandleTransmission  (Ptr<P1906CommunicationInterface> src,
		                    Ptr<P1906MessageCarrier> message,
		                    Ptr<P1906Field> field);

  /**
   * \param xxx add parameters
   * The metod is is charge of delivering the message to the destination node
   */
  void HandleReception  (Ptr<P1906CommunicationInterface> dst, Ptr<P1906MessageCarrier> message);

  /**
   * \param xxx add parameters
   *
   * Adds the communication interface to the list of potential receivers
   */
  void AddP1906CommunicationInterface (Ptr<P1906CommunicationInterface> i);

  void SetP1906Force (Ptr<P1906Force> f);
  Ptr<P1906Force> GetP1906Force ();

  typedef std::vector< Ptr<P1906CommunicationInterface> > P1906CommunicationInterfaces;

private:
  P1906CommunicationInterfaces* m_communicationInterfaces;
  Ptr<P1906Force> m_force;

protected:
  virtual void DoDispose ();
};

}

#endif /* P1906_MEDIUM_H */
