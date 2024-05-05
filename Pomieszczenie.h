#pragma once
#include <random>
#include "Postac.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <memory>

class Pomieszczenie
{
public:
	virtual void zbadaj(Postac& postac) const = 0;
};

class Skarbiec : public Pomieszczenie
{
private:
	int m_skarb;
public:
	Skarbiec();
	void zbadaj(Postac& postac) const override;
};

class Pulapka : public Pomieszczenie
{
public:
	void zbadaj(Postac& postac) const override;
};

class CiagPomieszczen : public Pomieszczenie
{
private:
	std::vector<std::unique_ptr<Pomieszczenie>> m_pomieszczenia;
public:
	void zbadaj(Postac& postac) const override;
	void dodaj(std::unique_ptr<Pomieszczenie> &&pomieszczenie);
};

class Rozwidlenie : public Pomieszczenie
{
private:
	std::vector<std::unique_ptr<Pomieszczenie>> m_pomieszczenia;
public:
	void zbadaj(Postac& postac) const override;
	void dodaj(std::unique_ptr<Pomieszczenie> &&pomieszczenie);
};


