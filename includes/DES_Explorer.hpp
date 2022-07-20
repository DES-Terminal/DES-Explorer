/**
 * @file DES_Explorer.hpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 메인 클래스 정의파일입니다.
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 * @note author 및 date 관련해서는, 수정 시 추가해주세요.
 */

#pragma once

#include "Logger.hpp"

#include <filesystem>
#include <string>

/**
 * @brief 메인 클래스입니다.
 * @details 터미널 파일 브라우저의 역활을 해주는 메인 클래스 정의입니다.
 * @todo 경로 관리자 클래스 및 로거가 필요합니다.
 */
class DES_Explorer
{
private:
  DES_Logger logger; /** 로거 클래스 */

protected:
  std::filesystem::path current_path; /** 현재 경로 */

public:
  DES_Explorer() : current_path("~") {}                                                                    /** 기본 생성자 */
  DES_Explorer(std::string open_path, std::string log_path) : current_path(open_path), logger(log_path) {} /** 로그 경로 지정 */

  /**
   * @brief 현재 탐색기의 경로를 반환한다.
   *
   * @return std::string 현재 탐색기의 경로
   */
  std::string get_current_path();
};