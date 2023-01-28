/**
 * @file FolderUtils.hpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 디렉토리에 대해 검색하는 함수들을 정의합니다.
 * @version 0.1
 * @date 2022-08-14
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include "DES_Errors.hpp"
#include "DES_Types.hpp"

#include <filesystem>

/**
 * @note 기본 함수와 헷갈리지 않게 하기 위해 네임스페이스를 지정하였다.
 */
namespace DES
{
  namespace Functions
  {
    /**
     * @brief 특정 디렉토리의 파일 목록을 읽어오는 함수
     *
     * @param path 파일을 읽을 경로
     * @return DES::Types::PathList 파일의 목록이 담긴 배열
     */
    DES::Types::PathList ReadFileList(DES::Types::Path const &path);

    /**
     * @brief 특정 디렉토리의 파일 목록 중 파일만을 읽어오는 함수
     *
     * @param path 파일을 읽을 경로
     * @return DES::Types::PathList 파일의 목록이 담긴 배열
     */
    DES::Types::PathList ReadOnlyFileList(DES::Types::Path const &path);

    /**
     * @brief 특정 디렉토리의 파일 목록 중 디렉토리만을 읽어오는 함수
     *
     * @param path 파일을 읽을 경로
     * @return DES::Types::PathList 디렉토리의 목록이 담긴 배열
     */
    DES::Types::PathList ReadOnlyDirectoryList(DES::Types::Path const &path);

    /**
     * @brief 파일 경로 중, 특정 이름으로 시작되는 리스트를 반환하는 함수
     *
     * @param pathlist 파일의 경로 목록
     * @param prefix 접두사
     * @return DES::Types::PathList 파일 이름이 prefix로 시작되는 경로가 담긴 배열
     */
    DES::Types::PathList ReadFilenameStartfrom(DES::Types::PathList const &pathlist, DES::Types::String const &prefix) noexcept;
  }
}