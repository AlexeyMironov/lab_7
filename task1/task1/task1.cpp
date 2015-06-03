// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "FindMax.h"
#include <string>

using namespace std;

struct Sportsman
{
	string name;
	int height; 
	int weight;
};


int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
{
	vector<int> a = { 1, 4, -2, 0, 12, -6 };
	int max;
	assert(FindMax(a, max));
	assert(max == 12);

	vector<string> strings = { "cat", "dog", "apple", "cow" };
	string maxString;
	assert(FindMax(strings, maxString));
	assert(maxString == "dog");


	vector<Sportsman> sportsmans = {
		{ "Ivan Petrov", 100, 150 },
		{ "Eugene Dolgushev", 87, 188 },
		{ "Vladimir Alitov", 62, 175 },
	};
	Sportsman tallestSportsman;
	assert(FindMax(sportsmans, tallestSportsman, [](Sportsman const& a, Sportsman const& b){
		return a.height < b.height;		
	}));
	assert(tallestSportsman.name == "Eugene Dolgushev");
	Sportsman lightestSportsman;
	assert(FindMax(sportsmans, lightestSportsman, [](Sportsman const& a, Sportsman const& b){
		return a.weight > b.weight;
	}));
	assert(lightestSportsman.name == "Vladimir Alitov");
	return 0;
}