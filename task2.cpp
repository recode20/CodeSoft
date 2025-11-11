// simple_calculator.cpp
// Simple Calculator: addition, subtraction, multiplication, division
#include <iostream>
#include <limits>   // for std::numeric_limits
using namespace std;

double getNumber(const string &prompt) {
    double num;
    while (true) {
        cout << prompt;
        if (cin >> num) return num;
        // invalid input
        cout << "❌ Invalid number. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char getOperation() {
    char op;
    while (true) {
        cout << "Choose operation (+ - * /): ";
        cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '/') return op;
        cout << "❌ Invalid operation. Please enter one of +, -, *, /.\n";
    }
}

int main() {
    cout << "=== Simple Calculator ===\n\n";
    bool again = true;
    while (again) {
        double a = getNumber("Enter first number: ");
        double b = getNumber("Enter second number: ");
        char op = getOperation();

        cout << "\nResult: ";
        if (op == '+') cout << (a + b) << '\n';
        else if (op == '-') cout << (a - b) << '\n';
        else if (op == '*') cout << (a * b) << '\n';
        else { // division
            if (b == 0) cout << "Error: Division by zero is not allowed.\n";
            else cout << (a / b) << '\n';
        }

        // Play again?
        cout << "\nDo another calculation? (y/n): ";
        char r; cin >> r;
        if (r != 'y' && r != 'Y') again = false;
        cout << '\n';
    }

    cout << "Thanks for using the calculator. 👋\n";
    return 0;
}
