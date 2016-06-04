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
#include "cmdline.h"

int main(int argc, char *argv[]){
	cmdline::parser p;
	p.add<std::string>("bot1exe", '1', "first bot executable", true, "");
	p.add<std::string>("bot2exe", '2', "first bot executable", true, "");
	p.add("suppress", 's', "suppress bots error stream");
	p.add<int>("numgames", 'n', "number of games", false, 1);
	p.add("verbose", 'v', "show more details");
	p.add<int>("timebank", 't', "set timebank in milliseconds", false, 40000);
	p.add<int>("timepermove", 'm', "set timepermove in milliseconds", false, 2000);
	p.add("alternate", 'a', "alternate players, switch players every game");
	p.parse_check(argc, argv);

	std::vector<std::string> commands;
	commands.push_back(p.get<std::string>("bot1exe"));
	commands.push_back(p.get<std::string>("bot2exe"));

	__NUMBEROFGAMES__ = p.get<int>("numgames");
	__VERBOSE__ = p.exist("verbose");
	__TIMEBANK__ = p.get<int>("timebank");
	__TIMEPERMOVE__ = p.get<int>("timepermove");
	__ALTERNATE__ = p.exist("alternate");

	std::vector<std::string> newCommands = commands;
	if(p.exist("suppress")) {
		for(auto &command:newCommands) {
			command += " 2>/dev/null";
		}
	}

	if(!__VERBOSE__) PRINT("Add verbose option for more details.");


	if(__NUMBEROFGAMES__ == 1) {
		PRINT("Game: "+commands[0]+" vs "+commands[1]);
		Engine engine(newCommands);
		engine.setUpEngine();
		engine.runEngine();
		PRINT("Stopping...");
		PRINT(engine.getGameResult());
	} else {
		std::map<std::string, int> idxs;
		idxs[newCommands[0]]=0;
		idxs[newCommands[1]]=1;

		int scores[2] = {}, draws = 0;
		int trials = __NUMBEROFGAMES__;
		for(int i = 0; i < trials; i++) {
			PRINT("Game #"+std::to_string(i+1)+": "+commands[idxs[newCommands[0]]]+" vs "+commands[idxs[newCommands[1]]]);
			Engine engine(newCommands);
			engine.setUpEngine();
			engine.runEngine();

			std::string res = engine.getGameResult();
			if(res.back() == '1') scores[idxs[newCommands[0]]]++;
			else if(res.back() == '2') scores[idxs[newCommands[1]]]++;
			else draws++;

			PRINT(res+" ... "+(res.back()=='1'?commands[idxs[newCommands[0]]]:(res.back()=='2'?commands[idxs[newCommands[1]]]:"")));
			PRINT("");

			if(__ALTERNATE__) {
				swap(newCommands[0], newCommands[1]);
			}
		}
		PRINT("Games played "+std::to_string(trials)+" games.");
		PRINT(commands[0]+" won "+std::to_string(scores[0])+ " games.");
		PRINT(commands[1]+" won "+std::to_string(scores[1])+ " games.");
		PRINT("No. of draws "+std::to_string(draws)+ " games.");
	}
    return 0;
}