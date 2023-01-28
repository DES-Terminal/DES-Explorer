/**
 * @file logger.hpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 로그를 효율적으로 관리하기 위한 클래스가 정의되었습니다.
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <fstream>
#include <iostream> // std::cout에 대해 출력하기 위해 포함하였다.
#include <string>

namespace des {
namespace utils {
/**
 * @brief 로거클래스
 * @details 로거클래스의 내용이 적기때문에 헤더파일 내부에 내용이 존재한다.
 */
class Logger
{
private:
  const std::string log_path; /** 로그파일 경로 */
  std::ofstream     log_file; /** 로그파일 스트림 */

  std::ostream& console = std::cout; /** 콘솔출력 */

  const time_t startTime; /** 시작시간 */

  /**
   * @brief 로그클래스의 기본값 경로를 설정하기 위한 함수
   *
   * @return std::string Logs/DES_현재시간.log 형태로 반환된다.
   */
  std::string getDefaultLogPath() const noexcept
  {
    std::string log_file_name = "Logs/DES_";
    log_file_name += std::to_string(startTime);
    log_file_name += ".log";
    return log_file_name;
  }

public:
  Logger()
    : Logger(getDefaultLogPath())
  {
  }

  Logger(std::string const& path)
    : log_path(path)
    , startTime(time(NULL))
  {
    log_file.open(log_path);
    log("Logger started.");
  }

  ~Logger()
  {
    log("Logger stopped.");
    log("총 소요시간 : " + std::to_string(time(NULL) - startTime));
    log_file.close();
  }

  /**
   * @brief 로그 출력 함수
   * @note 로그 출력을 추가하려면 해당 메소드에 기록을 추가하세요.
   *
   * @param message 출력할 메세지
   */
  void log(std::string const& message)
  {
    log_file << message << std::endl;
    console << message << std::endl;
  }
};
}
}