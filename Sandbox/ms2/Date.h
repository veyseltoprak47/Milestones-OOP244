/* Final Project Milestone 1
Module: Date
Filename: Date.h
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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
#include "Utils.h"

namespace sdds
{
	const int maximumYear = 2030;
	const int currentYear = 2023;

	class Date : public Status
	{
		int m_year{};
		int m_month{};
		int m_day{};
		bool m_formatted;
		Status State;
		bool validate();
		int uniqDateValue();
		void setEmpty();
	public:
		Date();
		Date(int year, int month, int day);
		bool operator== (Date& date);
		bool operator!= (Date& date);
		bool operator> (Date& date);
		bool operator< (Date& date);
		bool operator>= (Date& date);
		bool operator<= (Date& date);
		const Status& state() const;
		Date& formatted(bool valid);
		operator bool() const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		~Date();
	};
	std::ostream& operator<< (std::ostream& ostr, const Date& date);
	std::istream& operator>> (std::istream& istr, Date& date);
}
#endif // !SDDS_DATE_H
