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
    vector <string> lines;
    char instruction;
    int num=0;
    int x=0;
    int y=0;
    int currDegrees=90; //N=0,E=90,S=180,W=270

    file.open("tmp");
    if(file.is_open()){
        while(getline(file, line))     
            lines.push_back(line);
    } 
file.close();

    for (int i=0; i<lines.size();++i)
    {
        instruction=lines[i][0];
        num=atoi(lines[i].substr(1).c_str());
        switch(instruction) {
        case 'N':
            y+=num;
            break;
        case 'S':
            y-=num;
            break;
        case 'E':
            x+=num;
            break;
        case 'W':
            x-=num;
            break;
        case 'L':
            currDegrees-=num;
            break;
        case 'R':
            currDegrees+=num;
            break;
        case 'F':
            if (currDegrees==0)
                y+=num;
            else if (currDegrees==90)
                x+=num;
            else if (currDegrees==180)
                y-=num;
            else
                x-=num;
            break;
        default:
            break;
        }
        if (currDegrees>=360)
            currDegrees-=360;
        else if (currDegrees<0)
            currDegrees+=360;
    }

cout<<fabs(x)+fabs(y)<<endl;



return 0;
}
