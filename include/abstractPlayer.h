// Copyright 2016 ghooo (https://github.com/ghooo)

//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at

//        http://www.apache.org/licenses/LICENSE-2.0

//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//  
//    For the full copyright and license information, please view the LICENSE
//    file that was distributed with this source code.

#include <string>
#include "IOPlayer.h"
#include "helpers.h"

#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H

class AbstractPlayer {
	std::string name_;
	IOPlayer *bot_;
	timell timeBank_;
	timell maxTimeBank_;
	timell timePerMove_;
public:
	AbstractPlayer(std::string name, IOPlayer *bot, timell maxTimeBank, timell timePerMove);
	std::string getName();
	timell getTimeBank();
	IOPlayer* getBot();
	void setTimBank(timell timeBank);
	void updateTimeBank(timell timeElapsed);
	void sendSetting(std::string type, std::string value);
	void sendSetting(std::string type, int value);
	void sendUpdate(std::string type, AbstractPlayer* player, std::string value);
	void sendUpdate(std::string type, AbstractPlayer* player, int value);
	void sendUpdate(std::string type, std::string value);
	void sendUpdate(std::string type, int value);
	std::string requestMove(std::string moveType);
	void sendLine(std::string content);


};

#endif //ABSTRACTPLAYER_H