#pragma once
#include <string>


enum Colors {
	yellow = 1,
	darkyellow,
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
	lightred,
	darkred,
	red,
	gold,
	silver

};

std::string getStringOfColor(int colorNumber) {


	switch (colorNumber)
	{
		case yellow: return std::string("yellow");
		case darkyellow:return std::string("darkyellow");
		case blue:return std::string("blue");
		case lightblue:return std::string("lightblue");
		case darkblue:return std::string("darkblue");
		case gray:return std::string("gray");
		case green:return std::string("green");
		case lightgreen:return std::string("lightgreen");
		case darkgreen:return std::string("darkgreen");
		case black:return std::string("black");
		case white:return std::string("white");
		case pink:return std::string("pink");
		case lightred:return std::string("lightred");
		case darkred:return std::string("darkred");
		case red:return std::string("red");
		case gold:return std::string("gold");
		case silver:return std::string("silver");
	default:
		return std::to_string(colorNumber);
		break;
	}

}