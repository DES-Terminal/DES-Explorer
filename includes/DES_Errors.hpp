/**
 * @file DES_Errors.hpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 오류 타입을 지정하기 위한 헤더파일입니다.
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 * @note 표준 예외 클래스와의 일관성을 위해 클래스 이름은 소문자, snake_case로 작성한다.
 */

#pragma once

#include <stdexcept>

namespace DES
{
  namespace Errors
  {
    /**
     * @brief 파일이 존재하지 않습니다.
     */
    class file_not_found : public std::exception
    {
    public:
      const char *what() const noexcept override
      {
        return "File not found";
      }
    };
  }
}