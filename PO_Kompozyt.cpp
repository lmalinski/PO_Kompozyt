#include <iostream>
#include <memory>
#include "Postac.h"
#include "Pomieszczenie.h"

int main()
{
	Postac bohater;
	
	//Tworzenie lochu:
	CiagPomieszczen Loch;
	Loch.dodaj(std::make_unique<Skarbiec>());
	Loch.dodaj(std::make_unique<Pulapka>());
	
	auto rozwidlenie = std::make_unique<Rozwidlenie>();
	rozwidlenie->dodaj(std::make_unique<Skarbiec>());
	rozwidlenie->dodaj(std::make_unique<Pulapka>());
	rozwidlenie->dodaj(std::make_unique<Pulapka>());
	
	auto korytarz = std::make_unique<CiagPomieszczen>();
	korytarz->dodaj(std::make_unique<Skarbiec>());
	korytarz->dodaj(std::make_unique<Pulapka>());
	korytarz->dodaj(std::make_unique<Pulapka>());
	rozwidlenie->dodaj(std::move(korytarz));
	Loch.dodaj(std::move(rozwidlenie));

	Loch.dodaj(std::make_unique<Skarbiec>());
	Loch.dodaj(std::make_unique<Pulapka>());

	//Exploracja lochu:
	try
	{
		Loch.zbadaj(bohater);
		std::cout << "Dotarles do konca!" << std::endl;
	}
	catch (std::domain_error event)
	{
		std::cout << event.what() << std::endl;
	}
	std::cout << bohater << std::endl;
}


