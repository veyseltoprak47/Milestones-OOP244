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
#include <iostream>
#include "Status.h"
#include "Utils.h"


namespace sdds
{
	Status::Status(const char* description)
	{
		if (description)
		{
			ut.alocpy(m_description, description);
		}
		else
		{
			m_description = nullptr;
		}
		
		m_sCode = 0;
	}
	Status::~Status()
	{
		delete[] m_description;
	}
	Status::operator int() const
	{
		return m_sCode;
	}
	Status::operator bool() const
	{
		return m_description == nullptr;
	}
	
}