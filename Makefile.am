ACLOCAL_AMFLAGS = -I tools/m4
AM_CPPFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/tools/cxxtest

lib_LTLIBRARIES = libbarelibrary.la
libbarelibrary_la_SOURCES = src/HelloWorld.cpp

include_HEADERS = include/HelloWorld.h

bin_PROGRAMS = testrunner
nodist_testrunner_SOURCES = unit-test/main.cpp
testrunner_LDADD = libbarelibrary.la 

unit-test/main.cpp: unit-test/*.h
	tools/cxxtest/bin/cxxtestgen --error-printer -o unit-test/main.cpp unit-test/*.h
	
run-unit-tests : testrunner
	./testrunner

CLEANFILES = unit-test/main.cpp
