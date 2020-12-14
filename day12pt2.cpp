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
    int wpx=10;
    int wpy=1;
    int relx=10;
    int rely=1;

    file.open("tmp");
    if(file.is_open()){
        while(getline(file, line))     
            lines.push_back(line);
    } 
file.close();

int tmp;

    for (int i=0; i<lines.size();++i)
    {
        instruction=lines[i][0];
        num=atoi(lines[i].substr(1).c_str());
        switch(instruction) {
        case 'N':
            wpy+=num;
            rely=wpy-y;
            break;
        case 'S':
            wpy-=num;
            rely=wpy-y;
            break;
        case 'E':
            wpx+=num;
            relx=wpx-x;
            break;
        case 'W':
            wpx-=num;
            relx=wpx-x;
            break;
        case 'L':
            if (num==90)
                num=270;
            else if (num==270)
                num=90;
        case 'R':
            if (num==90)
            {
                tmp=rely;
                rely=-relx;
                relx=tmp;
                wpx=x+relx;
                wpy=y+rely;
            }
            else if (num==180)
            {
                rely=-rely;
                relx=-relx;
                wpy=y+rely;
                wpx=x+relx;
            }
            else if (num==270)
            {
                tmp=relx;
                relx=-rely;
                rely=tmp;
                wpx=x+relx;
                wpy=y+rely;
            }
            break;
        case 'F':
            relx=wpx-x;
            rely=wpy-y;
            y+=num*(wpy-y);
            x+=num*(wpx-x);
            wpx=x+relx;
            wpy=y+rely;
            break;
        default:
            break;
        }
    cout<<x<<" "<<y<<endl;
    cout<<"waypoint"<<wpx<<" "<<wpy<<endl;

    }

cout<<fabs(x)+fabs(y)<<endl;



return 0;
}
