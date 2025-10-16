#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

vector<string> tokenize(const string &expr) {
    vector<string> tokens;
    string num;

    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];
        
        if (isspace(c)) continue;
        if (isdigit(c)) {
            num += c;
            while (i + 1 < expr.size() && isdigit(expr[i + 1])) {
                num += expr[++i];
            }
            tokens.push_back(num);
            num.clear();
        } else {
            tokens.push_back(string(1, c));
        }
    }

    // show tokens
    cout << "🔹 Tokens: ";
    for (const auto &t : tokens) cout << t << " ";
    cout << endl;
    return tokens;
}

//----------------shunting yard------------
vector<string> infixToPostfix(const vector<string> &tokens) {
    vector<string> output;
    stack<string> opstack;

    // operator precedence
    map<string, int> prec 
}



int main() {
    string expr = "3 + 5 * (2 - 8)";
    cout << "expr: " << expr << endl;
    
    vector<string> tokens = tokenize(expr);
    
    cout << "Tokenization complete." << endl;
    return 0;
}