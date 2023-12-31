#pragma once
#include "HGGameManager.h"
#include "HGIOHandler.h"

class HGApp
{
private:
	HGGameManager m_man;
	HGIOHandler m_handler;

public:
	HGApp();

public:
	void Start();
};

