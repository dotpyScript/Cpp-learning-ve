
#include <curl/curl.h>
#include <iostream>

int main() {
    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}


// // main.cpp
// #include <iostream>
// #include "sensor.h"

// int main() {
//     std::cout << "🚨 IoT Gas Sensor System Starting...\n";

//     int gasValue = readGasSensor();
//     std::cout << "Gas Sensor Reading: " << gasValue << "%\n";

//     if (gasValue > 70) {
//         std::cout << "⚠️  High gas level detected! Take immediate action.\n";
//     } else {
//         std::cout << "✅ Gas level normal.\n";
//     }

//     return 0;
// }
