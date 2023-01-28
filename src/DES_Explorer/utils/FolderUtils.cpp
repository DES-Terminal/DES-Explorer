/**
 * @file FolderUtils.cpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 디렉토리의 내용을 탐색하여 관련된 내용을 보여주는 기능입니다.
 * @version 0.1
 * @date 2022-08-13
 *
 * @copyright Copyright (c) 2022
 */

#include "utils/FolderUtils.hpp"

DES::Types::PathList DES::Functions::ReadFileList(DES::Types::Path const &path)
{
  if (!std::filesystem::is_directory(path)) /** @brief 탐색을 원하는 경로가 디렉토리인지 확인 */
  {
    throw DES::Errors::not_a_directory();
  }

  DES::Types::PathList result;

  std::filesystem::directory_iterator iter(path);

  for (auto &i : iter) /** @brief 디렉토리 내부 모든 데이터에 대해 배열에 추가 */
  {
    result.push_back(i.path());
  }

  return result;
}

DES::Types::PathList DES::Functions::ReadOnlyFileList(DES::Types::Path const &path)
{
  DES::Types::PathList filelist = ReadFileList(path); /* 오류는 내부에서 처리된다. */

  DES::Types::PathList result;

  for (auto &i : filelist) /** @brief 디렉토리 내부 모든 데이터에 대해 배열에 추가 */
  {
    if (std::filesystem::is_directory(i)) /* 디렉토리면 패스한다. */
    {
      continue;
    }
    else
    {
      result.push_back(i); /* 파일만이면 리스트에 추가한다. */
    }
  }

  return result;
}

DES::Types::PathList DES::Functions::ReadOnlyDirectoryList(DES::Types::Path const &path)
{
  DES::Types::PathList filelist = ReadFileList(path); /* 오류는 내부에서 처리된다. */

  DES::Types::PathList result;

  for (auto &i : filelist) /** @brief 폴더 내부 모든 데이터에 대해 배열에 추가 */
  {
    if (std::filesystem::is_directory(i)) /* 디렉토리면 리스트에 추가한다. */
    {
      result.push_back(i);
    }
    else
    {
      continue;
    }
  }

  return result;
}

DES::Types::PathList DES::Functions::ReadFilenameStartfrom(DES::Types::PathList const &pathlist, DES::Types::String const &prefix) noexcept
{
  DES::Types::PathList result;

  for (auto &i : pathlist)
  {
    if (i.filename().string().find(prefix) == 0) /* 파일 이름이 prefix로 시작되면 결과에 등록한다. */
    {
      result.push_back(i);
    }
  }

  return result;
}

// 정규형에 맞는 이름을 가진 함수 구현 예정

// 폴더 내부 폴더에 대한 재귀적 탐색 함수 구현 예정

// 파일 내용을 가지고 검색하는 함수 구현 예정

// 상위 폴더 경로 탐색
