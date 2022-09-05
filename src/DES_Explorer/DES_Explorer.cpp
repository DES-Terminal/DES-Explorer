/**
 * @file DES_Explorer.cpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 메인 클래스 소스파일입니다.
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 * @note author 및 date 관련해서는, 수정 시 추가해주세요.
 * @details 소스파일은 기능별로 분리하는것이 좋습니다.
 */

#include "DES_Explorer.hpp"

DES::Types::String
DES_Explorer::getCurrentPath()
{
  return currentPath.string(); /** 현재 탐색기의 경로를 반환한다. */
}