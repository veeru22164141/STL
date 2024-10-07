#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <string>

//display any vector of integers using range based for loop
void display(const std::vector<int> &vec)
{
    std::cout<<"[";
    for(auto const &i:vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void test1()
{
    std::cout<<"\n============================================="<<std::endl;
    std::vector<int> nums1{1,2,3,4,5};
 //   std::vector<int>::iterator it = nums1.begin();
    auto it = nums1.begin();
    std::cout<<*it<<std::endl;
    it++;
    std::cout<<*it<<std::endl;
    it +=2;
    std::cout<<*it<<std::endl;
    it-=2;
    std::cout<<*it<<std::endl;
    it = nums1.end() -1;
    std::cout<<*it<<std::endl;
}

void test2()
{
    std::cout<<"\n=========================================="<<std::endl;
    std::vector<int> nums1{1,2,3,4,5};
    std::vector<int>::iterator it = nums1.begin();
    while(it != nums1.end())
    {
        std::cout<<*it<<std::endl;
        it++;
    }
    // change all vector element to 0;
    it = nums1.begin();
    while(it != nums1.end())
    {
        *it =0;
        it++;
    }
    display(nums1);
}

void test3()
{
        std::cout<<"\n============================================="<<std::endl;
        std::vector<int> nums1{1,2,3,4,5};
        //std::vector<int>::const_iterator it1 = nums1.begin();
        auto it1 = nums1.cbegin();
        while(it1 != nums1.end())
        {
            std::cout<<*it1<<std::endl;
            it1++;
        }
        it1 = nums1.begin();
        while(it1 != nums1.end())
        {
            //*it1 =0;
            it1++;
        }
        
}
void test4()
{
    std::cout<<"\n=========================================================="<<std::endl;
    std::vector<int> nums1{1,2,3,4,5};
    std::vector<int>::reverse_iterator rit = nums1.rbegin();
  //  auto rit = nums1.rbegin();

    while(rit != nums1.rend())
    {
        std::cout<<*rit<<std::endl;
        rit++;
    }
    
    //const reverse iterator over a list
    std::list<std::string> name{"Larry","Moe","Curly"};
    //auto crit = name.crbegin();
    std::list<std::string,std::string>::const_reverse_iterator crit = name.crbegin();
    while(crit != name.crend())
    {
        std::cout<<*crit<<std::endl;
        crit++;
    }
    
    crit = name.crbegin();
    
    std::cout<<*crit<<std::endl;
    
    crit++;
    std::cout<<*crit<<std::endl;
    
    //iterator over map
    
    std::map<std::string,std::string> favorites{
        {"Frank","c++"},
        {"Bill","java"},
        {"james","Haskell"}
    };
    std::map<std::string,std::string>::iterator mit = favorites.begin() ;
    //auto mit = favorites.begin();
    while(mit != favorites.end())
    {
        std::cout<<mit->first<<" : "<<mit->second<<std::endl;
        mit++;
    }
    
}

void reveseString(std::string str)
{
    std::cout<<"string before reverse: "<<str<<std::endl;
    std::vector<char> char_vec;
    for(size_t i=0;i<str.length();i++)
    {
        char_vec.push_back(str.at(i));
        
    }
    auto rit = char_vec.rbegin();
    while(rit != char_vec.rend())
    {
        std::cout<<*rit;
        rit++;
    }
    
}


int main(int argc, char **argv)
{
	//test1();
    //test2();
    //test3();
    test4();
    reveseString("viremdra yadav");
	return 0;
}
