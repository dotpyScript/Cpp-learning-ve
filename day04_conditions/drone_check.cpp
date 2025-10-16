#include <iostream>
using namespace std;

int main() {
    int batteryLevel;
    float altitude;
    int signalStrength;

    string RED = "\033[31m";
    string GREEN = "\033[32m";
    string YELLOW = "\033[33m";
    string RESET = "\033[0m";

    bool droneStatus = true;

    cout << "Enter the battery level (%): ";
    cin >> batteryLevel;

    cout << "Enter the altitude (meters): ";
    cin >> altitude;

    cout << "Enter the signal strength (%): ";
    cin >> signalStrength;

    cout << "\n==== Drone Warning ======\n";

    if (batteryLevel < 30) {
        cout << RED << "⚠️ Battery Low!" << RESET << endl;
        droneStatus = false;
    } else if (batteryLevel >= 80) {
        cout << GREEN << "🔋 Battery is full!" << RESET << endl;
    } else {
        cout << YELLOW << "🟡 Battery is OK." << RESET << endl;
    }
    
    if (altitude > 120) {
        cout << RED << "🚁 Warning! Altitude too high!" << RESET << endl;
        droneStatus = false;
    } else if (altitude < 30) {
        cout << RED << "🚁 Warning! Altitude too low!" << RESET << endl;
        droneStatus = false;
    } else {
        cout << GREEN << "🚁 Altitude is within safe limits." << RESET << endl;
    }
    
    if (signalStrength < 20) {
        cout << RED << "📶 Warning! Weak Signal detected!" << RESET << endl;
        droneStatus = false;
    } else if (signalStrength >= 80) {
        cout << GREEN << "📶 Signal strength is good!" << RESET << endl;
    } else {
        cout << YELLOW << "📶 Signal strength is OK." << RESET << endl;
    }

    if (!droneStatus) {
        cout << RED << "\n🚨 Drone is in an unsafe state! Please check all warnings." << RESET << endl;
    }

    return 0;
}