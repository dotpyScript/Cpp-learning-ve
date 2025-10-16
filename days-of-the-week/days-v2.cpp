#include <iostream>
#include <limits>
#include <string>
#include <chrono>
#include <thread>
#include <cctype>
#include <algorithm>

using namespace std;

// function declaration;
void clearScreen();
void pauseScreen();
void loadingAnimation(const string &message, int dots, int delay);
string toUppercase(string text);
string toSentenceCase(string text);
string welcomeMessage();
int getDayInput(int day);
void displayDayInfo(int day, int delay);

