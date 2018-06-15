// Troll-Zwergen-Inplementierung.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <vector>
#include "Zwerg.h"
#include <iostream>
#include "randomer.h"




int main()
{
	initrandomer();
	std::vector<Zwerg> Zwerge;
	int numberOfZwerge = 0;
	int numberOfColors = 0;
	
	std::cout << "gebe Anzahl an Zwerge an die um ihr Leben spielen: ";
	std::cin >> numberOfZwerge;
	std::cout << std::endl;

	std::cout << "gebe Anzahl an verschiedenen Hutfarben an : ";
	std::cin >> numberOfColors;
	std::cout << std::endl;
	
	int deaths = 0;
	int lives = 0;
	
	for (int i = 1; i <= numberOfZwerge; i++) {
		Zwerge.push_back(std::move(Zwerg(getRandomValueunder(numberOfColors)+1)));
	}
		
	std::vector<int> lastAnswers;
	
	int i = 0;
	for (auto it = Zwerge.begin(); it != Zwerge.end(); it++) { //nacheinander alle zwerge durchgehen
		Zwerg zwergNeedToGiveAnAnswer = *(Zwerge.begin() + i); 

		std::vector<Zwerg> ZwergeAfterMe;
		for (auto itt = Zwerge.begin() + i + 1; itt != Zwerge.end(); itt++) { // alle zwerge vor mir in den container ZwergeAfterMe
			ZwergeAfterMe.push_back(*(itt));
		}
		
		lastAnswers.push_back( zwergNeedToGiveAnAnswer.answer(ZwergeAfterMe, lastAnswers, numberOfColors));
		
		std::cout << "Ich sage meine Hutfarbe ist: " << *(lastAnswers.end()-1) << " | " << "Meine echte Hutfarbe ist aber " << zwergNeedToGiveAnAnswer.getColor();

		if (*(lastAnswers.end() - 1) == zwergNeedToGiveAnAnswer.getColor()) {
			std::cout << "  Ja ich darf leben" << std::endl;
			lives++;
		}
		else {
			std::cout << "  oh nein ich werde sterben" << std::endl;
			deaths++;
		}
		i++;
	}
	
	
	std::cout << " anzahl an durchgägen: " << i << std::endl;

	std::cout << "so viele sind gestroben: " << deaths << std::endl;
	std::cout << "so viele haben überebt: " << lives << std::endl;
	char k;
	std::cin >> k;

	destroyrandomer();
    return 0;
}

