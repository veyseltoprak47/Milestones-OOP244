/* Final Project Milestone 1
Module: Date
Filename: Date.cpp
Version 1.0
Author	Veysel Toprak
Revision History
-----------------------------------------------------------
Date      Reason
2023/10/11  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Date.h"

using namespace std;
namespace sdds
{
	void Date::setEmpty()
	{
		m_year = 0;
		m_month = 0;
		m_day = 0;
		State = nullptr;
		m_formatted = true;
	}

	bool Date::validate()
	{
		State.clear();
		bool valid = true;
		if (!(m_year >= currentYear && m_year <= maximumYear))
		{
			State = "Invalid year in date";
			State = 1;
			valid = false;
		}
		else if (!(m_month >= 1 && m_month <= 12))
		{
			State = "Invalid month in date";
			State = 2;
			valid = false;
		}
		else if (!(m_day >= 1 && m_day <= ut.daysOfMon(m_month, m_year)))
		{
			State = "Invalid day in date";
			State = 3;
			valid = false;
		}

		return valid;
	}

	int Date::uniqDateValue()
	{
		return m_year * 372 + m_month * 31 + m_day;
	}

	Date::Date()
	{
		Date::setEmpty();
		ut.getSystemDate(&m_year, &m_month, &m_day);
	}

	Date::Date(int year, int month, int day) : Status()
	{
		m_year = year;
		m_month = month;
		m_day = day;
		m_formatted = true;

		if (!validate())
		{
			m_year = 0;
			m_month = 0;
			m_day = 0;
		}
	}

	bool Date::operator== (Date& date)
	{
		bool valid = false;
		if (uniqDateValue() == date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator!= (Date& date)
	{
		bool valid = false;
		if (uniqDateValue() != date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator> (Date& date)
	{
		bool valid = false;
		if (uniqDateValue() > date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator< (Date& date)
	{
		bool valid = false;
		if (uniqDateValue() < date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator>= (Date& date)
	{
		bool valid = false;
		if (uniqDateValue() >= date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	bool Date::operator<= (Date& date)
	{
		bool valid = false;
		if (uniqDateValue() <= date.uniqDateValue())
		{
			valid = true;
		}
		return valid;
	}

	const Status& Date::state() const
	{
		return this->State;
	}

	Date& Date::formatted(bool valid)
	{
		m_formatted = valid;
		return *this;
	}

	Date::operator bool() const
	{
		return m_formatted;
	}

	std::ostream& Date::write(std::ostream& ostr) const
	{
		if (m_formatted)
		{
			ostr << m_year << "/";
			ostr.width(2);
			ostr.fill('0');
			ostr << m_month << "/";
			ostr.width(2);
			ostr.fill('0');
			ostr << m_day;
		}
		else
		{
			ostr << m_year - 2000;
			ostr.width(2);
			ostr.fill('0');
			ostr << m_month;
			ostr.width(2);
			ostr.fill('0');
			ostr << m_day;
		}
		return ostr;
	}

	std::istream& Date::read(std::istream& is)
	{
		int date;
		is >> date;
		if (is)
		{
			if (date >= 100000 && date <= 999999)
			{
				m_day = date % 100;
				m_month = (date % 10000 - m_day) / 100;
				m_year = date / 10000 + 2000;
			}
			else if (date >= 100 && date <= 9999)
			{
				m_year = currentYear;
				m_day = date % 100;
				m_month = (date % 10000 - m_day) / 100;
			}
			else if (date < 100)
			{
				m_year = currentYear;
				m_month = 0;
				m_day = date;
			}
			if (!validate())
			{
				is.setstate(ios::badbit);
			}
		}
		else
		{
			State = "Invalid date value";
			State = 0;
		}
		is.ignore(1000, '\n');

		return is;
	}
	Date::~Date()
	{
		State.clear();
	}

	std::ostream& operator<< (std::ostream& os, const Date& date)
	{
		return date.write(os);
	}

	std::istream& operator>> (std::istream& is, Date& date)
	{
		return date.read(is);
	}

}
