#include "HGIOHandler.h"

HGIOHandler::HGIOHandler()
    : m_active(true)
{
}

void HGIOHandler::Write(char c)
{
    std::cout << c;
}

void HGIOHandler::Write(std::string str)
{
    std::cout << str;
}

void HGIOHandler::WriteLine(std::string str)
{
    std::cout << str << std::endl;
}

void HGIOHandler::WriteLine()
{
    std::cout << std::endl;
}

std::string HGIOHandler::Read()
{
    std::string str;
    std::cin >> str;
    return str;
}

bool HGIOHandler::RequestExit()
{
    m_active = false;
    return true;
}

bool HGIOHandler::IsActive()
{
    return m_active;
}
