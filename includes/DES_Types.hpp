/**
 * @file DES_Types.hpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 파일의 자료형을 정의하는 헤더파일입니다.
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace DES
{
  /**
   * @brief 파일의 자료형을 묶는 네임스페이스입니다. 타입을 추후에 수정될 때를 대비하여 정의하였습니다.
   * @note Types::RawData_t처럼 사용됩니다.
   */
  namespace Types
  {

    /**
     * @brief 읽어온 파일의 원본 데이터가 담기는 배열입니다.
     * @details Vector는 데이터의 크기를 가져올 수 있고, 오류가 적을 수 있기 때문에 사용되었습니다.
     */
    using RawData = std::vector<char>;

    /**
     * @brief 읽을 파일의 인덱스나 길이를 나타내는 자료형입니다.
     * @details size_t와 동일하나, 변경이 필요할 때를 대비하여 정의하였습니다.
     */
    using Size = unsigned long long;

    /**
     * @brief 파일의 경로를 나타내는 자료형입니다.
     */
    using Path = std::filesystem::path;

    /**
     * @brief 표준 문자열입니다.
     * @detials 클래스 타입으로 변경할 수 있게, 타입을 정의하였습니다.
     */
    using String = std::string;

  }
}