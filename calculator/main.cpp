#include <iostream>
#include <string>
#include "calc_engine.hpp"

int main() {
    std::cout << "C++ Calculator (type 'exit' to quit)\n";
    std::string line;
    double last = 0.0; // remembers last answer
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;
        if (line == "exit") break;
        // Allow using 'ans' in expressions
        for (size_t pos = 0; (pos = line.find("ans", pos)) != std::string::npos; ) {
            line.replace(pos, 3, std::to_string(last));
            pos += 1;
        }
        try {
            double result = calc::evaluate(line);
            last = result;
            std::cout << "= " << result << "\n";
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}
