#include<iostream>
using namespace std;

int main()
{
    int *ptr, var;
    cout<<"Enter var: ";
    cin>>var;

    ptr = &var;
    cout<<"Value of var: "<<var<<endl;
    cout<<"Address of var: "<<ptr<<endl;
    cout<<"Address of ptr: "<<&ptr<<endl;

    return 0;

}
