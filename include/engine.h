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
#include <vector>
#include "simulator.h"
#include "abstractPlayer.h"

#ifndef ENGINE_H
#define ENGINE_H

class Engine {
	std::vector<std::string> commands_;
	Simulator* simulator_;
	std::string gameResult_;
public:
	Engine(std::vector<std::string> commands) {
		commands_ = commands;
		simulator_ = new Simulator();
		gameResult_ = "";
	}
	~Engine() {
		delete simulator_;
	}
	void setUpEngine() {
		for(auto command:commands_) {
			simulator_->addPlayer(command);
		}
		simulator_->sendSettings();
	}
	void runEngine() {
		do {
			if(!__VERBOSE__) std::cerr << "\rROUND # " << simulator_->getRoundNumber() << std::flush;
		}while(simulator_->playRound());

		if(!__VERBOSE__) PRINTSTDERR("");

		AbstractPlayer *winner = simulator_->getWinner();
		if(winner) {
			gameResult_ = "The winner is " + winner->getName();
		} else {
			gameResult_ = "The game is a draw.";
		}
	}
	std::string getGameResult() {
		return gameResult_;
	}
};

#endif //ENGINE_H