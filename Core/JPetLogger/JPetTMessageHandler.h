/**
 *  @copyright Copyright 2019 The J-PET Framework Authors. All rights reserved.
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
 *  @file JPetMessageHandle.h
 */

#ifndef JPETTMESSAGEHANDLER_H
#define JPETTMESSAGEHANDLER_H
#include "TMessageHandler.h"

class JPetTMessageHandler : public TMessageHandler {
public:
  JPetTMessageHandler();
  ~JPetTMessageHandler();
  Bool_t Notify() override;
};

#endif /* !JPETTMESSAGEHANDLER_H */
