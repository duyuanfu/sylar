CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(sylar)

SET(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(/usr/local/include/)
LINK_DIRECTORIES(/usr/local/lib/)

find_library(YAMLCPP yaml-cpp)

SET(LIB_SRC
    sylar/log.cc
    sylar/util.cc
    sylar/config.cc

    )

ADD_LIBRARY(sylar SHARED ${LIB_SRC})


ADD_EXECUTABLE(test tests/test.cc)
ADD_DEPENDENCIES(test sylar)
TARGET_LINK_LIBRARIES(test sylar ${YAMLCPP})

ADD_EXECUTABLE(test_config tests/test_config.cc)
ADD_DEPENDENCIES(test_config sylar)
TARGET_LINK_LIBRARIES(test_config sylar ${YAMLCPP})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)