cmake_minimum_required(VERSION 3.0.0)

project(LoggerTest)

set(Common_SRCS
Logger.cxx
Object.cxx
Module.cxx
)

add_library(Common ${Common_SRCS})

add_executable(LoggerTest LoggerTest.cxx EchoModule.cxx)
target_link_libraries(LoggerTest Common)

