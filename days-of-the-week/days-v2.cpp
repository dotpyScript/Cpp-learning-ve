#include <algorithm>
#include <cctype>
#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <thread>

using namespace std;

// function declaration;
void clearScreen();
void pauseScreen();
void loadingAnimation(const string &message, int dots, int delay);
string toUppercase(string text);
string toSentencecase(string text);
string welcomeMessage();
int getDayInput(int day);
void displayDayInfo(int day, int delay);

// function definitions;
void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void pauseScreen() {
  cout << "\n\033[33mPress enter to continue\033[0m";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cin.get();
  cout << "Returning to main menu...\n";
}

void loadingAnimation(const string &message, int dots = 5, int delay = 300) {
  cout << message;
  for (int i = 0; i < dots; ++i) {
    cout << ".";
    cout.flush();
    this_thread::sleep_for(chrono::milliseconds(delay));
  }
  cout << "\n";
}

string toUppercase(string text) {
  transform(text.begin(), text.end(), text.begin(), ::toupper);
  return text;
}

string toSentencecase(string text) {
  if (!text.empty()) {
    text[0] = toupper(text[0]);
  }
  return text;
}
string welcomeMessage() {
  string message = R"(
 __        __   _                            _          _   _                 
 \ \      / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |_| |__   ___        
  \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  | __| '_ \ / _ \       
   \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |_| | | |  __/       
    \_/\_/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/   \__|_| |_|\___|       
                                                                               
  ____                  _       _     _                 _                    
 |  _ \  ___  ___ _   _| |_ ___| |__ (_) ___  ___      / \   _ __  _ __     
 | | | |/ _ \/ __| | | | __/ __| '_ \| |/ _ \/ __|    / _ \ | '_ \| '_ \    
 | |_| |  __/ (__| |_| | || (__| | | | |  __/\__ \   / ___ \| |_) | |_) |   
 |____/ \___|\___|\__,_|\__\___|_| |_|_|\___||___/  /_/   \_\ .__/| .__/    
                                                           |_|   |_|       
)";
  return message;
}
