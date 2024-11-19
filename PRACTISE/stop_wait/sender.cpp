#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    string message = "Hello";
    int sequenceNumber = 0;
    char ack;

    while(true)
    {
        char packet = message[sequenceNumber];
        cout<<"Sending Packet: "<<sequenceNumber<<packet<<endl;

        cin>>ack;
        if(ack ==' ')
        {
            cout<<"ACK timeout, resending packet "<<sequenceNumber<<endl;
        }
        else
        {
            cout<<"Received ACK: "<<ack<<endl;
        }

        if(sequenceNumber == 2)
        {
            cout<<"ACK timeout or loss, resetting..."<<endl;
            sequenceNumber = 0;
        }
        else
        {
            sequenceNumber = 1 - sequenceNumber;
        }

        this_thread::sleep_for(chrono::seconds(2));
    }
}