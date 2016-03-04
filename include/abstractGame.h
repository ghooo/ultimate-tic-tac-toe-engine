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

#ifndef ABSTRACTGAME_H
#define ABSTRACTGAME_H

class AbstractGame {
	int maxRounds_;
	const bool DEV_MODE = false;
	const std::string TEST_BOT = "devbot/bot";
	const int NUM_TEST_BOTS = 2;
	std::vector<IOPlayer*> ioPlayers_;
protected:
	int roundNumber_;
	std::string playedGame_;
public:
	AbstractGame() {
		playedGame_ = "";
		roundNumber_ = 1;
		maxRounds_ = -1;
	}
	std::string getPlayedGame() {
		return playedGame_;
	}
	int getRoundNumber() {
		return roundNumber_;
	}
	virtual void addPlayer(std::string command) = 0;
	virtual bool playRound() = 0;
	virtual void sendSettings() = 0;
	virtual void saveGame() = 0;
	virtual AbstractPlayer* getWinner() = 0;
};

#endif //ABSTRACTGAME_H