#include <iostream>
#include <string>
using namespace std;

int main() {
    int batteryLevel, altitude, signalStrength;

    do {
        cout << "\nEnter battery level (-1 to exit): ";
        cin >> batteryLevel;

        if (batteryLevel == -1) {
            cout << "Shutting down drone monitor...\n";
            break;
        }

        cout << "Enter altitude: ";
        cin >> altitude;

        cout << "Enter signal strength: ";
        cin >> signalStrength;

        string status = "";

        status += (batteryLevel >= 80) ? "Battery ✅ " :
                  (batteryLevel >= 30) ? "Battery ⚠️ " : "Battery 🔻 ";

        status += (altitude >= 80) ? "Altitude ✅ " :
                  (altitude >= 30) ? "Altitude ⚠️ " : "Altitude 🔻 ";

        status += (signalStrength >= 80) ? "Signal ✅" :
                  (signalStrength >= 30) ? "Signal ⚠️" : "Signal 🔻";

        cout << "\n📡 Drone Status: " << status << endl;

    } while (true);

    return 0;
}
