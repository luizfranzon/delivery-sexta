#ifndef RESTAURANT_DELIVERY_SYSTEM_MENUS_H
#define RESTAURANT_DELIVERY_SYSTEM_MENUS_H

enum SubMenus {
    SUBMENU_ORDERS,
};

enum MainMenuChoices {
    INVALID_MAIN_MENU_CHOICE = -1,
    ORDERS = 1,
    STATISTICS = 2,
    EXPORT_TO_CSV = 3,
    QUIT = 0,
};

void printLogo();

void presentMainMenu();

void presentSubMenu(enum SubMenus menu);

enum MainMenuChoices mainMenuGetChoice();

#endif
