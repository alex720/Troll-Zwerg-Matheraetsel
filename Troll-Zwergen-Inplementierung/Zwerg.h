#pragma once
#include <vector>

enum Colors {
	yellow = 0,
	blue,
	lightblue,
	darkblue,
	gray,
	green,
	lightgreen,
	darkgreen,
	black,
	white,
	pink,
	red,
	gold,
	silver
};



class Zwerg
{
public:
	Zwerg(int hatcolor);
	~Zwerg();

	int getColor();

	int answer(std::vector<Zwerg> &list, std::vector<int> &lastAnswers, int &numberOfColors);

private:

	int color;

};

