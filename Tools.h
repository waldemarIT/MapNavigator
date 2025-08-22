#pragma once

#include <iostream>
#include "LinkedList.h"
using namespace std;
#define NAME_LEN 150

struct City {
	short x, y;
	//char name[150];
	Name name;
};
ostream& operator<<(ostream& out, const City& city);


struct Fly {
	Name city_from;
	Name city_to;
	int duration;
};
ostream& operator<<(ostream& out, const Fly& fly);

struct Trip {
	Name city_from;
	Name city_to;
	int type; // 0 or 1
};
ostream& operator<<(ostream& out, const Trip& fly);


typedef short** Matr;

Matr CreateMap(int m, int n);
void DeleteMap(Matr map, int m);
void ShowMap(Matr map, int m, int n);
void revStr(char *s);
