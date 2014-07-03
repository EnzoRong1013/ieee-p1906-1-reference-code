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

#ifndef P1906_HELPER_H
#define P1906_HELPER_H

#include <string>
#include "ns3/object-factory.h"
#include "ns3/node-container.h"
#include <ns3/mobility-model.h>
#include "ns3/net-device-container.h"


namespace ns3 {

class P1906NetDevice;
class P1906Field;
class P1906Perturbation;
class P1906Specificity;
class P1906Medium;
class P1906CommunicationInterface;
class P1906Motion;

/**
 * \ingroup P1906 framework
 * \brief helps to manage and create nanomachines objects
 */
class P1906Helper
{
public:

  /**
   * \brief Create a the helper object for the P1906 framework
   */
   P1906Helper (void);
  ~P1906Helper (void);


  /**
   * Helper to enable all log components related to the P1906 framework
   */
  void EnableLogComponents (void);

  /**
   * Helper to connect components, attributes, and devices
   */
  void Connect (Ptr<Node>, Ptr<P1906NetDevice>, Ptr<P1906Medium> m, Ptr<P1906CommunicationInterface> c, Ptr<P1906Field>, Ptr<P1906Perturbation>, Ptr<P1906Specificity>);
};

} // namespace ns3

#endif /* P1906_HELPER_H */
