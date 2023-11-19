/* Final Project Milestone 2
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
namespace sdds {
    const int MAX_MENU = 15;
    class Menu {
        char* m_contentMenu{};
        unsigned int m_numOptions{};
        void setEmpty();
        bool isValid() const;
    public:
        Menu(const char* contentMenu);
        ~Menu();
        unsigned int run();
    };



}
#endif // !SDDS_MENU_H
