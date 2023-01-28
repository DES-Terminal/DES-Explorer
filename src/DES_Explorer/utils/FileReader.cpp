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

des::types::RawData
des::functions::read(des::types::Path const& path,
                     des::types::Size const& index,
                     des::types::Size const& length)
{
  des::types::RawData rawData(length); /* 데이터를 저장할 객체 생성 및 길이 초기화 */
  std::ifstream file(path, std::ios::binary); /* 파일 읽기 */

  /* 파일 존재 체크 */
  if (!file.is_open()) {
    throw des::errors::file_not_found();
  }

  file.seekg(index);                 /* 해당 위치로 이동 */
  file.read(rawData.data(), length); /* 파일 읽기 */
  file.close();                      /* 파일 닫기 */

  return rawData;
}