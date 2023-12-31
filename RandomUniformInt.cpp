#include "RandomUniformInt.h"

RandomUniformInt::RandomUniformInt()
    : m_rd(), m_gen(m_rd())
{
}

int RandomUniformInt::Next(int min, int max)
{
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(m_gen);
}
