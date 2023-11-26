/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <ctime>
#include "Utils.h"
using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::alocpy(char*& destination, const char* source)
    {
        if (source)
        {
            delete[] destination;
            destination = nullptr;
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
        else
        {
            cout << "invalid Source!" << endl;
        }
    }
    int Utils::getInt(const char* prompt)
    {
        int input = 0;
        char buffer;
        bool valid = false;
        if (prompt)
        {
            cout << prompt;
            do
            {
                cin >> input;
                if (cin.fail())
                {
                    cout << "Invalid Integer, retry: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                {
                    cin.get(buffer);

                    if (buffer != '\n')
                    {
                        cout << "Enter only an integer, try again: ";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    else
                        valid = true;
                }
            } while (!valid);
        }
        return input;
    }
    int Utils::getInt(int min, int max, const char* prompt, const char* errMes)
    {
        int input = 0;
        bool valid = false;
        input = getInt(prompt);
        do
        {
            if (input < min || input > max)
            {
                if (errMes)
                {
                    cout << errMes << ", retry: ";
                }
                else
                {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
                cin >> input;
            }
            else
            {
                valid = true;
            }
        } while (!valid);
        return input;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    void Utils::extractChar(istream& istr, char ch) const
    {
        if (istr.peek() == ch)
        {
            istr.ignore();
        }
        else
        {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }
    const char* Utils::strStr(const char* str, const char* find)
    {
        const char* faddress = nullptr;
        int i;
        int flen = strlen(find);
        int slen = strlen(str);
        for (i = 0; i <= slen - flen && strnCmp(&str[i], find, flen); i++)
            ;
        if (i <= slen - flen)
            faddress = &str[i];
        return faddress;
    }

    int Utils::strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0;
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i])
        {
            i++;
        }
        return s1[i] - s2[i];
    }

}