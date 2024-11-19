#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    char packet;
    int sequenceNumber = 0;

    while(true)
    {
        cout<<"Waiting for packet"<<endl;
        cin>>packet;

        if(packet == ' ')
        {
            continue;
        }

        cout<<"Received Packet: "<<packet<<endl;
        cout<<"Acknowledging Packet: "<<packet<<endl;

        cout<<"ACK "<<sequenceNumber<<endl;

        sequenceNumber = 1 - sequenceNumber;

    }
}