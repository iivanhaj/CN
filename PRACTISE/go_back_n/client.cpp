#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void client(int window_size)
{
    int seq_number = 0;
    int next_seq = 0;
    int base = 0;

    while(true)
    {
        if(next_seq< base +window_size)
        {
            cout<<"Sending packet with sequence number: "<<next_seq<<endl;
            next_seq++;

            this_thread::sleep_for(chrono::seconds(2));

            int ack;
            cin>>ack;

            if(ack == base)
            {
                base++;
            }
            else
            {
                cout<<"Resending packet with sequence number: "<<ack<<endl;
            }
        }
    }

}

int main()
{
    int window_size;
    cout << "Enter window size: ";
    cin >> window_size;

    client(window_size);
}