#pragma once
#include "util/log_base.h"

#ifndef LOG_INIT
static LogInitializer logInitializer("import_point");
#define LOG_INIT
#endif