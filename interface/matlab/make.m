INCLUDE_PATHS = cell(0);
LIBRARY_PATHS = cell(0);
LIBRARIES = cell(0);
SOURCES = cell(0);

INCLUDE_PATHS(1) = cellstr('../../include');
LIBRARY_PATHS(1) = cellstr('../../.libs');
LIBRARIES(1) = cellstr('barelibrary');
SOURCES(1) = cellstr('HelloWorld_create.cpp');
SOURCES(2) = cellstr('HelloWorld_sayHello.cpp');

command = 'mex COMPFLAGS="$COMPFLAGS -std=c++11 -Wall"';

for includePath = INCLUDE_PATHS
    command = [command ' -I' char(includePath)];
end

ld_library_path = getenv('LD_LIBRARY_PATH');
for libraryPath = LIBRARY_PATHS
    ld_library_path = [ld_library_path ':' fullfile(pwd, char(libraryPath))];
    command = [command ' -L' char(libraryPath)];
end

for library = LIBRARIES
    command = [command ' -l' char(library)];
end

for source = SOURCES
    sourceCommand = [command ' ' char(source)];
    eval(sourceCommand);
end

