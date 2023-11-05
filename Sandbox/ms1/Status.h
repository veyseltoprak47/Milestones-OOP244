/* Citation and Sources...
Final Project Milestone ?
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	Veysel Toprak
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

namespace sdds
{
	class Status{
		char* m_description{};
		int m_sCode{};
	public:
		Status(const char* description = nullptr);
		~Status();
		operator int()const;
		operator bool()const;
		//operator char()const;
		Status& operator=()
	};

}
#endif // !