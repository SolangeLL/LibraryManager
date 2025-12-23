#include "utils/Logger.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Logger::m_logger;

void Logger::Init()
{
    m_logger = spdlog::stdout_color_mt("MANAGER");
    m_logger->set_level(spdlog::level::trace);
    m_logger->set_pattern("%^[%T] [%n] [%s:%#] %v%$");
}
