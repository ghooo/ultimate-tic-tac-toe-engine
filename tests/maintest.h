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

class MyTestSuite : public CxxTest::TestSuite
{
	Engine *engine;
	Simulator *simulator;
	std::string devbot;
public:
	void setUp() {
		devbot = "devbot/bot";
		std::vector<std::string> commands;
		commands.push_back(devbot);
		commands.push_back(devbot);
	}
	void tearDown() {
		delete engine;
		delete simulator;
	}
	void testMain() {
		// engine = new Engine(commands);
		// engine->setUpEngine();
		// engine->runEngine();
	}
	void testSimulator() {
		// simulator = new Simulator();
		// simulator->addPlayer(devbot);
		// simulator->addPlayer(devbot);
		// simulator->sendSettings();
	}

	void testIOPlayer1() {
		IOPlayer ioplayer1("devbot/bot 1 1");
		IOPlayer ioplayer2("devbot/bot 2 2");
		IOPlayer ioplayer3("devbot/bot 3 3");
		ioplayer1.writeToBot("action move");
		ioplayer2.writeToBot("action move");
		ioplayer3.writeToBot("action move");
		ioplayer1.writeToBot("action move");
		ioplayer2.writeToBot("action move");
		ioplayer3.writeToBot("action move");
		ioplayer1.writeToBot("action move");
		ioplayer2.writeToBot("action move");
		ioplayer3.writeToBot("action move");
		ioplayer1.writeToBot("action move");
		ioplayer2.writeToBot("action move");
		ioplayer3.writeToBot("action move");


		std::cout << ioplayer1.getResponse(1000) << std::endl;
		std::cout << ioplayer1.getResponse(1000) << std::endl;
		std::cout << ioplayer1.getResponse(1000) << std::endl;
		std::cout << ioplayer2.getResponse(1000) << std::endl;
		std::cout << ioplayer2.getResponse(1000) << std::endl;
		std::cout << ioplayer2.getResponse(1000) << std::endl;
		std::cout << ioplayer3.getResponse(1000) << std::endl;
		std::cout << ioplayer3.getResponse(1000) << std::endl;
		std::cout << ioplayer3.getResponse(1000) << std::endl;
		std::cout << ioplayer3.getResponse(1000) << std::endl;
	}
	void testIOPlayer2() {
		INFO("--------------");
		IOPlayer *ioplayer1 = new IOPlayer("devbot/bot 1 1");
		IOPlayer *ioplayer2 = new IOPlayer("devbot/bot 2 2");
		IOPlayer *ioplayer3 = new IOPlayer("devbot/bot 3 3");

		ioplayer1->writeToBot("action move");
		ioplayer2->writeToBot("action move");
		ioplayer3->writeToBot("action move");
		ioplayer1->writeToBot("action move");
		ioplayer2->writeToBot("action move");
		ioplayer3->writeToBot("action move");
		ioplayer1->writeToBot("action move");
		ioplayer2->writeToBot("action move");
		ioplayer3->writeToBot("action move");
		ioplayer1->writeToBot("action move");
		ioplayer2->writeToBot("action move");
		ioplayer3->writeToBot("action move");


		std::cout << ioplayer1->getResponse(1000) << std::endl;
		std::cout << ioplayer1->getResponse(1000) << std::endl;
		std::cout << ioplayer1->getResponse(1000) << std::endl;
		std::cout << ioplayer2->getResponse(1000) << std::endl;
		std::cout << ioplayer2->getResponse(1000) << std::endl;
		std::cout << ioplayer2->getResponse(1000) << std::endl;
		std::cout << ioplayer3->getResponse(1000) << std::endl;
		std::cout << ioplayer3->getResponse(1000) << std::endl;
		std::cout << ioplayer3->getResponse(1000) << std::endl;
		std::cout << ioplayer3->getResponse(1000) << std::endl;


		 INFO("DELETE ALL IOPLAYERS");
		delete ioplayer1;
		 INFO("player 1 deleted");
		delete ioplayer2;
		 INFO("player 2 deleted");
		delete ioplayer3;
		 INFO("player3 deleted");
		// delete ioplayer2;
	}
	void testPstreams() {

		redi::pstream *p1 = new redi::pstream(devbot);
		redi::pstream *p2 = new redi::pstream(devbot);
		redi::pstream *p3 = new redi::pstream(devbot);
		(*p1) << "HI";
		(*p1) << "HI";
		(*p1) << "HI";
		(*p2) << "HI";
		(*p2) << "HI";
		(*p2) << "HI";
		(*p3) << "HI";
		(*p3) << "HI";
		(*p3) << "HI";
	}
	void testAddition( void )
	{
		TS_ASSERT( 1 + 1 > 1 );
		TS_ASSERT_EQUALS( 1 + 1, 2 );
	}
	void testAddition1( void )
	{
		TS_ASSERT( 1 + 1 > 1 );
		TS_ASSERT_EQUALS( 1 + 1, 2 );
	}
	void testAddition2( void )
	{
		TS_ASSERT( 1 + 1 > 1 );
		TS_ASSERT_EQUALS( 1 + 1, 2 );
	}
};