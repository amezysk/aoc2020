#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>   

using namespace std;

int getOccupancyDiagnol(const vector<string> &plane, int row, int col)
{
    int adjacentOccupied=0;
    int i=row-1;
    int j=col-1;
    while (i>=0 && j>=0)
    {
        if (plane[i][j]=='#' || plane[i][j]=='L')
        {   adjacentOccupied+=(plane[i][j]=='#');
            break;}
        i--;
        j--;
    }
    i=row+1;
    j=col+1;
    while (i<=plane.size()-1 && j<=plane[i].size()-1)
    {
        if (plane[i][j]=='#' || plane[i][j]=='L')
        {   adjacentOccupied+=(plane[i][j]=='#');
            break;}
        i++;
        j++;
    }
    i=row-1;
    j=col+1;
    while (i>=0 && j<=plane[i].size()-1)
    {
        if (plane[i][j]=='#' || plane[i][j]=='L')
        {   adjacentOccupied+=(plane[i][j]=='#');
            break;}
        i--;
        j++;
    }
    i=row+1;
    j=col-1;
    while (j>=0 && i<=plane.size()-1)
    {
        if (plane[i][j]=='#' || plane[i][j]=='L')
        {   adjacentOccupied+=(plane[i][j]=='#');
            break;}
        i++;
        j--;
    }
    return adjacentOccupied;
}


int getOccupancyCol(const vector<string> &plane, int row, int col)
{
    int adjacentOccupied=0;
    int i=row-1;
    while (i>=0)
    {
        if (plane[i][col]=='#' || plane[i][col]=='L')
        {   adjacentOccupied+=(plane[i][col]=='#');
            break;}
        i--;
    }
    i=row+1;
    while (i<=plane.size()-1)
    {
        if (plane[i][col]=='#' || plane[i][col]=='L')
        {   adjacentOccupied+=(plane[i][col]=='#');
            break;}
        i++;
    }
    return adjacentOccupied;
}

int getOccupancyRow(const string &row, int pos)
{
    int adjacentOccupied=0;
    size_t n;
    if (pos>0)
    {
        n= row.substr(0,pos).find_last_of("#L");
        if (n!=string::npos)
            adjacentOccupied+=(row[n]=='#');
    }
    if (pos<row.size())
    {
        n= row.substr(pos+1).find_first_of("#L");
        if (n!=string::npos)
            adjacentOccupied+=(row[n+pos+1]=='#');
    }
    return adjacentOccupied;
}


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
for (int i=0; i<plane.size();i++)
{
    for (int j=0; j<plane[i].size(); j++)
    {
         adjacentOccupied=0;
         if (plane[i][j]=='.')
            plane2[i][j]='.';
        else
        {
            adjacentOccupied+=getOccupancyRow(plane[i],j);
            adjacentOccupied+=getOccupancyCol(plane,i,j);
            adjacentOccupied+=getOccupancyDiagnol(plane,i,j);
            if (plane[i][j]=='L' && adjacentOccupied==0)
            {
                plane2[i][j]='#';
                changed=true;
            }
            else if (plane[i][j]=='#' && adjacentOccupied>4)
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
