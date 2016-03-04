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

IOPlayer::IOPlayer(std::string cmd){
	prog_ = new redi::pstream(cmd);
	thread_ = std::thread(&IOPlayer::readInput,this);
}
IOPlayer::~IOPlayer() {
	(*prog_) << redi::peof; // kill prog_
	thread_.join();
	delete prog_;
}
void IOPlayer::writeToBot(std::string line){
	(*prog_) << line << std::endl;
}
std::string IOPlayer::getResponse(long timeOut){
	clock_t start = clock();

	// timeOut is milliseconds
	clock_t clockTimeOut = CLOCKS_PER_SEC * timeOut/1000.0;


	while(true) {
		clock_t timeElapsed = clock()-start;
		if(timeElapsed > clockTimeOut) {
			return "";
		}
		lockQueue();
		if(lines.size()) {
			std::string ret;
			ret = lines.front();
			lines.pop();
			unlockQueue();
			return ret;
		}
		unlockQueue();
	}
}
void IOPlayer::lockQueue() {
	mu_.lock();
}
void IOPlayer::unlockQueue() {
	mu_.unlock();
}
void IOPlayer::readInput() {
	std::string line;
	while(std::getline(*prog_, line)) {
		lockQueue();
		lines.push(line);
		unlockQueue();
	};
}