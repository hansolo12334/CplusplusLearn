#pragma once

enum Commands
{
    cmCommitSearch = 95,
    cmCommitWrite = 96,
    cmCommitConnectSerial = 97,
    cmCommitConnectTcp = 98,
    cmConnectSerailServer = 99,
    cmConnectTcpServer = 100,
    cmCoilRegister = 101,
    cmDiscreteInputRegister = 102,
    cmHoldRegister = 103,
    cmInputRegister = 104,
    cmConnectTcpViewClose = 1001,
};

enum class RegisterType
{
    None = 0,
    Coil = 1,
    DiscreteInput = 2,
    Hold = 3,
    Input = 4,
};