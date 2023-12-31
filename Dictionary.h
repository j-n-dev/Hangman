#pragma once // probably won't be needed but just in case
#include <cstdint>
#include <string>
#include "RandomUniformInt.h"

constexpr uint8_t DICTIONARY_SIZE = 19;
std::string dictionary[DICTIONARY_SIZE] =
{
	"HANGMAN", "CUCUMBER", "PRONOUN", "ENGLISH", "POTATO", "EXECUTION", "CLASSROOM", "WARNING", "ERROR", "MESSAGE", "WINDOWS", "DEBUGGER", "PICKLE", "SOLUTION", "EXPLORER", "EXPERIENCE", "CPLUSPLUS", "BOOKSHELF", "SHIPPING"
};

std::string GetRandDictEntry()
{
	RandomUniformInt rui;
	return dictionary[rui.Next(0, DICTIONARY_SIZE - 1)];
}
