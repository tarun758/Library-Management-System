#pragma once
#include <cstdint>
class Menus
{
public:
	static uint16_t mainMenu();
	static uint16_t	manageBooksMenu();
	static uint16_t	managePatronsMenu();
private:
	Menus() = delete;
	Menus(const Menus &Menus) = delete;
};

