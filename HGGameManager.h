#pragma once
#include <list>
#include <string>
#include "Parameters.h"

class HGIOHandler;

class HGGameManager
{
private:
	std::list<char> m_triedLetters;
	std::list<char> m_guessedLetters;
	std::string m_keyword;
	uint8_t m_attempt;
	HGIOHandler &m_handler;

	struct GuessQuality
	{
		bool perfect, valid, used;
		uint8_t len;
		char c;
	};

public:
	HGGameManager(HGIOHandler &handler, std::string keyword);

public:
	void Tick();

private:
	void WriteBoard();
	std::string RequestGuess();
	GuessQuality ProcessInput(std::string in);
	void EvaluateGuess(GuessQuality gq);
	void HandleWin(GuessQuality gq);

	bool CheckWin();
	bool IsPerfect(std::string str);
	bool IsValid(char c);
	bool IsAlreadyUsed(char c);
};

