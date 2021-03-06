// Troll-Zwergen-Inplementierung.cpp: Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include <vector>
#include "Zwerg.h"
#include <iostream>
#include "randomer.h"
#include <string>
#include "Color.h"


int deaths = 0;
int lives = 0;





std::string getOutputString(Zwerg zwerg, int answer) {


	std::string buffer;
	buffer += "Zwerg: Ich sage meine Hutfarbe ist: ";
	buffer += getStringOfColor(answer);
	buffer += "\n";


	if (answer == zwerg.getColor()) {
		buffer += "Trollk�nig: Du hast recht du darfst Leben";
		buffer += "\n";
		lives++;
	}
	else {
		buffer += "Trollk�nig: Du liegst falsch und jetzt stirb";
		buffer += "\n";
		deaths++;
	}
	return buffer;
}



int main()
{
	initrandomer();
	std::vector<Zwerg> Zwerge;
	int numberOfZwerge = 0;
	int numberOfColors = 0;
	int debug = 0;

	std::cout << "sollen mehr informationen angezeigt werden(wenn ja 1 | wenn nein 0): ";
	std::cin >> debug;
	std::cout << std::endl;
	
	std::cout << "gebe Anzahl an Zwerge an die um ihr Leben spielen: ";
	std::cin >> numberOfZwerge;
	std::cout << std::endl;

	std::cout << "gebe Anzahl an verschiedenen Hutfarben an (Wenn zu viele Hutfarben angegeben sind wird die farbe nur als zahl angezeigt): ";
	std::cin >> numberOfColors;
	std::cout << std::endl;
	
	
	
	for (int i = 1; i <= numberOfZwerge; i++) {
		Zwerge.push_back(std::move(Zwerg(getRandomValueunder(numberOfColors)+1)));
	}
		
	std::vector<int> lastAnswers;
	
	int i = 0;
	for (std::vector<Zwerg>::iterator it = Zwerge.begin(); it != Zwerge.end(); it++) { //nacheinander alle zwerge durchgehen
		Zwerg zwergNeedToGiveAnAnswer = *(Zwerge.begin() + i); 

		std::vector<Zwerg> ZwergeAfterMe;
		for (std::vector<Zwerg>::iterator itt = Zwerge.begin() + i + 1; itt != Zwerge.end(); itt++) { // alle zwerge vor mir in den container ZwergeAfterMe
			ZwergeAfterMe.push_back(*(itt));
		}
		
		lastAnswers.push_back( zwergNeedToGiveAnAnswer.answer(ZwergeAfterMe, lastAnswers, numberOfColors,debug));

		std::cout << getOutputString(zwergNeedToGiveAnAnswer, *(lastAnswers.end() - 1)) <<std::endl;
		
		i++;
	}
	
	
	std::cout << " anzahl an durchg�gen: " << i << std::endl;

	std::cout << "so viele sind gestroben: " << deaths << std::endl;
	std::cout << "so viele haben �berebt: " << lives << std::endl;
	char k;
	std::cin >> k;

	destroyrandomer();
    return 0;
}


