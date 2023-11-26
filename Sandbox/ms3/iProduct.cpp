/* Final Project Milestone 3
Module: Menu
Filename: Menu.h
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
#include "iProduct.h"

namespace sdds
{
	std::istream& operator>>(std::istream& istr, iProduct& iProduct)
	{
		iProduct.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const iProduct& iProduct)
	{
		iProduct.display(ostr);
		return ostr;
	}
}