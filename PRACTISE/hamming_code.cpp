#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> hammingcode(const vector<int> &data)
{
    int m = data.size();
    int r = 0;
    while(pow(2,r)<m+r+1) r++;
    vector<int> code(m+r,0);

    int j = 0, k = 0;
    for(int i = 0; i<code.size(); i++)
    {
        if(i == pow(2,j)-1) j++;
        else code[i] = data[k++];
    }

    for(int i=0; i<r; i++)
    {
        int parityPos = pow(2,i)-1;
        int count =0;

        for(int j = parityPos; j<code.size(); j+=2*(parityPos+1))
        {
            for(int k = j; k<j+parityPos+1 && k<code.size(); k++)
            {
                count += code[k];
            }
        }
        code[parityPos] = count%2;
    }

    return code;
}

void detectandcorrect(vector<int>& received)
{
    int n = received.size();
    int r = log2(n+1);
    int errorPos = 0;

    for(int i =0; i<r; i++)
    {
        int parityPos = pow(2,i)-1;
        int count = 0;

        for(int j = parityPos; j<n; j+=2*(parityPos+1))
        {
            for(int k = j; k<j+parityPos+1 && k<n; k++)
            {
                count += received[k];
            }
        }

        if(count%2) errorPos += pow(2,i);
    }

    if(errorPos)
    {
        cout<<"Error at position: "<<errorPos<<endl;
        received[errorPos-1] ^= 1;
    }
    else
    {
        cout<<"No error detected."<<endl;
    }

    cout<<"Corrected Code: ";
    for(int bit : received) cout<<bit<<" ";
    cout<<endl;
}

int main()
{
    vector<int> data = {1,0,1,1};
    vector<int> hammingCode = hammingcode(data);

    cout<<"Generated Hamming Code: ";
    for(int bit : hammingCode) cout<<bit<<" ";
    cout<<endl;

    hammingCode[2] ^= 1; //error
    cout<<"Received Code (with error): ";
    for(int bit : hammingCode) cout<<bit<<" ";
    cout<<endl;

    detectandcorrect(hammingCode);
    return 0;
}