#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>   
#include <math.h>


using namespace std;


int main()
{
ifstream file;
string line;
vector <int> lines;
vector <int> oneCounts = {0,0,0,0,0,0};
//x[i] = x[i-1]+x[i-2]+x[i-3]
int breakdown[6] = {1,2,4,7,13,24}; //checked length of streaks programmatically -max was 3.

file.open("tmp");
if(file.is_open()){
    lines.push_back(0); //for plug
    while(getline(file, line))     
        lines.push_back(atoi(line.c_str()));
}

int oneCounter=0;
    sort (lines.begin(), lines.end());
    int diff;
    for (int i=lines.size()-1; i>0; --i)
    {
        diff = lines[i]-lines[i-1];
        if (diff!=1)
        {
            //-1 because the flanking one counts are fixed points
            if (oneCounter<=oneCounts.size() &&  oneCounter-1>0)
                oneCounts[oneCounter-1]++;
            oneCounter=0;
        }
        else
            oneCounter++;
    }

//acount for last one streak if present
if (oneCounter<=oneCounts.size() &&  oneCounter-1>0)
    oneCounts[oneCounter-1]++;

cout<<fixed<<pow(breakdown[1],oneCounts[1])*pow(breakdown[2],oneCounts[2])*
    pow(breakdown[3],oneCounts[3])*pow(breakdown[4],oneCounts[4])*
    pow(breakdown[5],oneCounts[5]);

file.close();

return 0;
}
