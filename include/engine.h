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
	int gameResult_;
public:
	Engine(std::vector<std::string> commands) {
		commands_ = commands;
		simulator_ = new Simulator();
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
		while(simulator_->playRound()) {
			//
		}
		PRINT("stopping...");
		AbstractPlayer *winner = simulator_->getWinner();
		if(winner) {
			PRINT("The winner is " + winner->getName());
		} else {
			PRINT("The game is a draw.");
		}
	}
};

#endif //ENGINE_H