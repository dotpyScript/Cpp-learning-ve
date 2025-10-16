#include <iostream>
using namespace std;

int main() {
    int batteryLevel;
    cout << "Enter the battery level (%): ";
    cin >> batteryLevel;

    if (batteryLevel >= 80) {
         cout << "🔋 Battery is full!" << endl;
    } else if (batteryLevel >= 30) {
         cout << "🟡 Battery is OK." << endl;;
    } else {
          cout << "🔴 Warning! Low Battery!" << endl;
    };
    return 0;
};
