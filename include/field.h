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

#include <vector>
#include <string>

#ifndef FIELD_H
#define FIELD_H

class Field {
	std::vector<std::vector<int> > board_;
	std::vector<std::vector<int> > macroBoard_;
	std::vector<std::vector<int> > allowedMacroBoard_;

	int checkBoard(std::vector<std::vector<int> > board, int macroRow, int macroCol);
public:
	Field();
	void clearBoard();
	bool addMark(int row, int col, int playerId);
	void updateAllowedMacroBoard(int nextMacroRow, int nextMacroCol);
	std::string boardString() const;
	std::string allowedMacroBoardString() const;
	int getWinner();
};

#endif //FIELD_H