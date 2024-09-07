#pragma once
#include <string>

#ifndef VAR_ENV
#define VAR_ENV "EMS_SIMULATE"
#endif

#ifndef DEFAULT_ROOT_DIR
#define DEFAULT_ROOT_DIR "/home/narada/modbus_test"
#endif

using namespace std::string_literals;

inline std::string rootPath()
{
    std::string rootDir;
    const char *envEmsSimulateRoot = getenv(VAR_ENV);
    if (nullptr == envEmsSimulateRoot)
    {
        rootDir = DEFAULT_ROOT_DIR;
    }
    else
    {
        rootDir = envEmsSimulateRoot;
    }

    return rootDir;
}

inline std::string csvPath()
{
    const std::string csvPath = "conf/csv/"s;
    return rootPath() + "/" + std::string(csvPath);
}

inline std::string deviceConfPath()
{
    const std::string deviceConfPath = "conf/device/config.json"s;
    return rootPath() + "/" + std::string(deviceConfPath);
}

inline std::string logPath()
{
    const std::string logPath = "log/"s;
    return rootPath() + "/build/" + std::string(logPath);
}
