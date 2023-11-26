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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "Item.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
    Item::Item() : iProduct(){}
    int Item::readSku(std::istream& is)
    {
        m_sku = ut.getInt(40000, 99999, "SKU: ");
        return m_sku;
    }
    void Item::linear(bool valid)
    {
        m_linear = valid;
    }
    int Item::qtyNeeded() const
    {
        return m_qtyNeeded;
    }
    int Item::qty() const
    {
        return m_qty;
    }
    Item::operator double() const
    {
        return m_price;
    }
    Item::operator bool() const
    {
        bool valid = false;
        if (m_state == nullptr)
        {
            valid = true;
        }
        return valid;
    }
    int Item::operator-=(int value)
    {
        return m_qty -= value;
    }
    int Item::operator+=(int value)
    {
        return m_qty += value;
    }
  
    bool Item::operator==(int sku) const
    {
        bool valid = false;
        if (m_sku == sku)
        {
            valid = true;
        }
        return valid;
    }
    bool Item::operator==(const char* description) const
    {
        bool valid = false;
        if (ut.strStr(m_description, description) != nullptr)
        {
            valid = true;
        }
        return valid;
    }
    std::ofstream& Item::save(std::ofstream& ofstr) const
    {
        if ((int)m_state == 0)
        {
            ofstr << m_sku << "\t" << m_description << "\t" <<m_qty
                << "\t" << m_qtyNeeded << "\t" << m_price << endl;
        }
        ofstr.close();
        return ofstr;
    }
    std::ifstream& Item::load(std::ifstream& ifstr)
    {
        int sku;
        int qty;
        int qtyneeded;
        double price;
        delete[] m_description;
        char descr[400];
        if (ifstr.fail())
        {
            cout << "Input file stream read failed!" << endl;
        }
        else if (!ifstr.eof())
        {
            ifstr >> sku;
            ut.extractChar(ifstr, '\t');
            ifstr.get(descr, 400, '\t');
            ut.extractChar(ifstr, '\t');
            ifstr >> qty;
            ut.extractChar(ifstr, '\t');
            ifstr >> qtyneeded;
            ut.extractChar(ifstr, '\t');
            ifstr >> price;
            ut.extractChar(ifstr, '\n');
            m_description = new char[strlen(descr) + 1];
            strcpy(m_description, descr);
            m_sku = sku;
            m_qtyNeeded = qtyneeded;
           m_qty = qty;
            m_price = price;
        }
        return ifstr;
    }
    std::ostream& Item::display(std::ostream& ostr) const
    {
        if (m_linear == true)
        {
            ostr << setw(5) << m_sku << " | " << left;
            if (strlen(m_description) > 35)
            {
                for (int i = 0; i < 35; i++)
                    ostr << left << m_description[i];
            }
            else
            {
                ostr << left << setw(35) << m_description;
            }
            ostr << " |"
                << right << setw(5) <<m_qty << " |" << setw(5) << m_qtyNeeded << " |";
            ostr << setw(8) << fixed << setprecision(2) << m_price << " |";
        }
        else
        {
            ostr << "AMA Item:" << endl;
            ostr << m_sku << ": " << m_description << endl;
            ostr << "Quantity Needed: " << m_qtyNeeded << endl;
            ostr << "Quantity Available: " <<m_qty << endl;
            ostr << "Unit Price: $" << m_price << endl;
            double needToBuy = m_price * (m_qtyNeeded -m_qty);
            ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << needToBuy << endl;
        }
        return ostr;
    }
    std::istream& Item::read(std::istream& istr)
    {
        char descr[35];
        int flag = 1;
        double price;
        delete[] m_description;
        m_state.clear();
        cout << "AMA Item:" << endl;
        cout << "SKU: " << m_sku << endl;
        cout << "Description: ";
        istr >> descr;
        if (strlen(descr) > 35)
        {
            cout << "Console entry failed!" << endl;
        }
        m_description = new char[strlen(descr) + 1];
        strcpy(m_description, descr);
        m_qtyNeeded = ut.getInt(1, 9999, "Quantity Needed: ");
       m_qty = ut.getInt(0, m_qtyNeeded, "Quantity On Hand: ");
        cout << "Unit Price: $";
        while (flag)
        {
            istr >> price;
            if (price > 9999.0 || price < 0.0)
            {
                cout << "Value out of range [0.00<=val<=9999.00]: ";
            }
            else if (istr.fail())
            {
                cout << "Invalid number, retry: ";
                istr.clear();
                istr.ignore(1000, '\n');
            }
            else if (price <= 9999.0 && price >= 0.0)
            {
                flag = 0;
                m_price = price;
            }
        }

        return istr;
    }
    void Item::clear()
    {
        m_price = 0.0;
        m_qty = 0;
        m_qtyNeeded = 0;
        m_state = "This object is in a good state!";
    }
    Item::~Item()
    {
        delete[] m_description;
    }
}



