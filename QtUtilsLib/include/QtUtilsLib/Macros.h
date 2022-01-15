#pragma once

#include <utilsLib/Utils.h>

#ifdef _DEBUG
#define UTILS_QLOG_TRACE(msg) UTILS_LOG_TRACE(std::string(msg.toLocal8Bit().constData()))
#define UTILS_QLOG_DEBUG(msg) UTILS_LOG_DEBUG(std::string(msg.toLocal8Bit().constData()))
#else
#define UTILS_QLOG_TRACE(msg)
#define UTILS_QLOG_DEBUG(msg)
#endif

#define UTILS_QLOG_INFO(msg) UTILS_LOG_INFO(std::string(msg.toLocal8Bit().constData()))
#define UTILS_QLOG_WARN(msg) UTILS_LOG_WARN(std::string(msg.toLocal8Bit().constData()))
#define UTILS_QLOG_ERROR(msg) UTILS_LOG_ERROR(std::string(msg.toLocal8Bit().constData()))
#define UTILS_QLOG_FATAL(msg) UTILS_LOG_FATAL(std::string(msg.toLocal8Bit().constData()))
