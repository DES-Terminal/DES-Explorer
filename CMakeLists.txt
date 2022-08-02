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

# 소스파일 설정
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

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

#################################################
#################################################
#################################################

# 디버그파일
add_executable(DES-Explorer-DEBUG.out ${SOURCES})

target_include_directories(DES-Explorer-DEBUG.out PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

target_compile_features(DES-Explorer-DEBUG.out PRIVATE cxx_std_17)

target_compile_options(DES-Explorer-DEBUG.out PUBLIC -Wall -g)

target_link_libraries(DES-Explorer-DEBUG.out PUBLIC ncurses)

#################################################
#################################################
#################################################

# 릴리즈파일, 디버그파일 설정에서 -Wall -g 제거
add_executable(DES-Explorer.out ${SOURCES})

target_include_directories(DES-Explorer.out PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

target_compile_features(DES-Explorer.out PRIVATE cxx_std_17)

target_link_libraries(DES-Explorer.out PUBLIC ncurses)
