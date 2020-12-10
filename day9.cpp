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
int j,k;
const int start=25;
int num;

file.open("tmp");
if(file.is_open()){
    while(getline(file, line))     
        lines.push_back(atoi(line.c_str()));
}

// pt1 - get first num without sum in preamble
for (unsigned int i=start; i<lines.size(); ++i)
{
    j=i-start;
    do {
        k=j+1;
        while (k<i && lines[k]+lines[j]!=lines[i])
            k++;        
        j++;
    } while (j<i && lines[k]+lines[j-1]!=lines[i]);
    if (lines[k]+lines[j-1]!=lines[i])
        num=lines[i];
}

int sum,x;
for (int z=0; z<(lines.size()-1); ++z)
{
    sum=lines[z];
    x=z+1;
    vector <int> nums;
    nums.push_back(lines[z]);

    while (sum<num && x<lines.size())
    {
        sum+=lines[x];
        nums.push_back(lines[x]);
        x++;
    }

    if (nums.size()>1 && sum==num)
    {
        sort (nums.begin(), nums.end());
        cout<<nums[0]+nums[nums.size()-1];
        break;
    }
}




file.close();

return 0;
}
