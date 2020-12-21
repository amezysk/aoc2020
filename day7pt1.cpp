#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <sstream>
#include <map>


using namespace std;

struct bag {
  string name;
  set <string> contains;
};


vector <string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
        result.push_back(move(token));

    return result;
}



int main()
{
ifstream file;
string line;
string::size_type tmp1;
vector <bag> bags;
set <string> bagSet;
vector <string> split;
vector <string> split2;
string tmpStr;
file.open("tmp");
if(file.is_open()){
    while(getline(file, line))
    {
        if ((tmp1=line.find("no other bags"))!=string::npos)
        {
            continue;  
        }
        else if ((tmp1=line.find(" bags contain"))!=string::npos)
        {
            bagSet.clear();
            bag color;
            color.name=line.substr(0,tmp1);
            tmpStr=line.substr(tmp1+13);
            split = explode(tmpStr,',');
            // create a new bag
            for (int i=0; i<split.size(); ++i)
            {
                split2 = explode(split[i],' ');
                bagSet.insert(split2[2]+" "+split2[3]);
            }
            // check if any bags in new bags set have been defined
            for (int j=0; j<bags.size(); ++j)
            {
                if (bagSet.count(bags[j].name)==1)
                {
                    for (set<string>::iterator it=bags[j].contains.begin(); it!=bags[j].contains.end(); ++it)
                        bagSet.insert(*it);
                }    
            }
            // add list to any bags containing current bag
            for (int h=0; h<bags.size(); ++h)
            {
                if (bags[h].contains.count(color.name)==1)
                {
                    for (set<string>::iterator it=bagSet.begin(); it!=bagSet.end(); ++it)
                        bags[h].contains.insert(*it);
                }
            }
            color.contains=bagSet;
            bags.push_back(color); //add to list of bags
        }
    }
file.close();
}
int goldCount=0;
for (int b=0; b<bags.size(); ++b)
{
    if (bags[b].contains.count("shiny gold")==1)
        goldCount++;
}

cout<<goldCount<<endl;

return 0;
}
