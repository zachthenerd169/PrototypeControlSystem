cmake_minimum_required(VERSION 3.0.0)

# -----------------------------------------------
# Create project
project(LoggerTest)


# -----------------------------------------------
# Create Executable
set(EXE_SRCS
  LoggerTest.cxx
  EchoModule.cxx
  ReverseEchoModule.cxx
)

add_executable(LoggerTest ${EXE_SRCS})

# -----------------------------------------------
# Create and Import Libraries
include_directories("${PROJECT_SOURCE_DIR}/Core")
add_subdirectory(Core)

target_link_libraries(LoggerTest Core)

