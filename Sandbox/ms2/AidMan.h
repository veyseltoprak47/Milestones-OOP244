/* Final Project Milestone 2
Module: AidMan
Filename: AidMan.h
Version 1.0
Author	Veysel Toprak
Revision History
-----------------------------------------------------------
Date      Reason
2023/12/11  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
namespace sdds
{
	class AidMan {
		char* m_fileName{};
		Menu mainMenu;
		unsigned int menu();
		void setEmpty();
	public:
		AidMan(const char* fileName);
		~AidMan();
		void run();
	};
}
#endif // !SDDS_AIDMAN_H