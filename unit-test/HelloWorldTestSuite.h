#pragma once

#include <cxxtest/TestSuite.h>
#include "../include/HelloWorld.h"

using namespace BareLibrary;

class HelloWorldTestSuite : public CxxTest::TestSuite
{
public:
    void testSayHello()
    {
         HelloWorld h;
         TS_ASSERT_EQUALS(h.sayHello().c_str(), "Hello World!");
    }
};
