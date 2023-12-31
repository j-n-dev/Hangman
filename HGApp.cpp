#include "HGApp.h"
#include "RandomUniformInt.h"
#include "Dictionary.h"

HGApp::HGApp()
	: m_handler(), m_man(m_handler, GetRandDictEntry())
{
}

void HGApp::Start()
{
	while (m_handler.IsActive())
		m_man.Tick();
}
