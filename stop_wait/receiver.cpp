#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    char packet;
    int sequenceNumber = 0;
    
    while (true) {
        cout << "Waiting for packet..." << endl;
        
        // Simulate receiving packet (For simplicity, we use cin here)
        cin >> packet;
        
        // Packet should be in the format: sequence number + character
        if (packet == ' ') {
            continue;
        }
        
        cout << "Received Packet: " << packet << endl;
        cout << "Acknowledging Packet: " << packet << endl;

        // Send ACK for received packet
        // (In a real system, this would be sent over a network, but here we just print it.)
        cout << "ACK " << sequenceNumber << endl;

        // Increment sequence number (to simulate alternate packet numbers)
        sequenceNumber = 1 - sequenceNumber;
    }
    
    return 0;
}
