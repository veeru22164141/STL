#include <iostream>
#include <algorithm>
#include <vector>

class Person
{
    friend std::ostream &operator<<(std::ostream &os , const Person &p);
    std::string name;
    int age;
public:
    Person()=default;
    Person(std::string name,int age):name{name},age{age}{}
    
    bool operator<(const Person &rhs)const
    {
        return this->age <rhs.age;
    }
    
    bool operator==(const Person &rhs)const
    {
            return (this->name ==rhs.name && this->age == rhs.age);
    }
    
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os<<p.name<<":" <<p.age;
    return os;
}

//use for_each and lambda expression to display vector elements
void display2(const std::vector<int> &vec)
{
    std::cout<<"[";
    for_each(vec.begin(),vec.end(),[](int x){
        std::cout<<x<<" " ;
    });
    std::cout<<"]"<<std::endl;
}
template <typename T> 
void display(const std::vector<T> &vec)
{
    std::cout<<"[";
    for(const auto &elem:vec)
    {
        std::cout<<elem<<" ";
    }
    std::cout<<"]"<<std::endl;
}

void test1()
{
    std::cout<<"\n test1==========================================="<<std::endl;
    std::vector<int> vec{1,2,3,4,5};
    display(vec);
    
    vec ={2,3,4,5,6};
    
    display2(vec);
    
    std::vector<int> vec1(10,100);
    display2(vec1);
}
void test2()
{
    std::cout<<"\n test2==========================================="<<std::endl;
    std::vector<int> vec{1,2,3,4,5};
    display(vec);
    
    std::cout<<"\n vec size: "<<vec.size()<<std::endl;
    std::cout<<" vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;
    
    vec.push_back(6);
    display(vec);
    
    std::cout<<"\n vec size: "<<vec.size()<<std::endl;
    std::cout<<" vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;
    
    vec.shrink_to_fit();
    
    display(vec);
    std::cout<<"\n vec size: "<<vec.size()<<std::endl;
    std::cout<<" vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;
    
    vec.reserve(100);
    display(vec);
      std::cout<<"\n vec size: "<<vec.size()<<std::endl;
    std::cout<<" vec max size: "<<vec.max_size()<<std::endl;
    std::cout<<"vec capacity: "<<vec.capacity()<<std::endl;
    
    
}
void test3()
{
    std::cout<<"\n test3==========================================="<<std::endl;
    std::vector<int> vec{1,2,3,4,5};
    
    display(vec);
    
    vec[0]=100;
    vec.at(1) = 200;
    display(vec);
    
}

void test4()
{
    std::cout<<"\n test4==========================================="<<std::endl;
    std::vector<Person> stooges;
    
    Person p1{"Larry",18};
    display(stooges);
    
    stooges.push_back(p1);
    display(stooges);
    
    stooges.push_back(Person {"Moe",25});
    display(stooges);
    
    stooges.emplace_back("curly",30);
    
    display(stooges);
}
void test5()
{
    std::cout<<"\n test5==========================================="<<std::endl;
    
    std::vector<Person> stooges{
        {"Larry",18},
        {"Moe",25},
        {"Curly",30}
    };
    
    display(stooges);
    
    std::cout<<"\nFornt : "<<stooges.front()<<std::endl;
    
    std::cout<<"back: "<<stooges.back()<<std::endl;
    
    stooges.pop_back();
    display(stooges);
}

void test6()
{
    std::cout<<"\n test6==========================================="<<std::endl;
    std::vector<int> vec{1,2,3,4,5};
    display(vec);
    
    vec.clear();
    
    display(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);
    
    vec.erase(vec.begin(),vec.begin()+2);
    display(vec);
    
    vec ={1,2,3,4,5,6,7,8,9,10};
    
    auto it = vec.begin();
    while(it!= vec.end())
    {
        if(*it %2 ==0)
            vec.erase(it);
        else
            it++;
    }
    
    display(vec);
}

void test8()
{
    std::cout<<"\n test8==============================================================="<<std::endl;
    std::vector<int> vec{1,21,3,40,12};
    
    display(vec);
    
    std::sort(vec.begin(),vec.end());
    
    display(vec);
}
void test9()
{
    std::cout<<"\n test9==============================================================="<<std::endl;
    
    std::vector<int> vec1{1,2,3,4,5};
    std::vector<int> vec2{10,20};
    
    display(vec1);
    display(vec2);
    
    std::cout<<std::endl;
    
    std::copy(vec1.begin(),vec1.end(),std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    
    //copy if element are even
    
    vec1={1,2,3,4,5,6,7,8,9,10};
    vec2 = {10,20};
    
    display(vec1);
    display(vec2);
    
    std::copy_if(vec1.begin(),vec1.end(),std::back_inserter(vec2),
    [](int x){ return x%2 ==0;});
    display(vec1);
    display(vec2);
    
    
     
}
void test10()
{
    std::cout<<"\n test10==============================================================="<<std::endl;
    std::vector<int> vec1{1,2,3,4,5};
    std::vector<int> vec2{10,20,30,40,50};
    std::vector<int> vec3;
    
    std::transform(vec1.begin(),vec1.end(),vec2.begin(),std::back_inserter(vec3),
    [](int x,int y){return x*y; });
    
    display(vec3);
    
}
//insert vec2 into vec1 before the 5
void test11()
{
    std::cout<<"\n test11==============================================================="<<std::endl;
    std::vector<int> vec1 {1,2,3,4,5,6,7,8,10};
    std::vector<int> vec2{100,200,300,400};
    
    display(vec1);
    display(vec2);
    
    auto it = std::find(vec1.begin(),vec1.end(),5);
    if(it != vec1.end())
    {
        std::cout<<"inserting..."<<std::endl;
        vec1.insert(it,vec2.begin(),vec2.end());
        auto it1 = std::find(vec1.begin(),vec1.end(),5);
        if(it1 != vec1.end())
        {
            std::cout<<"inserting...again"<<std::endl;
            vec1.insert(it1,10000);
        }
        else{
            std::cout<<"Sorry, 5 not found"<< std::endl;
        }
        //vec1.insert(it,1000);
        
    }
    else
    {
        std::cout<<"Sorry, 5 not found"<< std::endl;
    }
    display(vec1);
}

int main(int argc, char **argv)
{
	test1();
    test2();
    test3();
    test3();
    test5();
    test6();
    test8();
    test9();
    test10();
    test11();
    
	return 0;
}
