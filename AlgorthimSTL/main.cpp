#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cctype>

class Person
{
    std::string name;
    int age;
public:
    Person()= default;
    Person(std::string name,int age):name{name},age{age}{}
    
    bool operator<(const Person &rhs)const
    {
        return this->age<rhs.age;
    }
    bool operator==(const Person &rhs)const
    {
            return (this->age == rhs.age && this->name == rhs.name); 
    }
};
void find_test()
{
    std::cout <<"\n===================================================="<< std::endl;
    std::vector<int> vec{1,2,3,4,5};
    
   // auto loc = std::find(std::begin(vec),std::end(vec),1);
    //auto loc = std::find(vec.begin(),vec.end(),1);
    std::vector<int>::iterator loc = std::find(vec.begin(),vec.end(),1);
    
    if(loc !=std::end(vec))
        std::cout<<"Found the number: " <<*loc<<std::endl;
    else
        std::cout<<"Couldn't find the number"<<std::endl;
        
    std::list<Person> players{
        {"Larry",18},
        {"Moe",20},
        {"Curly",21}
    };
    
    std::list<Person>::iterator loc1 = std::find(players.begin(),players.end(),Person{"Moe",2});
    if(loc1 != players.end())
        std::cout<<"Found Moe"<<std::endl;
    else
        std::cout<<"Moe not found"<<std::endl;
}
void count_test()
{
    std::cout<<"\n========================================================="<<std::endl;
    std::vector<int> nums{1,2,3,1,3,4,5,6};
    int num = std::count(nums.begin(),nums.end(),1);
    std::cout<<"occurrence fond: " <<num<<std::endl;
}

void count_if_test()
{
    std::cout<<"\n========================================================="<<std::endl;
    
    std::vector<int> vec{1,2,3,4,5,1,2,1,100};
    int num = std::count_if(vec.begin(),vec.end(),[](int x){
       return x%2 ==0; 
    });
    std::cout<<num<<" even number found"<<std::endl;
    num = std::count_if(vec.begin(),vec.end(),[](int x){
       return x%2 !=0; 
    });
    std::cout<<num<<" odd number found"<<std::endl;
    
    // how many elements in vec greater than 5
    num = std::count_if(vec.begin(),vec.end(),[](int x){
       return x>=5; 
    });
    std::cout<<num<<" greater than or equal to 5"<<std::endl;
}

void replace_test()
{
    std::cout<<"\n========================================================="<<std::endl;
    
    std::vector<int> vec{1,2,3,4,5,1,2,1};
    for(auto i: vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::replace(vec.begin(),vec.end(),1,100);
    
    for(auto i: vec)
    {
        std::cout<<i<<" " ;
    }
    std::cout<<std::endl;
}
void all_of_test()
{
    std::cout<<"\n========================================================="<<std::endl;
    std::vector<int> vec{1,3,5,9,4,3,13,19,6};
    
    if(std::all_of(vec.begin(),vec.end(),[](int x){return x>10;}))
        std::cout<<"All elements ar > 10" <<std::endl;
    else
        std::cout<<"Not All elements are >10" << std::endl;
    
    if(std::all_of(vec.begin(),vec.end(),[](int x){return x<20;}))
        std::cout<<"All elements are < 20" <<std::endl;
    else
        std::cout<<"Not All elements are < 20" << std::endl;
    
}

void string_transform_test()
{
    std::cout<<"\n========================================================="<<std::endl;
    
    std::string str{"this is a test"};

    std::cout<<"Before transform: " <<str<<std::endl;
    
    std::transform(str.begin(),str.end(),str.begin(),::toupper);
    
    std::cout<<"After transform: " <<str<<std::endl;
    
}


int main(int argc, char **argv)
{
	find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();

    //sort_test()
	return 0;
}
