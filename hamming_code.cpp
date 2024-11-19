#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int calculateParity(vector<int>& hammingCode, int position, int length) {
    int parity = 0;
    for (int i = position; i <= length; i += 2 * position) {
        for (int j = i; j < i + position && j <= length; j++) {
            parity ^= hammingCode[j];
        }
    }
    return parity;
}

int main() {
    int m, r = 0;
    string dataBits;
    
    cout << "Enter the bit size for the data: ";
    cin >> m;
    cout << "Enter the Data bits: ";
    cin >> dataBits;
    
    // Calculate the number of parity bits required
    while (pow(2, r) < (m + r + 1)) {
        r++;
    }
    
    int totalBits = m + r;
    vector<int> hammingCode(totalBits + 1, 0);
    
    // Place data bits into hamming code
    int j = 0;
    for (int i = 1; i <= totalBits; i++) {
        if ((i & (i - 1)) == 0) { // Check if position is a power of 2
            continue; // Skip parity bit positions
        } else {
            hammingCode[i] = dataBits[j++] - '0'; // Assign data bits
        }
    }
    
    // Calculate parity bits
    for (int i = 0; i < r; i++) {
        int position = pow(2, i);
        hammingCode[position] = calculateParity(hammingCode, position, totalBits);
    }
    
    // Display generated Hamming code
    cout << "The Hamming code generated for your data is: ";
    for (int i = 1; i <= totalBits; i++) {
        cout << hammingCode[i];
    }
    cout << endl;
    
    // Simulate error detection
    int errorPos;
    cout << "For detecting error at the receiver end, enter position of a bit to alter original data: ";
    cin >> errorPos;
    
    // Introduce error
    hammingCode[errorPos] = hammingCode[errorPos] ^ 1;
    cout << "Sent Data is : ";
    for (int i = 1; i <= totalBits; i++) {
        cout << hammingCode[i];
    }
    cout << endl;
    
    // Detect error position
    int errorDetected = 0;
    for (int i = 0; i < r; i++) {
        int position = pow(2, i);
        int parity = calculateParity(hammingCode, position, totalBits);
        if (parity != 0) {
            errorDetected += position;
        }
    }
    
    // Display error detection result
    if (errorDetected == 0) {
        cout << "No error detected." << endl;
    } else {
        cout << "Error is found at location " << errorDetected << endl;
        
        // Correct the error
        hammingCode[errorDetected] = hammingCode[errorDetected] ^ 1;
        cout << "After correcting error, Data is ";
        for (int i = 1; i <= totalBits; i++) {
            cout << hammingCode[i];
        }
        cout << endl;
    }
    
    // Display original data sent from sender
    cout << "The data sent from the sender: ";
    for (int i = 1; i <= totalBits; i++) {
        if ((i & (i - 1)) == 0) { // Skip parity bits
            continue;
        }
        cout << hammingCode[i];
    }
    cout << endl;
    
    return 0;
}
