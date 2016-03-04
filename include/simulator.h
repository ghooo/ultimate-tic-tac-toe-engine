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

#include "IOPlayer.h"
#include "player.h"
#include "abstractGame.h"
#include "field.h"
#include "helpers.h"
#include <vector>
#include <string>

#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator: public AbstractGame {
	std::vector<IOPlayer*> ioplayers_;
	std::vector<Player*> players_;
	const int MAXTIMEBANK = 10000;
	const int TIMEPERMOVE = 1000;
	int moveNumber_;
	Field *field_;
	int failedPlayerId_;
	bool checkAndPlay(std::string response, Player *player);
public:
	Simulator();
	~Simulator();
	void addPlayer(std::string command);
	void sendSettings();
	bool playRound();
	int getFailedPlayerId();
	AbstractPlayer* getWinner();
	void saveGame();
};
#endif //SIMULATOR_H