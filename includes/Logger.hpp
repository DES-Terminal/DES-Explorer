/**
 * @file Logger.hpp
 * @author 정종민 (xhve00000@gmail.com)
 * @brief 로그를 효율적으로 관리하기 위한 클래스가 정의되었습니다.
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <fstream>
#include <string>

#include <iostream> /** std::cout에 대해 출력하기 위해 포함하였다. */

/**
 * @brief 로거클래스
 * @details 로거클래스의 내용이 적기때문에 헤더파일 내부에 내용이 존재한다.
 */
class DES_Logger
{
private:
  const std::string logPath; /** 로그파일 경로 */
  std::ofstream logFile;     /** 로그파일 스트림 */

  std::ostream &console = std::cout; /** 콘솔출력 */

  const time_t startTime; /** 시작시간 */

  /**
   * @brief 로그클래스의 기본값 경로를 설정하기 위한 함수
   *
   * @return std::string Logs/DES_현재시간.log 형태로 반환된다.
   */
  std::string getDefaultLogPath()
  {
    std::string logFileName = "Logs/DES_";
    logFileName += std::to_string(startTime);
    logFileName += ".log";
    return logFileName;
  }

public:
  DES_Logger() : DES_Logger(getDefaultLogPath()) {}
  DES_Logger(std::string path) : logPath(path), startTime(time(NULL))
  {
    logFile.open(logPath);
    log("Logger started.");
  }

  ~DES_Logger()
  {
    log("Logger stopped.");
    log("총 소요시간 : " + std::to_string(time(NULL) - startTime));
    logFile.close();
  }

  /**
   * @brief 로그 출력 함수
   * @note 로그 출력을 추가하려면 해당 메소드에 기록을 추가하세요.
   *
   * @param message 출력할 메세지
   */
  void log(std::string message)
  {
    logFile << message << std::endl;
    console << message << std::endl;
  }
};