#pragma once

#include "Utilities/Log.h"

#define AG_LOG(log_format, ...)			Log::GetInstance()->Print(Log::Type::LOG, log_format, __VA_ARGS__)
#define AG_NOTICE(log_format, ...)		Log::GetInstance()->Print(Log::Type::NOTICE, log_format, __VA_ARGS__)
#define AG_WARN(log_format, ...)		Log::GetInstance()->Print(Log::Type::WARNING, log_format, __VA_ARGS__)
#define AG_SUCCESS(log_format, ...)		Log::GetInstance()->Print(Log::Type::SUCCESS, log_format, __VA_ARGS__)
#define AG_ERROR(log_format, ...)		Log::GetInstance()->Print(Log::Type::ERROR, log_format, __VA_ARGS__)