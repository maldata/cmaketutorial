# Define the version of CMake that can be used
cmake_minimum_required(VERSION 3.2.2)

# Define the project name and any other pertinent project values,
# such as the version.
project (helloproj)

# This finds and loads settings from another project or module. Here, we load the
# threads module from /usr/local/share/cmake-3.2/Modules/FindThreads.cmake, which
# will figure out the system's thread library.
find_package(Threads)

# Create a variable that includes the names of the libraries we'll link against.
# You can also list them with individual target_link_libraries() lines.
# Order appears to be important. Here, libPocoFoundation is used by the others,
# and therefore, it must be at the end of the list.
set ( PROJECT_LINK_LIBS libPocoUtil.a libPocoXML.a libPocoJSON.a libPocoFoundation.a )

# This tells it where to look for the libraries, like gcc -L
link_directories(../lib/Linux/i686)

# This tells it where to look for headers, like gcc -I
include_directories(../inc)

# This can be used to add compiler options and definitions,
# for example, add_definitions(-DFOO -DBAR -std=c++0x)
#add_definitions(-std=c++0x)

# This will tell cmake to create the helloapp executable from hellopoco.cpp
add_executable(helloapp hellopoco.cpp)

# These tell the linker that helloapp needs to link against the poco libraries
# and the thread library that find_package found.
# Note that /usr/local/share/cmake-3.2/Modules/FindThreads.cmake sets the
# CMAKE_THREAD_LIBS_INIT variable, and we set PROJECT_LINK_LIBS ourselves above.
target_link_libraries(helloapp ${PROJECT_LINK_LIBS} )
target_link_libraries (helloapp ${CMAKE_THREAD_LIBS_INIT})
