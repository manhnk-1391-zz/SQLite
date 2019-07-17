#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>

#define POSXYZ 3

using namespace std;

vector<float> handlerStr(string str);

int main()
{
    ifstream file("output.csv");
    vector<vector<float> > vOut;
    string str;
    getline(file, str);

    while (!file.eof())
    {
        vector<float> vf = handlerStr(str);
        vOut.push_back(vf);
    }
    
    return 0;
}

vector<float> handlerStr(string str)
{
    vector<float> vOut;
    int count = 0;
    while (str.find(",",0) != string::npos)
    {
        int pos = str.find(",", 0);
        if(count < POSXYZ){
            count++;
            str = str.substr(pos+1, str.length()-1-pos);
            continue;
        }

        string tmp = str.substr(0, pos);
        if(tmp.empty())
            return vOut;

        stringstream geek(tmp);
        float fValue;
        geek >> fValue;
        vOut.push_back(fValue);
        count++;
        str = str.substr(pos+1, str.length()-pos-1);
    }
    return vOut;
}