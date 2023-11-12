/* Final Project Milestone 1
Module: Status
Filename: Status.h
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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

namespace sdds
{
	class Status{
		char* m_description{};
		int m_sCode{};
	public:
		Status(const char* description = nullptr);
		Status& operator=(int code);
		Status& operator=(const char* descrption);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& clear();
		std::ostream& print(std::ostream& ostr) const;
	};
	std::ostream& operator<< (std::ostream& ostr, const Status& status);

}
#endif // !