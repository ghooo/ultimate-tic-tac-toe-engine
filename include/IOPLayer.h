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
#include <thread>
#include <mutex>
#include <queue>
#include <ctime>
#include "helpers.h"
#include "pstream.h"

#ifndef IOPLAYER_H
#define IOPLAYER_H
class IOPlayer {
public:
	IOPlayer(std::string);
	void writeToBot(std::string line);
	std::string getResponse(long timeOut);
	void finish();
	~IOPlayer();
private:
	std::queue<std::string> lines;
	const int MAX_ERRORS = 2;
	const std::string NULL_MOVE = "no_moves";
	redi::pstream *prog_;
	std::thread thread_;
	std::mutex mu_;

	void readInput();
	void lockQueue();
	void unlockQueue();
protected:
};
#endif //IOPLAYER_H