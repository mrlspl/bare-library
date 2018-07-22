cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++11")


project(mycustomlib)
file(GLOB SOURCES ./src/HelloWorld.cpp)


include_directories(include)

add_library(mycustomlib SHARED ${SOURCES})

install(TARGETS mycustomlib DESTINATION lib/mycustomlib)

file(GLOB HEADERS ./include/HelloWorld.h)
install(FILES ${HEADERS} DESTINATION include/mycustomlib)

find_package(PythonInterp)

set(CXXTESTGEN ${./CMakeLists.txt}./bare-library/tools/cxxtest/bin/cxxtestgen.py)

find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
	include_directories(${CXXTEST_INCLUDE_DIR})
	enable_testing()
	CXXTEST_ADD_TEST(testrunner unit-test/main.cpp
			${CMAKE_SOURCE_DIR}/src/HelloWorld.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/unit-test/HelloWorldTestSuite.h)
endif()
	




