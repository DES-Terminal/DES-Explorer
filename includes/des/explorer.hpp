/**
 * @file explorer.hpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 메인 클래스 정의파일입니다.
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 * @note author 및 date 관련해서는, 수정 시 추가해주세요.
 */

#pragma once

#include "des/errors.hpp"
#include "des/types.hpp"
#include "des/utils/folder_utils.hpp"
#include "des/utils/logger.hpp"

namespace des {
/**
 * @brief 메인 클래스입니다.
 * @details 터미널 파일 브라우저의 역활을 해주는 메인 클래스 정의입니다.
 * @todo 경로 관리자 클래스 및 로거가 필요합니다.
 */
class Explorer
{
private:
  Logger logger; /**< 로거 클래스 */

protected:
  ::des::types::Path currentPath; /**< 현재 경로 */

public:
  Explorer()
    : currentPath("~")
  {
  }

  Explorer(::des::types::String const& openPath, ::des::types::String const& logPath)
    : logger(logPath)
    , currentPath(openPath)
  {
  }

  /**
   * @brief 현재 탐색기의 경로를 반환한다.
   *
   * @return ::des::types::String 현재 탐색기의 경로
   */
  ::des::types::String getCurrentPath() const noexcept;
};
}