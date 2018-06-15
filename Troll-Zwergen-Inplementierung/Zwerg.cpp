#include "stdafx.h"
#include "Zwerg.h"
#include <iostream>

Zwerg::Zwerg(int hatcolor) : color(hatcolor){}


Zwerg::~Zwerg(){}

int Zwerg::getColor()
{
	return color;
}

int Zwerg::answer(std::vector<Zwerg> &list, std::vector<int> &lastAnswers,int &numberOfColors,int debug)
{
	int allNumbers = 0; // alle hüte zusammengezählt, die ich sehe
	for (auto it = list.begin(); it != list.end(); it++) {
		allNumbers += it->getColor();
	}

	if(debug) std::cout << "allNumbers:" << allNumbers << std::endl;

	if (lastAnswers.empty()) { // ich bin der erste zwerg in der reihe
		int buf = allNumbers % numberOfColors;
		if (buf == 0) return numberOfColors;
		return buf;
	}

	//all numbers (des erste Zwerges) mod numberOfColors = x
	// x  =  (allnumbers + sumOfAnswers + y) mod numberOfColors  --> y = mycolor

	int sumOfAnswers = 0; // summe aller antworten ohne die erste antwort

	for (auto it = lastAnswers.begin() + 1; it != lastAnswers.end(); it++) {
		sumOfAnswers += *(it);
	}

	if (debug) std::cout << "sumOfAnswers:" << sumOfAnswers << std::endl;

	for (int i = 1;; i++){

		int buf = *(lastAnswers.begin());
		if (buf == numberOfColors) buf = 0;

		if (buf == (allNumbers + sumOfAnswers + i) % numberOfColors) {
			return i;
		}
	}

}
