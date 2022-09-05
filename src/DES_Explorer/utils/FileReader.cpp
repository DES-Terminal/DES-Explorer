/**
 * @file FileReader.cpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 파일을 읽어오는 함수의 소스파일입니다.
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 */

#include "utils/FileReader.hpp"

DES::Types::RawData
DES::Functions::read(DES::Types::Path path, DES::Types::Size index, DES::Types::Size length)
{
  DES::Types::RawData rawData(length); /** @brief 데이터를 저장할 객체 생성 및 길이 초기화 */
  std::ifstream file(path, std::ios::binary); /** @brief 파일 읽기 */

  /**
   * @brief 파일 존재 체크
   */
  if (!file.is_open()) {
    throw DES::Errors::file_not_found();
  }

  file.seekg(index);                 /** @details 해당 위치로 이동 */
  file.read(rawData.data(), length); /** @details 파일 읽기 */
  file.close();                      /** @details 파일 닫기 */

  return rawData;
}