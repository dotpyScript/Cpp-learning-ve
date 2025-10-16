#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "Hello, world!";
    for (size_t i = 0; i < text.length(); ++i) {
    cout << "character:" << i << ": " << text[i] << endl;
    }
    return 0;
}