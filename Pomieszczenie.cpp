#include "Pomieszczenie.h"

Skarbiec::Skarbiec()
{
	std::random_device rng;
	std::uniform_int_distribution<int> zakres(1, 10);
	m_skarb = zakres(rng);
}

void Skarbiec::zbadaj(Postac& postac) const
{
	std::cout << "Skarbiec" << std::endl;
	postac.dodajLupy(m_skarb);
	std::cout << postac << std::endl;
}

void Pulapka::zbadaj(Postac& postac) const
{
	std::cout << "Pulapka!" << std::endl;
	std::random_device rng;
	std::bernoulli_distribution szansa(0.5);
	std::uniform_int_distribution<int> rana(1, 5);
	if (szansa(rng) < 0.5)
		postac.zadajRane(rana(rng));
	if (postac.czyZywy() == false) 
		throw std::domain_error("Jestes Martwy!");
	std::cout << postac << std::endl;
}

void CiagPomieszczen::zbadaj(Postac& postac) const
{
	std::cout << "Ciag Pomieszczen" << std::endl;
	for (int pom = 0; pom < m_pomieszczenia.size(); pom++)
	{
		char odp;
		std::cout << "Czy idziesz dalej? "; std::cin >> odp;
		getchar();
		switch (odp)
		{
		case 't':
		case 'T':
			m_pomieszczenia[pom]->zbadaj(postac);
			break;
		case 'n':
		case 'N':
		default:
			throw std::domain_error("Wycofales sie!");
		}

	}
}

void CiagPomieszczen::dodaj(std::unique_ptr<Pomieszczenie> &&pomieszczenie)
{
	m_pomieszczenia.push_back(std::move(pomieszczenie));
}

void Rozwidlenie::zbadaj(Postac& postac) const
{
	std::cout << "Rozwidlenie" << std::endl;
	int odp;
	do
	{
		std::cout << "Wybierz droge [1-" << m_pomieszczenia.size() << "]: ";
		std::cin >> odp;
	} while (odp < 1 || m_pomieszczenia.size() < odp);
	m_pomieszczenia[odp - 1]->zbadaj(postac);
}

void Rozwidlenie::dodaj(std::unique_ptr<Pomieszczenie> &&pomieszczenie)
{
	m_pomieszczenia.push_back(std::move(pomieszczenie));
}
