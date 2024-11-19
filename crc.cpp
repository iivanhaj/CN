#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string xorOperation(string a, string b) {
    string result = "";
    for (int i = 0; i < b.length(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

string crcEncode(string data, string genPoly) {
    int dataLen = data.length();
    int genLen = genPoly.length();
    string augmentedData = data + string(genLen - 1, '0');
    
    for (int i = 0; i < dataLen; i++) {
        if (augmentedData[i] == '1') {
            string temp = augmentedData.substr(i, genLen);
            augmentedData.replace(i, genLen, xorOperation(temp, genPoly));
        }
    }
    return augmentedData.substr(dataLen);  // Return the remainder (CRC code)
}

bool verifyCRC(string data, string genPoly, string receivedCRC) {
    int dataLen = data.length();
    int genLen = genPoly.length();
    string augmentedData = data + receivedCRC;
    
    for (int i = 0; i < dataLen; i++) {
        if (augmentedData[i] == '1') {
            string temp = augmentedData.substr(i, genLen);
            augmentedData.replace(i, genLen, xorOperation(temp, genPoly));
        }
    }
    return augmentedData.find('1') == string::npos;  // No remainder means no error
}

int main() {
    string data = "111101111";  // Given data
    string genPoly = "11011";   // Given generator polynomial

    string crc = crcEncode(data, genPoly);
    cout << "CRC Code: " << crc << endl;

    // Simulate transmission with CRC appended to the data
    string transmittedData = data + crc;
    
    cout << "Transmitted Data: " << transmittedData << endl;

    // Verify received data
    if (verifyCRC(transmittedData.substr(0, data.length()), genPoly, transmittedData.substr(data.length()))) {
        cout << "Data is correct (no error detected)." << endl;
    } else {
        cout << "Error detected in received data!" << endl;
    }

    return 0;
}
