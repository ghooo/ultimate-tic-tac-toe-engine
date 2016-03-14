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

#include <iostream>

#include <string>
#include <vector>

#include "engine.h"

void reportErrorAndExit(std::string error) {
	ERROR(error);
	PRINTSTDERR("Usage: <exe> '<bot1 exe>' '<bot2 exe> [num-of-games] [--debug] [--fixedseed]");
	exit(1);
}
void checkArgument(std::string s) {
	if(s == "--debug") __DEBUG_GAME_INFO__ = true;
	else if(s == "--fixedseed") __FIXEDSEED__ = true;
	else if(isdigit(s[0])) __NUMBEROFGAMES__ = stoi(s);
	else {
		reportErrorAndExit("no paramter named " + s);
	}
}
int main(int argc, char **argv){
	if(argc < 3) {
		reportErrorAndExit("insufficient number of parameters");
	}
	std::vector<std::string> commands;
	commands.push_back(std::string(argv[1]));
	commands.push_back(std::string(argv[2]));
	
	for(int i = 3; i < argc; i++) {
		checkArgument(std::string(argv[i]));
	}

	if(!__NUMBEROFGAMES__) {
		Engine engine(commands);
		engine.setUpEngine();
		engine.runEngine();
		PRINT("Stopping...");
		PRINT(engine.getGameResult());
	} else {
		int trials = __NUMBEROFGAMES__;
		int wins1 = 0, wins2 = 0, draws = 0;
		for(int i = 0; i < trials; i++) {
			if(trials >= 10 && (i+1)%(trials/10) == 0) {
				PRINT(std::to_string(i+1)+"/"+std::to_string(trials));
			}
			std::vector<std::string> newCommands = commands;
			if(__FIXEDSEED__) {
				newCommands[0] += " " + std::to_string(rand());
				newCommands[1] += " " + std::to_string(rand());
			}
			Engine engine(newCommands);
			engine.setUpEngine();
			engine.runEngine();
			std::string res = engine.getGameResult();
			if(res.back() == '1') wins1++;
			else if(res.back() == '2') wins2++;
			else draws++;
		}
		PRINT("Games played "+std::to_string(trials)+" games.");
		PRINT("Player1 wins "+std::to_string(wins1)+ " games.");
		PRINT("Player2 wins "+std::to_string(wins2)+ " games.");
		PRINT("No. of draws "+std::to_string(draws)+ " games.");
	}
    return 0;
}