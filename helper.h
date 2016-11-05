#ifndef HELPER_H
#define HELPER_H
#include "Definitions.h"

struct Resource
{
    double ReceivedTime;
    std::string NodeName;
    qint64 ram_used_Mb;
    qint16 cpu_used_perc;
};

struct Diagnostic
{

    std::string NodeName;
    int System;
    int Subsystem;
    int Component;
    int DiagnosticType;
    int Level;
    int Message;
    std::string Description;
};
struct Node
{
    qint64 time_delta_ms;
    std::string NodeName;
    int Level;
};
struct Device
{

    std::string DeviceName;
    std::string Architecture;
    std::string DeviceType;
    std::string DeviceParent;
    int Level;
    qint64 time_delta_ms;
    std::vector<Node> Nodes;
};

#endif

