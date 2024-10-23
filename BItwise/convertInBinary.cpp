#include<iostream>
#include<vector>

using namespace std;

void convertToBinary(int num){
    vector<int> binary; // To store the binary representation

    if(num == 0){
        binary.push_back(0);
    } else {
        while(num > 0) {
            // Get the least significant bit (0 or 1)
            int bit = num & 1;  // num & 1 gives the rightmost bit
            binary.push_back(bit);
            num = num >> 1;  // Right shift the number to process the next bit
        }
    }

    // The binary vector now has bits in reverse order, so we need to print in reverse
    for(int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i];
    }
    cout << endl;
}

int main(){
    int n = 14;
    cout << "Binary representation of " << n << ": ";
    convertToBinary(n);  // Outputs the binary representation
    return 0;
}
