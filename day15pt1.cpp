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
vector <int> lines={8,13,1,0,18,9};
int tracker[50000]; //most recent
int tracker2[50000]; //second most recent
int lastNum, currNum,tmp,i;
int run =2020;

for (i=0; i<run; ++i)
{
    if (i<lines.size())
    {
        lastNum=lines[i];
        tracker[lastNum]=i+1;
    }
    else if (tracker[lastNum]==0 || (tracker[lastNum]==i && tracker2[lastNum]==0))
    {
        lastNum=0;
        tracker2[0]=tracker[0];
        tracker[0]=i+1;

    }
    else
    {
        lastNum=tracker[lastNum]-tracker2[lastNum];
        tracker2[lastNum]=tracker[lastNum];
        tracker[lastNum]=i+1;
    }
}

    cout<<lastNum<<endl;

return 0;
}
