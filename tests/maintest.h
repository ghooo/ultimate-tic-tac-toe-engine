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
#include <cxxtest/TestSuite.h>
#include "engine.h"
#include <vector>
#include <string>

struct batee5 {
	IOPlayer ioplayer1, ioplayer2, ioplayer3;
	batee5(std::string cmd):ioplayer1(cmd), ioplayer2(cmd), ioplayer3(cmd) {}
};
class MyTestSuite : public CxxTest::TestSuite
{
	Engine *engine;
	Simulator *simulator;
	std::string devbot;
	std::string mybot;
public:
	void setUp() {
		devbot = "devbot/bot";
		mybot = "/Users/ghooo/Projects/ultimate-tic-tac-toe/bin/runner";
	}
	void tearDown() {
	}
	void testMain() {
		std::vector<std::string> commands;
		commands.push_back(mybot);
		commands.push_back(mybot);
		engine = new Engine(commands);
		engine->setUpEngine();
		engine->runEngine();
	}
	void testSimulator() {
		// simulator = new Simulator();
		// simulator->addPlayer(devbot);
		// simulator->addPlayer(devbot);
		// simulator->sendSettings();
	}

	void testIOPlayer1() {
		// batee5 b(devbot);
		// static IOPlayer ioplayer1 ("devbot/bot 1 1");
		// IOPlayer ioplayer2("devbot/bot 2 2");
		// IOPlayer ioplayer3("devbot/bot 3 3");
		// ioplayer1.writeToBot("action move");
		// ioplayer2.writeToBot("action move");
		// ioplayer3.writeToBot("action move");
		// ioplayer1.writeToBot("action move");
		// ioplayer2.writeToBot("action move");
		// ioplayer3.writeToBot("action move");
		// ioplayer1.writeToBot("action move");
		// ioplayer2.writeToBot("action move");
		// ioplayer3.writeToBot("action move");
		// ioplayer1.writeToBot("action move");
		// ioplayer2.writeToBot("action move");
		// ioplayer3.writeToBot("action move");


		// std::cout << ioplayer1.getResponse(1000) << std::endl;
		// std::cout << ioplayer1.getResponse(1000) << std::endl;
		// std::cout << ioplayer1.getResponse(1000) << std::endl;
		// std::cout << ioplayer2.getResponse(1000) << std::endl;
		// std::cout << ioplayer2.getResponse(1000) << std::endl;
		// std::cout << ioplayer2.getResponse(1000) << std::endl;
		// std::cout << ioplayer3.getResponse(1000) << std::endl;
		// std::cout << ioplayer3.getResponse(1000) << std::endl;
		// std::cout << ioplayer3.getResponse(1000) << std::endl;
		// std::cout << ioplayer3.getResponse(1000) << std::endl;
	}
	void testIOPlayer2() {
		//delete b1;
		//delete b2;
		// INFO("--------------");
		// IOPlayer *ioplayer1 = new IOPlayer("devbot/bot 1 1");
		// IOPlayer *ioplayer2 = new IOPlayer("devbot/bot 2 2");
		// IOPlayer *ioplayer3 = new IOPlayer("devbot/bot 3 3");

		// ioplayer1->writeToBot("action move");
		// ioplayer2->writeToBot("action move");
		// ioplayer3->writeToBot("action move");
		// ioplayer1->writeToBot("action move");
		// ioplayer2->writeToBot("action move");
		// ioplayer3->writeToBot("action move");
		// ioplayer1->writeToBot("action move");
		// ioplayer2->writeToBot("action move");
		// ioplayer3->writeToBot("action move");
		// ioplayer1->writeToBot("action move");
		// ioplayer2->writeToBot("action move");
		// ioplayer3->writeToBot("action move");


		// std::cout << ioplayer1->getResponse(1000) << std::endl;
		// std::cout << ioplayer1->getResponse(1000) << std::endl;
		// std::cout << ioplayer1->getResponse(1000) << std::endl;
		// std::cout << ioplayer2->getResponse(1000) << std::endl;
		// std::cout << ioplayer2->getResponse(1000) << std::endl;
		// std::cout << ioplayer2->getResponse(1000) << std::endl;
		// std::cout << ioplayer3->getResponse(1000) << std::endl;
		// std::cout << ioplayer3->getResponse(1000) << std::endl;
		// std::cout << ioplayer3->getResponse(1000) << std::endl;
		// std::cout << ioplayer3->getResponse(1000) << std::endl;

		// delete ioplayer3;
		// delete ioplayer2;
		// delete ioplayer1;
		// ioplayer1->~IOPlayer();
		//  INFO("DELETE ALL IOPLAYERS");
		// delete ioplayer1;
		//  INFO("player 1 deleted");
		// delete ioplayer2;
		//  INFO("player 2 deleted");
		// delete ioplayer3;
		//  INFO("player3 deleted");
		// delete ioplayer2;
	}
	void testPstreams() {
		// redi::pstream *p1 = new redi::pstream("devbot/bot 1 1");
		// redi::pstream *p2 = new redi::pstream("devbot/bot 2 2");
		// redi::pstream *p3 = new redi::pstream("devbot/bot 3 3");
		// delete p3;
		// delete p2;
		// delete p1;
	}
};