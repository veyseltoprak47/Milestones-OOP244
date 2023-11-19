/* Final Project Milestone 2
Module: AidMan
Filename: AidMan.cpp
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
#include <iostream>
#include <cstring>
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"

using namespace std;
namespace sdds {

    AidMan::AidMan(const char* fileName) :mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
        if (fileName && strlen(fileName) > 0) {
            ut.alocpy(m_fileName, fileName);
        }
        else {
            setEmpty();
        }
    }

    AidMan::~AidMan() {
        delete[] m_fileName;
    }

    void AidMan::run() {
        while (true) {
            cout << "Aid Management System" << endl;
            cout << "Date: " <<Date()<< endl;
            cout << "Data file: " << (m_fileName ? m_fileName : "No file") << endl;
            cout << "\n";

            unsigned int choice = menu();

            switch (choice) {
            case 0:
                cout << "Exiting Program!" << endl;
                return;
            case 1:
                cout << "\n****List Items****\n\n";
                break;
            case 2:
                cout << "\n****Add Item****\n\n";
                break;
            case 3:
                cout << "\n****Remove Item****\n\n";
                break;
            case 4:
                cout << "\n****Update Quantity****\n\n";
                break;
            case 5:
                cout << "\n****Sort****\n\n";
                break;
            case 6:
                cout << "\n****Ship Items****\n\n";
                break;
            case 7:
                cout << "\n****New/Open Aid Database****\n\n";
                break;
            default:
                cout << "Invalid option!" << endl;
            }
        }
    }

    unsigned int AidMan::menu() {
        return mainMenu.run();
    }
    void AidMan::setEmpty()
    {
        m_fileName = nullptr;
    }
}