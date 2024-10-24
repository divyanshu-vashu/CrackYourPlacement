#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// Mapping words to their corresponding digits
unordered_map<string, int> wordToDigit = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

// Mapping operations to their functions
unordered_map<string, char> operations = {
    {"add", '+'}, {"sub", '-'}, {"mul", '*'}, {"div", '/'}, {"rem", '%'}, {"pow", '^'}
};

// Function to convert word to number, including cases with 'c' (like oneconecone)
bool wordToNumber(const string& word, int& result) {
    stringstream ss(word);
    string part;
    result = 0;
    
    // Separate the parts by 'c'
    while (getline(ss, part, 'c')) {
        if (wordToDigit.find(part) == wordToDigit.end()) {
            return false; // Invalid word found
        }
        result = result * 10 + wordToDigit[part];
    }
    
    return true;
}

// Function to evaluate an expression
int evaluate(int num1, int num2, char operation) {
    switch (operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 == 0) {
                cout << "Error: Division by zero" << endl;
                exit(1);
            }
            return num1 / num2; // assuming valid division
        case '%': 
            if (num2 == 0) {
                cout << "Error: Modulus by zero" << endl;
                exit(1);
            }
            return num1 % num2;
        case '^': return pow(num1, num2); // pow returns double, but we can handle this as int
        default: return 0;
    }
}

// Main function to evaluate the expression
void evaluateExpression(const string& input) {
    stringstream ss(input);
    string token;
    vector<string> tokens;
    
    // Tokenize the input
    while (ss >> token) {
        tokens.push_back(token);
    }
    
    vector<int> operands;
    vector<char> ops;
    
    // Parse the tokens
    for (size_t i = 0; i < tokens.size(); ++i) {
        // If it's an operation
        if (operations.find(tokens[i]) != operations.end()) {
            ops.push_back(operations[tokens[i]]);
        }
        // If it's a number word
        else {
            int number;
            if (wordToNumber(tokens[i], number)) {
                operands.push_back(number);
            } else {
                cout << "Expression evaluation stopped: invalid words present" << endl;
                return;
            }
        }
    }
    
    // Now, evaluate based on the operations and operands
    if (ops.empty() || operands.size() < 2) {
        cout << "Expression is not complete or invalid" << endl;
        return;
    }
    
    // Start evaluation
    int result = operands[0];
    size_t opIndex = 0;
    
    for (size_t i = 1; i < operands.size(); ++i) {
        if (opIndex >= ops.size()) {
            cout << "Expression is not complete or invalid" << endl;
            return;
        }
        
        result = evaluate(result, operands[i], ops[opIndex]);
        ++opIndex;
    }
    
    cout << result;
}

int main() {
    string input;
    getline(cin, input);
    
    evaluateExpression(input);
    
    return 0;
}
