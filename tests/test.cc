/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "/Users/ghooo/Projects/ultimate-tic-tac-toe-engine/tests/maintest.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "/Users/ghooo/Projects/ultimate-tic-tac-toe-engine/tests/maintest.h", 22, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testMain : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testMain() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 38, "testMain" ) {}
 void runTest() { suite_MyTestSuite.testMain(); }
} testDescription_suite_MyTestSuite_testMain;

static class TestDescription_suite_MyTestSuite_testSimulator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testSimulator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 43, "testSimulator" ) {}
 void runTest() { suite_MyTestSuite.testSimulator(); }
} testDescription_suite_MyTestSuite_testSimulator;

static class TestDescription_suite_MyTestSuite_testIOPlayer1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testIOPlayer1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 50, "testIOPlayer1" ) {}
 void runTest() { suite_MyTestSuite.testIOPlayer1(); }
} testDescription_suite_MyTestSuite_testIOPlayer1;

static class TestDescription_suite_MyTestSuite_testIOPlayer2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testIOPlayer2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 79, "testIOPlayer2" ) {}
 void runTest() { suite_MyTestSuite.testIOPlayer2(); }
} testDescription_suite_MyTestSuite_testIOPlayer2;

static class TestDescription_suite_MyTestSuite_testPstreams : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testPstreams() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 120, "testPstreams" ) {}
 void runTest() { suite_MyTestSuite.testPstreams(); }
} testDescription_suite_MyTestSuite_testPstreams;

static class TestDescription_suite_MyTestSuite_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAddition() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 135, "testAddition" ) {}
 void runTest() { suite_MyTestSuite.testAddition(); }
} testDescription_suite_MyTestSuite_testAddition;

static class TestDescription_suite_MyTestSuite_testAddition1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAddition1() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 140, "testAddition1" ) {}
 void runTest() { suite_MyTestSuite.testAddition1(); }
} testDescription_suite_MyTestSuite_testAddition1;

static class TestDescription_suite_MyTestSuite_testAddition2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAddition2() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 145, "testAddition2" ) {}
 void runTest() { suite_MyTestSuite.testAddition2(); }
} testDescription_suite_MyTestSuite_testAddition2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
