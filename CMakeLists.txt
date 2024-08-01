cmake_minimum_required(VERSION 3.11)
project(TTTouchFix)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

FetchContent_Declare(
	minhook
	GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git
	GIT_TAG master
)

FetchContent_MakeAvailable(minhook)

include_directories (${minhook_SOURCE_DIR}/include)

add_library(TTTouchFix SHARED src/main.cpp)
set_target_properties(TTTouchFix PROPERTIES PREFIX "")
set_target_properties(TTTouchFix PROPERTIES SUFFIX ".dll")
set_target_properties(TTTouchFix PROPERTIES OUTPUT_NAME "dinput8")

target_link_libraries(TTTouchFix minhook)