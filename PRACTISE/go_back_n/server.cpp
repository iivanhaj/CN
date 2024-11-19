#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void server(int window_size)
{
    int expected_seq = 0;

    while(true)
    {
        cout<<"Waiting for packet with seq number: "<<expected_seq<<endl;

        int received_seq;
        cin>>received_seq;

        if(received_seq == expected_seq)
        {
            cout<<"Packet received correctly";
            expected_seq = (expected_seq +1)%window_size;
            cout<<"ACK "<<received_seq<<endl;
        }
        else
        {
            cout << "Out of order packet. Expecting " << expected_seq << ", but received " << received_seq << endl;
            cout << "Resending ACK for " << (expected_seq - 1 + window_size) % window_size << endl;
        }
    }
}

int main()
{
    int window_size;
    cout << "Enter window size: ";
    cin >> window_size;

    server(window_size);
}