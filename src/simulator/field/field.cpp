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

#include "field.h"

int Field::checkBoard(std::vector<std::vector<int> > board, int macroRow, int macroCol) {
	for(int r = macroRow*3; r < macroRow*3+3; r++) {
		int count = 0, playerId = board[r][macroCol*3];
		for(int c = macroCol*3; c < macroCol*3+3; c++)
			if(board[r][c] == playerId) count++;
		if(count == 3 && playerId) return playerId;
	}

	for(int c = macroCol*3; c < macroCol*3+3; c++) {
		int count = 0, playerId = board[macroRow*3][c];
		for(int r = macroRow*3; r < macroRow*3+3; r++)
			if(board[r][c] == playerId) count++;
		if(count == 3 && playerId) return playerId;
	}
	
	int r = macroRow*3, c = macroCol*3, count = 0;
	int playerId = board[r][c];
	for(int i = 0; i < 3; i++) {
		if(board[r][c] == playerId) count++;
		r++,c++;
	}
	if(count == 3 && playerId) return playerId;

	r = macroRow*3+2, c = macroCol*3, count = 0;
	playerId = board[r][c];
	for(int i = 0; i < 3; i++) {
		if(board[r][c] == playerId) count++;
		r--, c++;
	}
	if(count == 3 && playerId) return playerId;

	return 0;
}

Field::Field() {
	clearBoard();
}

void Field::clearBoard() {
	board_ = std::vector<std::vector<int> >(9, std::vector<int>(9,0));
	macroBoard_ = std::vector<std::vector<int> >(3, std::vector<int>(3,0));
}

bool Field::addMark(int row, int col, int playerId) {
	if(row >= 9 || row < 0 || col >= 9 || row < 0) return false;
	if(board_[row][col]) return false;
	int macroRow = row/3, macroCol = col/3;
	if(allowedMacroBoard_[macroRow][macroCol] != -1) return false;
	board_[row][col] = playerId;
	macroBoard_[macroRow][macroCol] = checkBoard(board_, macroRow, macroCol);
	updateAllowedMacroBoard(row-macroRow*3, col-macroCol*3);
	return true;
}

void Field::updateAllowedMacroBoard(int nextMacroRow, int nextMacroCol) {
	for(int row = 0; row < 3; row++) {
		for(int col = 0; col < 3; col++) {
			if(board_[row][col]) {
				allowedMacroBoard_[row][col] = board_[row][col];
			} else if(board_[nextMacroRow][nextMacroCol]) {
				allowedMacroBoard_[row][col] = -1;
			} else if(row == nextMacroRow && col == nextMacroCol) {
				allowedMacroBoard_[row][col] = -1;
			} else {
				allowedMacroBoard_[row][col] = 0;
			}
		}
	}
}

int Field::getWinner() {
	return checkBoard(macroBoard_,0,0);
}

std::string conv(const std::vector<std::vector<int> > &vv) {
		std::string ret;
		for(int i = 0; i < vv.size(); i++) {
			for(int j = 0; j < vv[i].size(); j++) {
				if(ret.size()) ret += ",";
				ret += std::to_string(vv[i][j]);
			}
		}
		return ret;
}

std::string Field::boardString() const {
	return conv(board_);
}
std::string Field::allowedMacroBoardString() const {
	return conv(allowedMacroBoard_);
}

