// Type your code here, or load an example.

/*
 * in this program we have to arrange words of a given string in such way that word with less distinct character
will come first but if two words having same distinct character then that character come first which was also placed fist
in original string.
fist use map so that make "word and its distinct character count" pair , to count distinct charecter in word use set 
as set can not store duplicate element then find the size if set after that    
 * */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
void FirstNonRepeat(string s)
{
    for(size_t i{0};i<s.length();i++)
    {
        if(s.find(s[i],s.find(s[i]) + 1)==string::npos)
        {
            cout<<"first non-repeating character is "<<s[i];
            return;
        }
    }
    cout<<"Either all charcters are repeating or string is empty";
    return;
}

vector<string> jumbled(vector<string> &vecStr)
{
    map<string,int> wordWithDistinctchar{};
    set<char> setsofDistinctChar{};
    for(auto word:vecStr)
    {
//        cout<<"word: "<<word<<endl;
        for(auto ch: word)
        {
//            cout<<"ch: "<<ch<<endl;
            setsofDistinctChar.emplace(ch);
        }
//       cout<<setsofDistinctChar.size()<<endl;
        wordWithDistinctchar[word]=setsofDistinctChar.size();
        setsofDistinctChar.clear();
    } 
    vector<pair<string,int>> tempvec{};
    for(auto &mit:wordWithDistinctchar)
     {
         cout<<(mit).first<<" : "<<mit.second <<" ";
        tempvec.push_back(mit);
     }
     cout<<endl;

     sort(tempvec.begin(),tempvec.end(),[](pair<string,int>&a,pair<string,int>&b)
     {
        return a.second<b.second;
     });
     vector<string>temp{};
     for(auto &vecEl:tempvec)
     {

        cout<<(vecEl).first<<" : "<<vecEl.second <<" ";
        temp.push_back((vecEl).first);
     }
     cout<<endl;
     return temp;
     
}
void sort_test(std::vector<std::string> vecStr)
{
    std::vector<std::pair<std::string,int>> tempPairVec{};
    set<char> charSet{};
    for(auto it:vecStr)
    {
        for(auto sIt:it)
        {
            charSet.emplace(sIt);
        }
        std::pair<std::string,int> p{it,charSet.size()};
        charSet.clear();
        tempPairVec.push_back(p);
    }
     sort(tempPairVec.begin(),tempPairVec.end(),[](pair<string,int>&a,pair<string,int>&b)
     {
        return a.second<b.second;
     });
      vector<string>temp{};
     for(auto &vecEl:tempPairVec)
     {

        cout<<(vecEl).first<<" : "<<vecEl.second <<" ";
        temp.push_back((vecEl).first);
     }
     cout<<endl;
     for(auto it:temp)
     {
        cout<<it<<" ";
     }
}

int main()
{
    vector<string> vecStr{"bananas","do","not","to","grow","in","mississippi"};
    vector<string>jumbledVec=jumbled(vecStr);
    for(auto it: jumbledVec)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    sort_test(vecStr);
    //FirstNonRepeat(s);
}