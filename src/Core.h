#pragma once

#include "Utilities/Log.h"

#define AG_LOG(logFormat, ...)			Log::GetInstance()->Print(Log::Type::LOG, logFormat, __VA_ARGS__)
#define AG_NOTICE(logFormat, ...)		Log::GetInstance()->Print(Log::Type::NOTICE, logFormat, __VA_ARGS__)
#define AG_WARN(logFormat, ...)			Log::GetInstance()->Print(Log::Type::WARNING, logFormat, __VA_ARGS__)
#define AG_SUCCESS(logFormat, ...)		Log::GetInstance()->Print(Log::Type::SUCCESS, logFormat, __VA_ARGS__)
#define AG_ERROR(logFormat, ...)		Log::GetInstance()->Print(Log::Type::ERROR, logFormat, __VA_ARGS__)