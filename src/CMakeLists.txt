# set the name of the binary
set(BINARY ${CMAKE_PROJECT_NAME})

# recursively add source files to the executable
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES ${SOURCES})
add_executable(${BINARY} ${SOURCES})

# create library to include the code in the tests
add_library(${BINARY}_lib STATIC ${SOURCES})
