#pragma once
#include <random>

class RandomUniformInt
{
private:
	std::random_device m_rd;
	std::mt19937 m_gen;

public:
	RandomUniformInt();

public:
	int Next(int min, int max);
};

