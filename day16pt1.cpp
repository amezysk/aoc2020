#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>   
#include <math.h>


using namespace std;

void parseRule(string &in, vector <int> &tracker)
{
    string::size_type x = in.find(": ");
    in = in.substr(x+2);
    x=in.find("-");
    tracker.push_back(atoi(in.substr(0,x).c_str()));
    in=in.substr(x+1);
    x=in.find(" ");
    tracker.push_back(atoi(in.substr(0,x).c_str()));
    in=in.substr(x+4); // length of " or "
    x=in.find("-");
    tracker.push_back(atoi(in.substr(0,x).c_str()));
    tracker.push_back(atoi(in.substr(x+1).c_str()));
}

void parseTicket(string &in, vector <vector<int>> &t)
{
    string::size_type x;
    vector <int> ticket;
    t.push_back(ticket);
    const int i = t.size()-1;
    while ((x=in.find(","))!=string::npos)
    {
        t[i].push_back(atoi(in.substr(0,x).c_str()));
        in=in.substr(x+1);
    }
    t[i].push_back(atoi(in.c_str())); //last value without ending comma
}

int main()
{
    ifstream file;
    string line;
    vector <int> rangeTracker; //4 per line
    vector <vector <int>> tickets; //each ticket is a vector
    int ruleCount;
    int num;
    int invalidSum=0;
    bool isValid;
    file.open("tmp");
    if(file.is_open()){
        while(getline(file, line))
            if (line.find(": ")!=string::npos) // rule
                parseRule(line, rangeTracker);
            else if (line.find(",")!=string::npos)
                parseTicket(line,tickets);} 

//begin at one since we don't care about own ticket
    for (int i=1; i<tickets.size();++i)//all tickets
    {
        for (int j=0; j<tickets[i].size();++j)
        {
            num= tickets[i][j];
            isValid=false;
            ruleCount=0;

            while (ruleCount<rangeTracker.size()-3)
            {
                if ((num>=rangeTracker[ruleCount] && num<=rangeTracker[ruleCount+1]) ||
                (num>=rangeTracker[ruleCount+2] && num<=rangeTracker[ruleCount+3]))
                {
                    ruleCount=0;
                    isValid=true;
                    break;
                }
                ruleCount+=4;
            }
            if (!isValid)
                invalidSum+=num;
        }
    }

cout<<invalidSum<<endl;

file.close();

return 0;
}
