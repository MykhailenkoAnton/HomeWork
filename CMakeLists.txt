# cmake_minimum_required(VERSION 3.13)

# project(home)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

# add_executable(home C++_Learning/tasks_from_google.cpp)


cmake_minimum_required(VERSION 3.13)  # CMake version check
project(MyStudies)                       # Create project "My"
set(CMAKE_CXX_STANDARD 11)            # Enable c++14 standard

# Add sources files.
set(SOURCE_FILES
    # C++_Learning/tasks_from_google.cpp
    # C++_Learning/sen.cpp
    # Quest/fibonacci.cpp
    Practice/from_int_to_str.cpp
)

# Add headers files.
set(HEADER_FILES
)

# Add subdirectory.
set(DIRS
    # C++_Learning
    # Quest
    Practice
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

# Add executable target.
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${DIRS})