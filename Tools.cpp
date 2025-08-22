#include "Tools.h"
#include <iomanip>
#include <string.h>

ostream& operator<<(ostream& out, const City& city) {
    out << city.x << " " << city.y << " " << city.name;
    return out;
}

ostream& operator<<(ostream& out, const Fly& flies) {
    out << flies.city_from << " " << flies.city_to << " " << flies.duration;
    return out;
}

ostream& operator<<(ostream& out, const Trip& trips) {
    out << trips.city_from << " " << trips.city_to << " " << trips.type;
    return out;
}

Matr CreateMap(int m, int n) {
    Matr M = new short* [m];
    for (int i = 0; i < m; i++) {
        M[i] = new short[n];
    }
    return M;
}

void DeleteMap(Matr map, int m) {
    for (int i = 0; i < m; i++) {
        delete[] map[i];
    }
    delete[] map;
}

void ShowMap(Matr map, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(1) << (char)map[i][j] << " ";
        }
        cout << endl;
    }
}

void revStr(char* s) {
    int n = strlen(s);
    int i = 0;
    int j = n - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}