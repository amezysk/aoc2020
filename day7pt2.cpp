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
  vector <pair <string, int>> numMap;
};


vector <string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
        result.push_back(move(token));

    return result;
}

void countBags( string &currBag,  vector <bag> &bags, int &count, int count2)
{
    for (int i=0; i<bags.size(); ++i)
    {
        if (bags[i].name==currBag)
        {
                for (int j=0; j<bags[i].numMap.size(); ++j)
                {
                    count+=bags[i].numMap[j].second*count2;
                    countBags(bags[i].numMap[j].first, bags,count, bags[i].numMap[j].second*count2);
                }

            }
    }

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
int tmpNum;
file.open("tmp");
if(file.is_open()){
    while(getline(file, line))
    {
        //fill bags vector as we parse the file
        if ((tmp1=line.find(" bags contain"))!=string::npos)
        {
            bagSet.clear();
            vector <pair <string,int>> bagVect;
            bag color;
            color.name=line.substr(0,tmp1);
            //If this is an empty bag, add it to the bag vector with name only and move on
            if (line.find("no other bags")!=string::npos)
            {
                bags.push_back(color);
                continue;
            }
            tmpStr=line.substr(tmp1+13);
            split = explode(tmpStr,',');
            // create a new bag
            for (int i=0; i<split.size(); ++i)
            { 
                split2 = explode(split[i],' ');
                bagSet.insert(split2[2]+" "+split2[3]);
                bagVect.push_back(make_pair(split2[2]+" "+split2[3], atoi(split2[1].c_str())));
            }
            color.contains=bagSet;
            color.numMap=bagVect;
            bags.push_back(color); //add to list of bags
        }
    }
}
file.close();

string currBag = "shiny gold";
int c = 0;
countBags(currBag, bags, c, 1);
cout<<c<<endl;


return 0;
}
