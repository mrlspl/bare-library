INCLUDE_PATHS = cell(0);
SOURCES = cell(0);

INCLUDE_PATHS(1) = cellstr('../../include');
SOURCES(1) = cellstr('HelloWorld_create.cpp');

command = 'mex COMPFLAGS="$COMPFLAGS -std=c++11 -Wall"';

for includePath = INCLUDE_PATHS
    command = [command ' -I' char(includePath)];
end

for source = SOURCES
    command = [command ' ' char(source)];
end

eval(command);
