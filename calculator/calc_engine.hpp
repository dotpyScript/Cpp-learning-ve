#pragma once
#include <string>
#include <string_view>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <cmath>

namespace calc {

    inline int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    inline void apply_op (std::vector<double>& vals, std::vector<char>& ops) {
        if (vals.size() < 2 || ops.empty()) throw std::runtime_error("Malformed expression");
        double b = vals.back();
        vals.pop_back();
        double a = vals.back();
        vals.pop_back();
        char op = ops.back();
        ops.pop_back();
        double r = 0.0;

        switch (op) {
            case '+': r = a + b;
            break;
            case '-': r = a - b;
            break;
            case '*': r = a * b;
            break;
            case '/': 
            if (b == 0.0) throw std::runtime_error("Division by zero");
            r = a / b; break;

            default: throw std::runtime_error("Unknown operator");
        }
        vals.push_back(r);
    }

    inline double evaluate(std::string_view expr_sv) {
        // tokenize and evaluate two stacks (shunting-yard style)
        std::string expr(expr_sv); // make a copy for safe indexing
        std::vector<double>vals; vals.reserve(32);
        std::vector<char> ops; ops.reserve(32);

        auto push_number = [&](size_t& i) {
            size_t j = i;
            bool dot = false;
            while (j < expr.size() && (std::isdigit((unsigned char) expr[j]) || expr[j]=='.')) {
                if (expr[j]=='.') {
                    if (dot) break;
                    dot = true;
                }
                ++j;
            }
            if (j == i) throw std::runtime_error("Number expected");
            double v = std::stod(expr.substr(i, j - i));
            vals.push_back(v);
            i = j;
        };

        // Support unary minus by converting "-x" to "0 - x" when appropriate
        auto is_unary_minus = [&](size_t i)-> bool {
            if (expr[i] != '-') return false;
            // start of string or previous significant char is '(' or operator
            size_t k = i;
            while (k>0) return true;
            char p = expr[k-1];
            return (p=='(' || p=='+' || p=='-' || p=='*' || p=='/');
        };

        for (size_t i = 0; i < expr.size();) {
            if (std::isspace((unsigned char)expr[i])) {i++; continue;}

            if (std::isdigit((unsigned char)expr[i]) || expr[i] == '.') {
                push_number(i);
                continue;
            }
            
            if (expr[i] == '(') {
                ops.push_back('(');
                ++i;
                continue;
            }

            if (expr[i] == ')') {
                while (!ops.empty() && ops.back() != '(') apply_op(vals, ops);
                if (ops.empty() || ops.back() != '(') throw std::runtime_error("Mismatch parenthesis");
                    ++i;
                continue;
            }

            if (expr[i] == '+' || expr[i]=='-' || expr[i] =='*' || expr[i] == '/') {
                if (is_unary_minus(i)) {
                    // treat as 0 - (...)
                    vals.push_back(0.0);
                }
                char op = expr[i];
                while (!ops.empty() && ops.back() != '(' && prec(ops.back()) >= prec(op)) {
                    apply_op(vals, ops);
                }
                ops.push_back(op);
                ++i;
                continue;
            }
            
            throw std::runtime_error(std::string("Unexpected character: ") + expr[i]);
        }

        while (!ops.empty()) {
            if (ops.back() == '(') throw std::runtime_error("Mismatched parenthesis");
            apply_op(vals, ops);
        }
        if (vals.size() != 1) throw std::runtime_error("Malformed expression");
        return vals.back();
    }

} // namespace calc