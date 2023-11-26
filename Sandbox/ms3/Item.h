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

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"
namespace sdds
{
    class Item : public iProduct
    {
        char* m_description{nullptr};
        bool m_linear{false};
        double m_price{0.0};
        int m_qty{ 0 };
        int m_qtyNeeded{0};
    protected:
        Status m_state{nullptr};
        int m_sku;
        void linear(bool valid);
    public:
        Item();
        int readSku(std::istream& is);
        int qtyNeeded() const;
        int qty() const;
        operator double() const;
        operator bool() const;
        int operator-=(int value);
        int operator+=(int value);
        bool operator==(int sku) const;
        bool operator==(const char* description) const;
        std::ofstream& save(std::ofstream& ofstr) const;
        std::ifstream& load(std::ifstream& ifstr);
        std::ostream& display(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        void clear();
        virtual ~Item();
    };

}
#endif // !SDDS_ITEM_H
