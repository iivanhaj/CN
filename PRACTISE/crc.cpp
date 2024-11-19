#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string xorOperation(string a, string b)
{
    string result = "";
    for (int i = 0; i < b.length(); i++)
    {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

string crc(string data, string polynomial)
{
    int datalen = data.length();
    int polylen = polynomial.length();
    string augmentedData = data + string(polylen - 1, '0');

    for(int i=0; i<datalen;i++)
    {
        if(augmentedData[i]=='1')
        {
            string temp = augmentedData.substr(i,polylen);
            augmentedData.replace(i,polylen,xorOperation(temp,polynomial));
        }
    }

    return augmentedData.substr(datalen); //crc code
}

bool verifycrc(string data, string polynomial, string receivedcrc)
{
    int datalen = data.length();
    int polylen = polynomial.length();
    string augmentedData = data + receivedcrc;

    for(int i=0; i<datalen;i++)
    {
        if(augmentedData[i]=='1')
        {
            string temp = augmentedData.substr(i,polylen);
            augmentedData.replace(i,polylen,xorOperation(temp,polynomial));
        }
    }

    return augmentedData.find('1') == string::npos;
}

int main()
{
    string data = "111101111";
    string polynomial = "11011";

    string crc_code = crc(data,polynomial);
    cout<<"CRC Code: "<<crc_code<<endl;

    string transmittedData = data + crc_code;
    cout<<"Transmitted Data: "<<transmittedData<<endl;

    if(verifycrc(transmittedData.substr(0,data.length()),polynomial,transmittedData.substr(data.length())))
    {
        cout<<"Data is correct (no error detected)"<<endl;
    }
    else
    {
        cout<<"Error detected in received data"<<endl;
    }
}