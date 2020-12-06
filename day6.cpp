#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>

using namespace std;


int main()
{
 ofstream outf;
  outf.open("tmp", std::ios_base::app); 
  outf << "\n\n"; 
  outf.close();

ifstream file;
string line;
set <char> currYes, lastYes;
int total=0;
bool isFirst=true;
file.open("tmp");
if(file.is_open()){
    while(getline(file, line)){
        if (line.empty())
        {
            total+=currYes.size();
            isFirst=true;
            currYes.clear();
            lastYes.clear();
        }
        else 
        {
            if (isFirst)
            {
                isFirst=false;
                for (unsigned int i=0; i<line.length(); ++i)
                    currYes.insert(line[i]);
            }
            else
            {
                lastYes=currYes;
                currYes.clear();
                for (unsigned int i=0; i<line.length(); ++i)
                {   
                    if (lastYes.count(line[i])==1)
                        currYes.insert(line[i]);
                }
            }
            

        }
    }
}
file.close();
cout<<total<<endl;

return 0;
}
