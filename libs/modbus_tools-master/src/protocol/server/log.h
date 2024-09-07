#pragma once
#include "util/log_base.h"

#ifndef LOG_INIT
static LogInitializer logInitializer("modbus_server");
#define LOG_INIT
#endif