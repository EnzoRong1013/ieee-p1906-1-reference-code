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

#ifndef P1906_NET_DEVICE_H
#define P1906_NET_DEVICE_H

#include <string.h>
#include <ns3/node.h>
#include <ns3/address.h>
#include <ns3/net-device.h>
#include <ns3/callback.h>
#include <ns3/packet.h>
#include <ns3/traced-callback.h>
#include <ns3/ptr.h>
#include <list>

namespace ns3 {

class P1906CommunicationInterface;

/**
 * \ingroup P1906 framework
 *
 * \class P1906NetDevice
 *
 * \brief This class implements the network device that will handle all
 * the functionalities conceived within the P1906 framework. Basically, it is
 * conceived as a container of the communication interface, i.e., the object
 * storing the transmission entity and the reception entity. It enable the
 * interaction between low-layer components of the P1906 framework and
 * upper layers of the protocol stack.
 */
class P1906NetDevice : public NetDevice
{
public:
  static TypeId GetTypeId (void);

  /**
   * Constructor
   */
  P1906NetDevice ();
  /**
   * Destructor
   */
  virtual ~P1906NetDevice ();


  virtual void DoDispose (void);

private:
  Ptr<Node> m_node;
  uint32_t m_ifIndex;

  /**
   * The P1906 communication interface
   */
  Ptr<P1906CommunicationInterface> m_p1906CommunicationInterface;



public:
  // inherited from NetDevice
  virtual void SetIfIndex (const uint32_t index);
  virtual uint32_t GetIfIndex (void) const;
  virtual Ptr<Channel> GetChannel (void) const;
  virtual bool SetMtu (const uint16_t mtu);
  virtual uint16_t GetMtu (void) const;
  virtual void SetAddress (Address address);
  virtual Address GetAddress (void) const;
  virtual bool IsLinkUp (void) const;
  virtual void AddLinkChangeCallback (Callback<void> callback);
  virtual bool IsBroadcast (void) const;
  virtual Address GetBroadcast (void) const;
  virtual bool IsMulticast (void) const;
  virtual bool IsPointToPoint (void) const;
  virtual bool IsBridge (void) const;
  virtual bool Send (Ptr<Packet> packet, const Address& dest,
                     uint16_t protocolNumber);
  virtual bool SendFrom (Ptr<Packet> packet, const Address& source, const Address& dest,
                         uint16_t protocolNumber);
  virtual Ptr<Node> GetNode (void) const;
  virtual void SetNode (Ptr<Node> node);
  virtual bool NeedsArp (void) const;
  virtual void SetReceiveCallback (NetDevice::ReceiveCallback cb);
  virtual Address GetMulticast (Ipv4Address addr) const;
  virtual Address GetMulticast (Ipv6Address addr) const;
  virtual void SetPromiscReceiveCallback (PromiscReceiveCallback cb);
  virtual bool SupportsSendFrom (void) const;


  /**
   * Set the P1906 communication interface
   *
   * \param i the pointer to the P1906CommunicationInterface element
   */
  void SetP1906CommunicationInterface (Ptr<P1906CommunicationInterface> i);
  /**
   * \return the P1906 communication interface
   */
  Ptr<P1906CommunicationInterface> GetP1906CommunicationInterface (void);
};


} // namespace ns3

#endif /* P1906_NET_DEVICE_H */
