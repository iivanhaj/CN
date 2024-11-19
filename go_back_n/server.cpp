#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

// Function to simulate the server (receiver) side
void server(int window_size) {
    int expected_seq = 0;
    
    while (true) {
        // Simulate receiving a packet
        cout << "Waiting for packet with sequence number: " << expected_seq << endl;

        // Receive the packet
        int received_seq;
        cin >> received_seq;

        if (received_seq == expected_seq) {
            cout << "Packet " << received_seq << " received correctly." << endl;
            expected_seq = (expected_seq + 1) % window_size;  // Expect the next packet
            cout << "ACK " << received_seq << endl;  // Send acknowledgment
        } else {
            cout << "Out of order packet. Expecting " << expected_seq << ", but received " << received_seq << endl;
            cout << "Resending ACK for " << (expected_seq - 1 + window_size) % window_size << endl;
        }
    }
}

int main() {
    int window_size;
    cout << "Enter window size: ";
    cin >> window_size;

    // Start the server
    server(window_size);

    return 0;
}
