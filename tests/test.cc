#include <iostream>
#include "../sylar/log.h"

int main(int argc, char** argv)
{
    sylar::Logger::ptr logger(new sylar::Logger);
    logger->addAppender(sylar::LogAppender::ptr(new sylar::StdoutLogAppender));

    sylar::FileLogAppender::ptr file_appender(new sylar::FileLogAppender("./log.txt"));
    sylar::LogFormatter::ptr fmt(new sylar::LogFormatter("%d%T%p%m%n"));
    file_appender->setFormatter(fmt);
    file_appender->setLevel(sylar::LogLevel::UNKNOW);
    logger->addAppender(file_appender);

    // sylar::LogEvent::ptr event(new sylar::LogEvent(logger,  sylar::LogLevel::Level::DEBUG, __FILE__, __LINE__, 0, 1, 2, time(0), "unkown"));
    // event->getSS() << "hello sylar log";
    // logger->log(sylar::LogLevel::DEBUG, event);
    
    SYLAR_LOG_INFO(logger) << "test macro";

    SYLAR_LOG_FMT_ERROR(logger, "test macro fmt error %s", "aa");

    auto l = sylar::LoggerMgr::GetInstance()->getLogger("XX");
    SYLAR_LOG_INFO(l) << "xxx";

    
    return 0;
}