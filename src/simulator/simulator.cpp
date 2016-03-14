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

#include "simulator.h"

Simulator::Simulator():AbstractGame(){
	failedPlayerId_ = 0;
	moveNumber_ = 1;
	field_ = new Field();
}
Simulator::~Simulator() {
	// HACK: have to delete ioplayers in reverse order.
	for(int i = ioplayers_.size()-1; i >= 0; i--) {
		delete ioplayers_[i];
	}
	// for(int i = 0; i < ioplayers_.size(); i++) {
	// 	delete ioplayers_[i];
	// }
	for(int i = 0; i < players_.size(); i++) {
		delete players_[i];
	}
	delete field_;
}
void Simulator::addPlayer(std::string command) {
	int playerId = players_.size()+1;
	std::string name = "player"+std::to_string(playerId);

	ioplayers_.push_back(new IOPlayer(command));
	players_.push_back(new Player(name, ioplayers_.back(), MAXTIMEBANK, TIMEPERMOVE, playerId));
}
void Simulator::sendSettings() {
	if(players_.size() < 2) {
		throw "Error: Number of players less than 2.";
	}
	for(auto &player:players_) {
	    player->sendSetting("timebank", MAXTIMEBANK);
	    player->sendSetting("time_per_move", TIMEPERMOVE);
	    player->sendSetting("player_names", players_[0]->getName() + "," + players_[1]->getName());
	    player->sendSetting("your_bot", player->getName());
	    player->sendSetting("your_botid",player->getPlayerId());
	}
}
bool Simulator::playRound() {
	for(auto &player: players_) {
		player->sendUpdate("round", roundNumber_);
		player->sendUpdate("move", moveNumber_);

		if(getWinner() || isDraw()) {
			return false;
		}
		bool moveSuccess = false;
		for(int trial = 1; trial <= 3; trial++) {
			player->sendUpdate("field", field_->boardString());
			player->sendUpdate("macroboard", field_->allowedMacroBoardString());
			std::string response = player->requestMove("move");
			if(checkAndPlay(response, player)) {
				if(__DEBUG_GAME_INFO__) {
					PRINTSTDERR("ROUND # "+std::to_string(roundNumber_));
					PRINTSTDERR("MOVE  # "+std::to_string(moveNumber_));
					PRINTSTDERR(field_->boardString());
					PRINTSTDERR(field_->allowedMacroBoardString());
					PRINTSTDERR(field_->printableBoardString());
					PRINTSTDERR("");
				}
				// TODO: save moves to vector<Move>
				moveSuccess = true;
				player->sendUpdate("field", field_->boardString());
				break;
			}
		}
		if(!moveSuccess) {
			failedPlayerId_ = player->getPlayerId();
			return false;
		}
		moveNumber_++;
	}
	roundNumber_++;
	return true;
}
bool Simulator::checkAndPlay(std::string response, Player *player) {
	std::vector<std::string> parts = split(response,' ');
	if(parts.size() >= 3 && parts[0] == "place_move") {
		int row = stoi(parts[2]), col = stoi(parts[1]);
		if(field_->addMark(row, col, player->getPlayerId())) {
			playedGame_ += field_->boardString();
			return true;
		}
	}
	return false;
}
int Simulator::getFailedPlayerId() {
	return failedPlayerId_;
}
AbstractPlayer* Simulator::getWinner() {
	if(failedPlayerId_) {
		for(auto player:players_) {
			if(player->getPlayerId() != failedPlayerId_) {
				return player;
			}
		}
	}
	int winner = field_->getWinner();
	for(auto player:players_) {
		if(player->getPlayerId() == winner) {
			return player;
		}
	}
	return NULL;
}
bool Simulator::isDraw() {
	return field_->isAllowedMacroBoardFull();
}

void Simulator::saveGame() {

}
