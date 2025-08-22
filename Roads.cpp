#include "Tools.h"
#include "LinkedList.h"
#include <fstream>
#include <ctype.h>

#include <iostream>
using namespace std;

void SearchForCities(Matr map, int m, int n, LinkedList<City> &cities);

int main()
{
//----------------------------------------------
   // zifstream fin("D:\\PROGRAMS\\Roads\\vlad.txt");
//----------------------------------------------

//----------------------------------------------
    int n, m;
    cin >> n >> m;
//----------------------------------------------

//----------------------------------------------
    Matr map = CreateMap(m, n);
    char* s = new char[n + 1];

    for (int i = 0; i < m; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            map[i][j] = s[j];
        }
    }
    ShowMap(map, m, n);
//----------------------------------------------

 
//----------------------------------------------
    LinkedList<City> cities;
    SearchForCities(map, m, n, cities);
    cities.show(true);
//----------------------------------------------


    DeleteMap(map, m);
    delete[] s;
    return 0;
}

void SearchForCities(Matr map, int m, int n, LinkedList<City> &cities) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '*') {
                City city;
                city.x = j;
                city.y = i;

                //boundaries for search the first or last letter in cityname
                int x1 = city.x - 1; if (x1 < 0)  x1 = 0;
                int x2 = city.x + 1; if (x2 >= n) x2 = n - 1;
                int y1 = city.y - 1; if (y1 < 0)  y1 = 0;
                int y2 = city.y + 1; if (y2 >= m) y2 = m - 1;

                //search the first or last letter in cityname
                int x = -1, y = -1; 
                bool start = true;
                for (int i1 = y1; i1 <= y2; i1++) {
                    for (int j1 = x1; j1 <= x2; j1++) {
                        if (isalpha(map[i1][j1])) {
                            y = i1;
                            x = j1;
                            if (x < n - 1) {
                                if (!isalnum(map[y][x + 1])) {
                                    start = false;
                                }
                            }
                            goto exit;
                        }
                    }
                }
            exit:

                city.name[0] = map[y][x];
                if (start) {
                    int k = 0;
                    while (x < n && isalnum(map[y][x])) {
                        k++; x++;
                        city.name[k] = map[y][x];
                    }
                    city.name[k] = 0;
                }
                else {
                    int k = 0;
                    while (x >= 0 && isalnum(map[y][x])) {
                        k++; x--;
                        city.name[k] = map[y][x];
                    }
                    city.name[k] = 0;
                    revStr(city.name);
                }

                cout << city.x << " " << city.y << " " << city.name << endl;
                cities.push_back(city);
            }
        }
    }
}
