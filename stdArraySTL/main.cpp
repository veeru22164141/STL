#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

void display(std::array<int, 5> &arr)
{
    std::cout<<"[";
    for(const auto &i:arr)
    {
        std::cout<<i<<" ";
        
    }
        std::cout<<"]"<<std::endl;
}

void test1()
{
    std::cout<<"\n Test1============================================"<<std::endl;
    
    std::array<int,5> arr1{1,2,3,4,5};
    std::array<int,5> arr2;
    
    display(arr1);
    display(arr2);
    
    arr2={10,20,30,40,50};
    
    display(arr1);
    display(arr2);
    
    std::cout<<"Sizeof the arr1 is: "<< arr1.size()<<std::endl;
    std::cout<<"Sizeof the arr2 is: "<< arr2.size()<<std::endl;
    
    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display(arr1);
    
    std::cout<<"Front of arr2: "<<arr2.front()<<std::endl;
    std::cout<<"Back of arr: " <<arr2.back()<<std::endl;
}
void test2()
{
    std::cout<<"\n Test2============================================"<<std::endl;
    
    std::array<int,5> arr1{1,2,3,4,5};
    std::array<int ,5> arr2{10,20,30,40,50};
    
    display(arr1);
    display(arr2);
    
    arr1.fill(0);
    display(arr1);
    display(arr2);
    
    arr1.swap(arr2);
    
    display(arr1);
    display(arr2);
    
}
void test3()
{
    std::cout<<"\n Test3============================================"<<std::endl;
    std::array<int ,5> arr1{1,2,3,4,5};
    
    int *ptr = arr1.data();
    
    std::cout<<ptr<<std::endl;
    
    *ptr = 1000;
    
    display(arr1);
    
}
void test4()
{
    std::cout<<"\n Test4============================================"<<std::endl;
    std::array<int ,5> arr1{2,1,4,3,5};
    
    display(arr1);
    
    std::sort(arr1.begin(),arr1.end());
    display(arr1);
}
void test5()
{
    std::cout<<"\n Test5============================================"<<std::endl;
    std::array<int ,5> arr1{2,1,4,5,3};
    
    std::array<int,5>::iterator min_num = std::min_element(arr1.begin(),arr1.end());
    auto max_num = std::max_element(arr1.begin(),arr1.end());
    
    std::cout<<"min: "<<min_num<<", max: " <<max_num<<std::endl;
    
}
void test6()
{
    std::cout<<"\n Test6============================================"<<std::endl;
    std::array<int,5> arr1{2,1,3,3,5};
    auto adjacent = std::adjacent_find(arr1.begin(),arr1.end());
    
    if(adjacent != arr1.end())
        std::cout<<"Adjacent element found with value : "<<*adjacent<<std::endl;
    else
        std::cout<<"No adjacent element found " <<std::endl;
}
void test7()
{
    std::cout<<"\n Test7============================================"<<std::endl;
    std::array<int ,5> arr1{1,2,3,4,5};
    
    int sum = std::accumulate(arr1.begin(),arr1.end(),0);
    std::cout<<"Sum of the elements in arr1 is : "<<sum<<std::endl;
}
void test8()
{
    std::cout<<"\n Test8============================================"<<std::endl;
    std::array<int,10>arr1{1,2,3,1,2,3,3,3,3,3};
    int count= std::count(arr1.begin(),arr1.end(),3);
    std::cout<<"Found 3: "<<count<<" times"<<std::endl;
}
void test9()
{
    std::cout<<"\n Test9============================================"<<std::endl;
    std::array<int ,10>arr1{1,2,3,5060,70,80,200,300,400};
    
    int count = std::count_if(arr1.begin(),arr1.end(),[](int x){
        return x>10 && x<200;
    });
    
    std::cout<<"Found "<<count <<" matches"<<std::endl;
    
}
int main(int argc, char **argv)
{
	test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
	return 0;
}
