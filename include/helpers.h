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

typedef long long timell;

#ifndef HELPERS_CPP
#define HELPERS_CPP
extern bool __DEBUG_GAME_INFO__;
extern bool __FIXEDSEED__;
extern int __NUMBEROFGAMES__;

#define PRINT(x) std::cout << std::endl << x 
#define PRINTSTDERR(x) std::cerr << std::endl << x
#define PRINTI(type,x) std::cerr << std::endl << type << #x << ": " << x
#define PRINTE(type,x) std::cerr << std::endl << type << x

#define ENABLE_DEBUGGING
#ifdef ENABLE_DEBUGGING
#include <iostream>
#define DEBUG(x) PRINT("DEBUG - ", x)

#else

#define DEBUG(x)

#endif

#define ENABLE_INFO
#ifdef ENABLE_INFO
#include <iostream>
#define INFO(x) PRINTI("INFO -- ", x)

#else 

#define INFO(x)

#endif

#define ENABLE_ERROR
#ifdef ENABLE_ERROR
#include <iostream>
#define ERROR(x) PRINTE("ERROR - ", x)

#else 

#define ERROR(x)

#endif

#include <vector>
#include <string>
#include <sstream>

void split(const std::string &s, char delim, std::vector<std::string> &elems);

std::vector<std::string> split(const std::string &s, char delim);


#endif //HELPERS_CPP

