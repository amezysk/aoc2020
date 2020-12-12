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
vector <string> plane;
vector <string> plane2;
int adjacentOccupied=0;
bool changed=true;

file.open("tmp");
if(file.is_open()){
    while(getline(file, line))
        plane2.push_back(line);
}
file.close();

while (changed==true)
{
changed=false;
plane=plane2;
cout<<endl<<endl<<endl<<endl;
for (int i=0; i<plane.size();i++)
{
    //cout<<plane[i]<<endl;
    for (int j=0; j<plane[i].size(); j++)
    {
         adjacentOccupied=0;
         if (plane[i][j]=='.')
            plane2[i][j]='.';
        else
        {
             if (j-1>=0)
             {
                adjacentOccupied+=(plane[i][j-1]=='#');
                if (i+1<plane.size())
                    adjacentOccupied+=(plane[i+1][j-1]=='#');
                if (i-1>=0)
                    adjacentOccupied+=(plane[i-1][j-1]=='#');
             }
             if (j+1<plane[i].size())
             {
                adjacentOccupied+=(plane[i][j+1]=='#');
                if (i+1<plane.size())
                   adjacentOccupied+=(plane[i+1][j+1]=='#');
                if (i-1>=0)
                    adjacentOccupied+=(plane[i-1][j+1]=='#');
             }
             if (i+1<plane.size())
                adjacentOccupied+=(plane[i+1][j]=='#');
             if (i-1>=0)
                adjacentOccupied+= (plane[i-1][j]=='#');
            if (plane[i][j]=='L' && adjacentOccupied==0)
            {
                plane2[i][j]='#';
                changed=true;
            }
            else if (plane[i][j]=='#' && adjacentOccupied>3)
            {
                plane2[i][j]='L';
                changed=true;
            }
            else
                plane2[i][j]=plane[i][j];
        }       
    }
}
}

size_t count=0;

for (int k=0; k<plane2.size();k++)
    count+= std::count(plane2[k].begin(), plane2[k].end(), '#');
cout<<count<<endl;

return 0;
}
