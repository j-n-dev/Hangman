#include "HGGameManager.h"
#include "HGIOHandler.h"

HGGameManager::HGGameManager(HGIOHandler& handler, std::string keyword)
	: m_handler(handler), m_keyword(keyword), m_attempt(MAX_ATTEMPTS)
{
}

void HGGameManager::Tick()
{
	WriteBoard();
	GuessQuality gq = ProcessInput(RequestGuess());
	EvaluateGuess(gq);
	HandleWin(gq);
}

void HGGameManager::WriteBoard()
{
	for (char c : m_keyword)
	{
		bool foundChar = false;
		for (char k : m_guessedLetters)
			if (c == k)
			{
				foundChar = true;
				break;
			}
		if (foundChar)
			m_handler.Write(c);
		else
			m_handler.Write('_');
	}
	m_handler.WriteLine();
	m_handler.Write("Attempts left: " + std::to_string(m_attempt));
	m_handler.WriteLine();

	m_handler.Write("Tried but failed letters: ");
	for (char c : m_triedLetters)
	{
		m_handler.Write(c);
		m_handler.Write(' ');
	}
	m_handler.WriteLine();
}

std::string HGGameManager::RequestGuess()
{
	m_handler.WriteLine("What is your guess?");
	return m_handler.Read();
}

HGGameManager::GuessQuality HGGameManager::ProcessInput(std::string in)
{
	m_handler.WriteLine();
	std::string str = in;
	for (int i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	char c = str[0];

	bool perfect = IsPerfect(str);
	bool valid = IsValid(c);
	bool used = IsAlreadyUsed(c);
	return { perfect, valid, used, (uint8_t)str.length(), c};
}

void HGGameManager::EvaluateGuess(GuessQuality gq)
{
	if (gq.perfect)
	{
		m_handler.WriteLine("That's perfect!");
	}
	else if (!gq.perfect && gq.len > 1)
	{
		m_handler.WriteLine("Greedy bastard!\n");
		m_attempt -= 2;
	}
	else if (gq.used)
	{
		m_handler.WriteLine("You already tried this letter!\n");
	}
	else if (gq.valid)
	{
		m_handler.WriteLine("That's correct!\n");
		m_guessedLetters.push_back(gq.c);
	}
	else
	{
		m_handler.WriteLine("That's incorrect!\n");
		m_triedLetters.push_back(gq.c);
		m_attempt--;
	}
}

void HGGameManager::HandleWin(GuessQuality gq)
{
	if (CheckWin() || gq.perfect)
	{
		m_handler.WriteLine(m_keyword + "\nYou have guessed the word correctly!");
		m_handler.RequestExit();
	}
	else if (m_attempt == 0)
	{
		m_handler.WriteLine("You failed! Better luck next time.\nThe word was: " + m_keyword);
		m_handler.RequestExit();
	}
}

bool HGGameManager::CheckWin()
{
	bool won = true;
	bool found = false;
	for (char c : m_keyword)
	{
		found = false;
		for (char k : m_guessedLetters)
			if (c == k)
			{
				found = true;
				break;
			}
		if (!found)
		{
			won = false;
			break;
		}
	}
	return won;
}

bool HGGameManager::IsPerfect(std::string str)
{
	return str == m_keyword;
}

bool HGGameManager::IsValid(char c)
{
	bool isValid = false;
	for (char k : m_keyword)
		if (k == c)
		{
			isValid = true;
			break;
		}
	return isValid;
}

bool HGGameManager::IsAlreadyUsed(char c)
{
	bool isDuplicate = false;
	for (char k : m_triedLetters)
		if (k == c)
		{
			isDuplicate = true;
			break;
		}
	for (char k : m_guessedLetters)
		if (k == c)
		{
			isDuplicate = true;
			break;
		}
	return isDuplicate;
}
