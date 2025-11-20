#ifndef RESTAURANT_DELIVERY_SYSTEM_MENUS_H
#define RESTAURANT_DELIVERY_SYSTEM_MENUS_H

enum MenuType {
    SUBMENU_ORDERS,
};

void printLogo();

void presentMainMenu();

void presentSubMenu(enum MenuType menu);

#endif //RESTAURANT_DELIVERY_SYSTEM_MENUS_H
