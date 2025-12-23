#pragma once
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "spdlog/fmt/ostr.h"
#include "spdlog/spdlog.h"

class Logger
{
  public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger> &GetLogger()
    {
        return m_logger;
    }

  private:
    static std::shared_ptr<spdlog::logger> m_logger;
};

#define LOG_TRACE(...) \
    SPDLOG_LOGGER_CALL(Logger::GetLogger().get(), spdlog::level::trace, __VA_ARGS__)
#define LOG_INFO(...) \
    SPDLOG_LOGGER_CALL(Logger::GetLogger().get(), spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(...) \
    SPDLOG_LOGGER_CALL(Logger::GetLogger().get(), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...) \
    SPDLOG_LOGGER_CALL(Logger::GetLogger().get(), spdlog::level::err, __VA_ARGS__)
#define LOG_CRITICAL(...) \
    SPDLOG_LOGGER_CALL(Logger::GetLogger().get(), spdlog::level::critical, __VA_ARGS__)
