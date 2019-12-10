#include <iostream>
 using namespace std;

int main()
{
    string str;
    cout<<"Enter a String: ";
    
    getline(cin,str);
    
    cout<<"You entered: ";
    cout<<str<<endl;

    str.push_back('N');
    cout<<"New String ";
    cout<<str<<endl;
    return 0;


}
