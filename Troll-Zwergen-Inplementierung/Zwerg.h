#pragma once
#include <vector>




class Zwerg
{
public:
	Zwerg(int hatcolor);
	~Zwerg();

	int getColor();

	int answer(std::vector<Zwerg> &list, std::vector<int> &lastAnswers, int &numberOfColors,int debug);

private:

	int color;

};

