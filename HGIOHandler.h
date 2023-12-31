#pragma once
#include <iostream>
#include <string>

class HGIOHandler
{
private:
	bool m_active;

public:
	HGIOHandler();

public:
	void Write(char c);
	void Write(std::string str);
	void WriteLine(std::string str);
	void WriteLine();

	std::string Read();

	bool RequestExit(); // misleading as it just forces an exit
	bool IsActive();
};

