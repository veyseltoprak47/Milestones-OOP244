/* Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <sstream>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds {
    void Menu::setEmpty()
    {
        m_contentMenu = nullptr;
        m_numOptions = 0;
    }
    Menu::Menu(const char* contentMenu) {
        int options = 0;
        for (unsigned int i = 0; i < strlen(contentMenu); i++) {
            if (contentMenu[i] == '\t') {
                options++;
            }
        }

        if (contentMenu && options <= MAX_MENU) {
            ut.alocpy(m_contentMenu, contentMenu);
            m_numOptions = options + 1;
        }
        else {
            setEmpty();
        }
    }
    bool Menu::isValid() const {
        return m_numOptions <= MAX_MENU && m_contentMenu != nullptr;
    }
    Menu::~Menu() {
        delete[] m_contentMenu;
    }

    unsigned int Menu::run() {
        if (!m_contentMenu) {
            cout << "Invalid Menu!" << endl;
            return 0;
        }

        while (true) {

            int optionNum = 1;
           istringstream stream(m_contentMenu);
           string token;

            while (getline(stream, token, '\t')) {
                cout << optionNum << "- " << token << endl;
                optionNum++;
            }

            cout << "---------------------------------" << endl;
            cout << "0- Exit" << endl;

            unsigned int choice;
            do {
                cout << "> ";
                cin >> choice;

                if (cin.fail()) {
                    cout << "Invalid Integer, retry: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cin >> choice;
                }
                else if (choice < 0 || choice > m_numOptions) {
                    cout << "Value out of range [0<=val<=" << m_numOptions << "]: ";
                    cin >> choice;
                }
            } while (choice < 0 || choice > m_numOptions);

            if (choice == 0) {
                return choice;
            }

            return choice;
        }
    }

    
}
