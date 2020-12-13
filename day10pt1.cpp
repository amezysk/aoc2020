#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>   

using namespace std;


int main()
{
ifstream file;
string line;
vector <int> lines;
vector <int> counts = {0,0,0,0};

file.open("tmp");
if(file.is_open()){
    lines.push_back(0); //for plug
    while(getline(file, line))     
        lines.push_back(atoi(line.c_str()));
}

    sort (lines.begin(), lines.end());
    int diff;
    for (int i=lines.size()-1; i>0;--i)
    {
        diff = lines[i]-lines[i-1];
        if (diff>=0 && diff<=3)
            counts[diff]++;
        else
            cout<<"invalid:"<<lines[i]<<" and "<<lines[i-1]<<endl;
    }
    counts[3]++; //for adapter
    cout<<counts[0]<<" "<<counts[1]<<" "<<counts[2]<<" "<<counts[3]<<endl;

    cout<<counts[1]*counts[3];

file.close();

return 0;
}
