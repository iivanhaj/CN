#include <iostream>
#include <string>
using namespace std;

// Function to perform XOR operation
void xorOperation(string &dividend, const string &divisor, int size) {
    for (int i = 0; i < size; i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

// Function to calculate the CRC remainder
string calculateCRC(string data, const string &divisor) {
    int dataSize = data.length(), divisorSize = divisor.length();
    string temp = data.substr(0, divisorSize);

    for (int i = divisorSize; i <= dataSize; i++) {
        if (temp[0] == '1') {
            xorOperation(temp, divisor, divisorSize);
        }
        temp.erase(0, 1); // Drop the first bit
        if (i < dataSize) {
            temp.push_back(data[i]); // Append the next bit from data
        }
    }
    return temp.substr(1); // Return remainder (excluding the leading bit)
}

int main() {
    // Input data bits
    int dataSize;
    cout << "Enter the size of the data array: ";
    cin >> dataSize;
    string data;
    cout << "Enter data bits: ";
    cin >> data;

    // Input divisor bits
    int divisorSize;
    cout << "Enter the size of the divisor array: ";
    cin >> divisorSize;
    string divisor;
    cout << "Enter divisor bits: ";
    cin >> divisor;

    // Append zeros to the data
    string paddedData = data + string(divisorSize - 1, '0');

    // Calculate CRC remainder and generated code
    string remainder = calculateCRC(paddedData, divisor);
    string crcCode = data + remainder;

    // Output results
    cout << "CRC Remainder: " << remainder << endl;
    cout << "Generated CRC code is: " << crcCode << endl;

    // Error detection
    cout << "Case1:\nEnter bits in the array which you want to send: ";
    string receivedData;
    cin >> receivedData;

    string receivedRemainder = calculateCRC(receivedData, divisor);
    if (receivedRemainder.find('1') != string::npos)
        cout << "Data received with error.\n";
    else
        cout << "Data received without any error.\n";

    return 0;
}
