cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS python)
find_package(PythonLibs)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()


include_directories(
  ${PYTHON_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  )

add_library(autolink SHARED ./autolink.c)
add_library(src_map SHARED ./src_map.c)
add_library(stack SHARED ./stack.c)
add_library(buffer SHARED ./buffer.c)
add_library(sundown SHARED ./sundown/src/markdown.c)

add_library(http SHARED ./HTTP.cc)

add_library(markdownparser SHARED ./MarkdownParser.cc)
add_library(markdownblock SHARED ./MarkdownBlock.cc)


add_library(uritemplate SHARED ./UriTemplateParser.cc)
add_library(serialize SHARED ./Serialize.cc)
add_library(json SHARED ./SerializeJSON.cc)
add_library(yaml SHARED ./SerializeYAML.cc)

add_library(regex SHARED ./posix/RegexMatch.cc)
add_library(parser SHARED ./Parser.cc)
add_library(parsercore SHARED ./ParserCore.cc)
add_library(snowcrash SHARED ./snowcrash.cc)
# add_library(Blueprint SHARED ./Blueprint.h)

add_library(mylib SHARED lib.cpp)
add_library(mypy SHARED module.cpp)

target_link_libraries(mypy
  ${Boost_LIBRARIES}
  ${PYTHON_LIBRARIES}

  buffer
  autolink
  src_map
  stack
  
  http
  sundown
  markdownparser
  markdownblock
  uritemplate
  serialize
  json
  yaml
  parser
  parsercore
  regex
  
  snowcrash
  
  mylib
  )

set_target_properties(mypy
  PROPERTIES
  PREFIX "" # remove the 'lib'
  )
