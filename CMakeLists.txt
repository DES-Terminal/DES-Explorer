# cmake 최소버전 지정
cmake_minimum_required(VERSION 3.11)

# 프로젝트 정보
project(
  DES-Explorer
  VERSION 0.1
  DESCRIPTION "DES 파일 탐색기"
  LANGUAGES CXX)

# Include 경로 오류시, 간단하게 파악하기 위한, 컴파일 커멘드 출력 설정
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#################################################
#################################################
#################################################

# 라이브러리 다운로드를 위한 스크립트 추가

include(FetchContent)

# ftxui 다운로드
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
  GIT_TAG        v3.0.0
)

FetchContent_MakeAvailable(
  ftxui
)

#################################################
#################################################
#################################################

# 소스파일 설정
file(
  GLOB_RECURSE SOURCES
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# 소스파일 설정중 RECURSE시, cmake에서 자동으로 만든 c파일이 경로에 포함되는 경우가 있어, 이를 해결하기 위한 제거루틴
set(GLOB_RECURSE_EXCLUDE_PATHS "CMakeFiles")
# 포함된 경로에서 CMakeFiles를 제거한다.
foreach(SOURCE ${SOURCES})
  foreach(EXCLUDE_PATH ${GLOB_RECURSE_EXCLUDE_PATHS})
    string(FIND ${SOURCE} ${EXCLUDE_PATH} FOUND_PATH)
    if(NOT ${FOUND_PATH} EQUAL -1)
      list(REMOVE_ITEM SOURCES ${SOURCE})
    endif()
  endforeach(EXCLUDE_PATH)
endforeach(SOURCE)

# 헤더파일 설정
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/includes
  ${ftxui_SOURCE_DIR}/include
)

# 라이브러리 추가
link_libraries(
  ftxui::screen
  ftxui::dom
  ftxui::component
)

#################################################
#################################################
#################################################

# 디버그파일
add_executable(
  des_explorer_debug
  ${SOURCES}
)

target_compile_options(
  des_explorer_debug
  PRIVATE
  -Wall
  -g
  -O0
)

target_compile_features(
  des_explorer_debug
  PRIVATE
  cxx_std_17
)

#################################################
#################################################
#################################################

# 릴리즈파일, 디버그파일 설정에서 -Wall -g 제거
add_executable(
  des_explorer
  ${SOURCES}
)

target_compile_options(
  des_explorer
  PRIVATE
  -O3
)

target_compile_features(
  des_explorer
  PRIVATE
  cxx_std_17
)
