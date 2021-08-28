/*
ID: frankzh1
TASK: friday
LANG: C++
*/
#include <iostream>
using namespace std;

int day[8] = {0};
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int n;
    int weekday = 1;
    cin >> n;
    for (int i = 1900; i < 1900 + n; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            month[1] = 29;
        } else {
            month[1] = 28;
        }

        for (int j = 0; j < 12; j++) {
            for (int k = 1; k <= month[j]; k++) {
                if (k == 13) day[weekday]++;
                weekday++;
                if (weekday == 8) weekday = 1;
            }
        }
    }
    cout << day[6] << " " << day[7] << " ";
    for (int i = 1; i <= 5; i++) {
        cout << day[i];
        if (i == 5) cout << endl;
        else cout << " ";
    }
    return 0;
}