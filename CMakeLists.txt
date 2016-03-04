cmake_minimum_required(VERSION 2.8.9)


project(ultimate-tic-tac-toe-engine)
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)
set(CMAKE_BINARY_DIR bin)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB_RECURSE SOURCES "src/*.cpp")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_executable(runner ${SOURCES})

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CMAKE_SOURCE_DIR}/include)
    enable_testing()
	file(GLOB_RECURSE TESTS "tests/*.h")
	file(GLOB_RECURSE HEADERS "include/*.h")
	set(testing_sources ${SOURCES})
	list(REMOVE_ITEM testing_sources ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

    set(CXXTEST_TESTGEN_INTERPRETER) # only use this if using CXXTEST_ADD_TEST
    CXXTEST_ADD_TEST(engine_test tests/test.cc  ${HEADERS} ${testing_sources} ${TESTS})
endif()