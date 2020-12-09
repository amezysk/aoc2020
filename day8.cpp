#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;


int main()
{
ifstream file;
string line,instruction;
int num,acc,nextOp;
vector <string> ops;
vector <string> vector1;
set <int> opsRun;
bool success=false;
int changeIndex=0;


file.open("tmp");
if(file.is_open()){
    while(getline(file, line))     
        vector1.push_back(line);
}


while (nextOp!=vector1.size() && changeIndex<vector1.size())
{
    nextOp=0;
    opsRun.clear();
    acc=0;
    while (opsRun.count(nextOp)==0 && nextOp<vector1.size())
    {
        opsRun.insert(nextOp);
        instruction = vector1[nextOp].substr(0,3);
        num = atoi(vector1[nextOp].substr(5).c_str());
        if (vector1[nextOp].substr(4,1)=="-")
            num=0-num;

        if (nextOp==changeIndex)
        {   
            if (instruction=="nop")
                instruction="jmp";
            else if (instruction=="jmp")
                instruction="nop";
        }

            
        if (instruction=="acc")
        {
            acc+=num;
            nextOp++;
        }
        else if (instruction=="jmp")
        {
            nextOp+=num;
        }
        else
        {
            nextOp++;
        }
    }
    changeIndex++;
}   
file.close();
cout<<acc<<endl;

return 0;
}
