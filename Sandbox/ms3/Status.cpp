/* Final Project Milestone 3
Module: Status
Filename: Status.cpp
Version 1.0
Author	Veysel Toprak
Revision History
-----------------------------------------------------------
Date      Reason
2023/25/11  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Status.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
	void Status::setEmpty()
	{
		m_description = nullptr;
		m_sCode = 0;
	}
	Status::Status(const char* description)
	{
		if (description && description[0]!='\0')
		{
			ut.alocpy(m_description, description);
			m_sCode = 0;
		}
		else
		{
			setEmpty();
		}
		
	}

	Status& Status::operator=(int code)
	{
		m_sCode = code;
		return *this;
	}

	Status& Status::operator=(const char* description)
	{
	
		if (description)
		{
			ut.alocpy(m_description, description);
		}
		return *this;
	}

	Status::operator int() const
	{
		return m_sCode;
	}

	Status::operator const char* () const
	{
		return m_description;
	}

	Status::operator bool() const
	{
		return m_description;
	}

	Status& Status::clear()
	{
		if (m_description)
		{
			delete[] m_description;
			m_description = nullptr;
			m_sCode = 0;
		}
		
		return *this;
	}

	std::ostream& Status::print(std::ostream& ostr) const
	{
		if (this != nullptr)
		{
			if (m_sCode != 0)
			{
				ostr << "ERR#" << m_sCode << ": ";
			}
			if (m_description != nullptr)
			{
				ostr << m_description;
			}
		}

		return ostr;
	}

	std::ostream& operator << (std::ostream& ostr, const Status& sts)
	{
		return sts.print(ostr);
	}
}