INCLUDE_PATHS = cell(0);
LIBRARIES = cell(0);
SOURCES = cell(0);

SOURCES(1) = cellstr('HelloWorld_new.cpp');
SOURCES(2) = cellstr('HelloWorld_delete.cpp');
SOURCES(3) = cellstr('HelloWorld_sayHello.cpp');
SOURCES(4) = cellstr('HelloWorld_setNumber.cpp');
SOURCES(5) = cellstr('HelloWorld_getNumber.cpp');

INCLUDE_PATHS(1) = cellstr('../../include');
LIBRARIES(1) = cellstr('barelibrary');

LIBRARY_PATH = cellstr('../../.libs');
command = ['mex COMPFLAGS="$COMPFLAGS -std=c++11 -Wall -fPIC" ' ];

for library = LIBRARIES
    command = [command '' char(LIBRARY_PATH) '/lib' char(library) '.a'];
end

for includePath = INCLUDE_PATHS
    command = [command ' -I' char(includePath)];
end

for source = SOURCES
    sourceCommand = [command ' ' char(source)];
    eval(sourceCommand);
end

