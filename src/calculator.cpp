/*
 * Name: Justin Guida 
 * Date: 03/23/2025
 * Description: This program evaluates expressions from user input + - * /
 *              Input read as string, parsed with stringstream, then calculated
 *  What I fixed:
 *  - Used getline() with stringstream to allow full input like "2 + 2"
 *  - Used double instead of int so it handles decimals too
 *  - Catches invalid input like letters or missing values
 *  - Checks for division by zero
 *  - Loop works clean using Y or y, and input buffer is cleared properly
 *  - Changed void main() to int main() � main always needs to return an int
 *  - Used single quotes for char ('Y' instead of "Y") � double quotes are strings
 *  - Fixed semicolons after if statements � they were breaking the logic flow
 *  - Corrected the order of operands � was backwards
 *  - Fixed wrong shift operators � used >> instead of <<
 *  - Fixed math operators being swapped (like printing * for /)
 *  - Added missing semicolons
 *  - Made it loop correctly based on Y/y
 */

#include <iostream>
#include <sstream>  // For parsing input
#include <limits>   // For clearing input buffer
using namespace std;

int main() {
    string input;  // This was implemented to store input into string.
    double op1, op2; // 
    char operation;
    char answer = 'Y';
    
    while (answer == 'Y' || answer == 'y') {
        cout << "Enter expression (etc 2 + 2):" << endl;
        getline(cin, input);  // Read the entire input line

        // Convert input string to a stream for parsing
        stringstream ss(input);

        // Try to extract values correctly
        if (!(ss >> op1 >> operation >> op2) || !ss.eof()) {
            cout << "Error: Invalid input. (Please enter + - * /)" << endl;
            continue; // Restart loop
        }

        // Perform calculations using if else statements
        if (operation == '+') {
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
        }
        else if (operation == '-') {
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
        }
        else if (operation == '*') {
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        }

        else if (operation == '/') { // Division by 0 error
            if (op2 == 0) {
                cout << "Error: Division by zero is undefined." << endl;
            }
            else {
                cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
            }

        }
        else {
            cout << "Error: You must use a valid operator (+, -, /, *)." << endl; //Checks for proper operator
            continue;
        }

        // Asks the user to evaluate another expression and outputs to screen.
        do {
            cout << "Do you wish to evaluate another expression? (Y/N)" << endl;
            cin >> answer;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer. So whitespaces don't cause errors

        } while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

        if (answer == 'N' || answer == 'n') {
            cout << "Program closing." << endl;
            break;
        }
    }
    return 0;
}
