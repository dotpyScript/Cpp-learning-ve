// filepath: test_curl.cpp
#include <curl/curl.h>
#include <iostream>
#include <string>

// Callback function to handle response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    userp->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Function to fetch GitHub user information
void fetchGitHubUser(const std::string& username) {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        // Construct the URL for the user
        std::string url = "https://api.github.com/users/" + username;
        
        // Set URL and headers
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "MyGitHubApp/1.0");
        
        // Skip SSL verification (Note: This is not recommended for production use)
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        
        // Set callback function to handle response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform request
        CURLcode res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "User information for " << username << ":\n" << response << std::endl;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
}

int main() {
    std::string username;
    std::cout << "Enter a GitHub username to fetch information: ";
    std::getline(std::cin, username);
    
    fetchGitHubUser(username);
    return 0;
}
