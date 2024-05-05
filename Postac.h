#pragma once

#include <iostream>

class Postac
{
private:
	static const int s_MAX_ZDROWIE = 10;
	int m_zdrowie = s_MAX_ZDROWIE;
	int m_lupy = 0;
public:
	void dodajLupy(int wart) { m_lupy += wart; }
	void zadajRane(int liczba) { m_zdrowie-=liczba; }
	bool czyZywy() const { return m_zdrowie > 0; }
	friend std::ostream& operator<<(std::ostream& str, const Postac& postac)
	{
		str << "Zdrowie: " << postac.m_zdrowie
			<< " Lupy: " << postac.m_lupy;
		return str;
	}
};

