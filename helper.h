#ifndef HELPER_H
#define HELPER_H


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
#endif // HELPER_H
