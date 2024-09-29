#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;  // Input string with numbers inside brackets, separated by commas
    vector<int> arr;
    string temp = "";

    for (auto c : s) {
        if (isdigit(c) || c == '-') {  // Check for digits or negative sign
            temp += c;  // Append character to temp if it's part of the number
        } else if (c == ',') {
            if (!temp.empty()) {
                arr.push_back(stoi(temp));  // Convert temp to an integer and push to array
                temp = "";  // Clear temp for the next number
            }
        }
    }

    // Handle the last number (since input might not end with a comma)
    if (!temp.empty()) {
        arr.push_back(stoi(temp));
    }

    // Print the resulting integers
    for (auto x : arr) {
        cout << x << endl;
    }

    return 0;
}
