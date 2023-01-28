/**
 * @file folder_utils.cpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 디렉토리의 내용을 탐색하여 관련된 내용을 보여주는 기능입니다.
 * @version 0.1
 * @date 2022-08-13
 *
 * @copyright Copyright (c) 2022
 */

#include "des/utils/folder_utils.hpp"

des::types::PathList
des::functions::ReadFileList(des::types::Path const& path)
{
  /* 탐색을 원하는 경로가 디렉토리인지 확인 */
  if (!std::filesystem::is_directory(path)) {
    throw des::errors::not_a_directory();
  }

  des::types::PathList result;

  std::filesystem::directory_iterator iter(path);

  /* 디렉토리 내부 모든 데이터에 대해 배열에 추가 */
  for (auto& i : iter) {
    result.push_back(i.path());
  }

  return result;
}

des::types::PathList
des::functions::ReadOnlyFileList(des::types::Path const& path)
{
  des::types::PathList filelist = ReadFileList(path); // 오류는 내부에서 처리된다.

  des::types::PathList result;

  /* 디렉토리 내부 모든 데이터에 대해 배열에 추가 */
  for (auto& i : filelist) {
    if (std::filesystem::is_directory(i)) {
      // 디렉토리면 패스한다.
      continue;
    } else {
      // 파일만이면 리스트에 추가한다.
      result.push_back(i);
    }
  }

  return result;
}

des::types::PathList
des::functions::ReadOnlyDirectoryList(des::types::Path const& path)
{
  des::types::PathList filelist = ReadFileList(path); // 오류는 내부에서 처리된다.

  des::types::PathList result;

  /* 폴더 내부 모든 데이터에 대해 배열에 추가 */
  for (auto& i : filelist) {
    if (std::filesystem::is_directory(i)) {
      // 디렉토리면 리스트에 추가한다.
      result.push_back(i);
    } else {
      continue;
    }
  }

  return result;
}

des::types::PathList
des::functions::ReadFilenameStartfrom(des::types::PathList const& pathlist,
                                      des::types::String const&   prefix) noexcept
{
  des::types::PathList result;

  /* 파일 이름이 prefix로 시작되면 결과에 등록한다. */
  for (auto& i : pathlist) {
    if (i.filename().string().find(prefix) == 0) {
      result.push_back(i);
    }
  }

  return result;
}

// 정규형에 맞는 이름을 가진 함수 구현 예정

// 폴더 내부 폴더에 대한 재귀적 탐색 함수 구현 예정

// 파일 내용을 가지고 검색하는 함수 구현 예정

// 상위 폴더 경로 탐색
