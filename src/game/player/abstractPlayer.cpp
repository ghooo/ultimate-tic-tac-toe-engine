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

#include "abstractPlayer.h"

AbstractPlayer::AbstractPlayer(std::string name, IOPlayer *bot, timell maxTimeBank, timell timePerMove) {
	name_ = name;
	bot_ = bot;
	maxTimeBank_ = maxTimeBank;
	timePerMove_ = timePerMove;
	timeBank_ = maxTimeBank;
}
std::string AbstractPlayer::getName() {
	return name_;
}
timell AbstractPlayer::getTimeBank() {
	return timeBank_;
}
IOPlayer* AbstractPlayer::getBot() {
	return bot_;
}
void AbstractPlayer::setTimBank(timell timeBank) {
	timeBank_ = timeBank;
}
void AbstractPlayer::updateTimeBank(timell timeElapsed) {
	timeBank_ = std::max(timell(), timeBank_-timeElapsed);
	timeBank_ = std::min(timeBank_+timePerMove_, maxTimeBank_);
}
void AbstractPlayer::sendSetting(std::string type, std::string value) {
	sendLine("settings " + type + " " + value);
}
void AbstractPlayer::sendSetting(std::string type, int value) {
	sendLine("settings " + type + " " + std::to_string(value));
}
void AbstractPlayer::sendUpdate(std::string type, AbstractPlayer* player, std::string value) {
	sendLine("update game " + type + " " + player->getName() + " " + value);
}
void AbstractPlayer::sendUpdate(std::string type, AbstractPlayer* player, int value) {
	sendLine("update game " + type + " " + player->getName() + " " + std::to_string(value));	
}
void AbstractPlayer::sendUpdate(std::string type, std::string value) {
	sendLine("update game " + type + " " + value);
}
void AbstractPlayer::sendUpdate(std::string type, int value) {
	sendLine("update game " + type + " " + std::to_string(value));
}
std::string AbstractPlayer::requestMove(std::string moveType) {
	clock_t start = clock();

	sendLine("action " + moveType + " " + std::to_string(timePerMove_));

	std::string response = bot_->getResponse(timeBank_);

	clock_t clocksElapsed = clock() - start;
	timell millisecondsElapsed = clocksElapsed/1000;

	updateTimeBank(millisecondsElapsed);

	return response;
}
void AbstractPlayer::sendLine(std::string content) {
	//TODO: add try-catch block
	bot_->writeToBot(content);
}