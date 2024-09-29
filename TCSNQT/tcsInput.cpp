#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<float> f;     // Vector to store floats
    vector<string> s;    // Vector to store strings
    vector<int> v;       // Vector to store integers

    // Example input string
    string input_data = "3.14,hello,42;2.71,world,24;5.78,earth,78;";

    // Use stringstream to split the input_data by the ';' delimiter
    stringstream ss(input_data);
    string entry;

    while (getline(ss, entry, ';')) {  // split by ';'
        stringstream entryStream(entry);
        string fo, so, integer;

        // Split the entry by ','
        getline(entryStream, fo, ',');
        f.push_back(stof(fo));  // Convert string to float and store in vector f

        getline(entryStream, so, ',');
        s.push_back(so);  // Store string in vector s

        getline(entryStream, integer, ',');
        v.push_back(stoi(integer));  // Convert string to int and store in vector v
    }

    // Output the stored values to verify
    for (int i = 0; i < v.size(); i++) {
        cout << "Float: " << f[i] << " String: " << s[i] << " Integer: " << v[i] << endl;
    }

    return 0;
}
