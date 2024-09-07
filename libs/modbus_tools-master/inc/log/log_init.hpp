#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

#include "../util/env.hpp"
#include "spdlog/async.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

// 编译release、链接时优化选项增加速度：-Wall -pthread -O3 -flto -DNDEBUG

#ifdef DEBUG
// 在spdlog.h之前定义才有效
#ifndef SPDLOG_TRACE_ON
#define SPDLOG_TRACE_ON
#endif

#ifndef SPDLOG_DEBUG_ON
#define SPDLOG_DEBUG_ON
#endif

#endif

// Linux使用CLOCK_REALTIME_COARSE
#ifndef SPDLOG_CLOCK_COARSE
#define SPDLOG_CLOCK_COARSE
#endif

using LV = spdlog::level::level_enum;

class LogInitializer
{
public:
    LogInitializer(const std::string &defaultLoggerName,
                   LV defalutLogLevel = LV::debug,
                   bool enableTerminalLog = false,
                   const int threadNum = 1) noexcept
    {
        static std::once_flag flag = std::once_flag();
        std::call_once(flag, init, defaultLoggerName, defalutLogLevel, enableTerminalLog, threadNum);
    }

private:
    LogInitializer(const LogInitializer &) = delete;
    LogInitializer &operator=(const LogInitializer &) = delete;

    static inline void
    init(const std::string &defaultLoggerName, LV defalutLogLevel, bool enableTerminalLog, const int threadNum) noexcept
    {
        try
        {
            if (defaultLoggerName.empty() || spdlog::get(defaultLoggerName) != nullptr)
            {
                return;
            }

            // 添加目的端
            std::vector<spdlog::sink_ptr> sinks;

            // 检查是否开启控制台
            if (enableTerminalLog)
            {
                sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
            }

            // 日志路径
            std::string logFilePath = logPath() + defaultLoggerName + "/" + defaultLoggerName;
#ifdef DEBUG
            logFilePath += "-debug";
#endif
            logFilePath += ".log";

            // 设置为滚动模式
            auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(logFilePath, 1024 * 1024 * 10, 10);
            sinks.push_back(rotating_sink);

            // 设置为异步模式
            spdlog::init_thread_pool(8192, threadNum); // 不要在其他地方再次调用init_thread_pool，否则会导致线程池析构
            std::shared_ptr<spdlog::logger> defaultLogger = std::make_shared<spdlog::async_logger>(
                defaultLoggerName, begin(sinks), end(sinks), spdlog::thread_pool(), spdlog::async_overflow_policy::block);

            // register日志
            spdlog::register_logger(defaultLogger);

            // 设置日志等级
            defaultLogger->set_level(defalutLogLevel);

            // 设置日志格式[年-月-日 时:分:秒.毫秒][进程号:线程号][调试级别](宏定义中添加: [文件名:行号]<函数名> - 具体内容)
            defaultLogger->set_pattern("[%Y-%m-%d %H:%M:%S.%e][%P:%t][%l]%v");

            // 设置当出发debug或更严重的错误时立刻刷新日志到disk
            defaultLogger->flush_on(spdlog::level::debug);

            spdlog::set_default_logger(defaultLogger);
        }
        catch (...)
        {
            spdlog::drop_all();
        }
    };
};
