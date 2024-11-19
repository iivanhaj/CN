#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    string message = "Hello";  // Message to send
    int sequenceNumber = 0;    // Initial sequence number
    char ack;
    
    while (true) {
        // Prepare packet as sequence number + character
        char packet = message[sequenceNumber];

        // Send the packet
        cout << "Sending Packet: " << sequenceNumber << packet << endl;

        // Wait for acknowledgment
        // Simulate receiving acknowledgment after sending a packet
        cin >> ack;
        
        if (ack == ' ') {
            cout << "ACK timeout, resending packet " << sequenceNumber << endl;
        } else {
            cout << "Received ACK: " << ack << endl;
        }

        // After sending 3 packets, reset timer and sequence number
        if (sequenceNumber == 2) {
            cout << "ACK timeout or loss, resetting..." << endl;
            sequenceNumber = 0; // Reset sequence number after 3 packets
        } else {
            sequenceNumber = 1 - sequenceNumber; // Toggle sequence number (0, 1)
        }
        
        // Delay for simulation purposes (to simulate timeouts)
        this_thread::sleep_for(chrono::seconds(2));
    }
    
    return 0;
}
