/**
 *  @copyright Copyright 2021 The J-PET Framework Authors. All rights reserved.
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may find a copy of the License in the LICENCE file.
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  @file JPetMCDecayTree.h
 */

#ifndef _JPETMCDECAYTREE_H_
#define _JPETMCDECAYTREE_H_

#include "JPetGeantDecayTreeBranch/JPetGeantDecayTreeBranch.h"
#include "JPetGeantDecayTree/JPetGeantDecayTree.h"
#include <TClonesArray.h>
#include <map>

/**
 * @class JPetMCDecayTree
 * @brief Class stores decay tree structures (in form of nodes and tracks)
 */

class JPetMCDecayTree : public JPetGeantDecayTree {
public:
  JPetMCDecayTree();
  ~JPetMCDecayTree();
  JPetMCDecayTree(JPetGeantDecayTree* geantDecayTree);

private:
  int fEventID = 0;
  DecayChannel fDecayChannel = DecayChannel::kUnknown;
  std::map<int, int> fTrackBranchConnection = {};
  TClonesArray fDecayTreeBranches;
  unsigned int fDecayTreeBranchesIndex = 0;
    
  ClassDef(JPetMCDecayTree, 2);
};

#endif
