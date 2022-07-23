/**
 * @file FileReader.hpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 파일을 읽어오는 함수들을 정의합니다.
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 */

#include "DES_Errors.hpp"
#include "DES_types.hpp"

#include <fstream>

/**
 * @note 기본 함수와 헷갈리지 않게 하기 위해 네임스페이스를 지정하였다.
 */
namespace DES
{
  namespace Functions
  {
    /**
     * @brief 특정 위치로부터 파일을 읽어오는 함수
     *
     * @param Path 파일의 경로
     * @param index 읽을 위치의 시작점
     * @param length 읽을 글자 수
     * @return Types::RawData 읽어들인 데이터
     */
    DES::Types::RawData Read(DES::Types::Path Path, DES::Types::Size index, DES::Types::Size length);
  }
}