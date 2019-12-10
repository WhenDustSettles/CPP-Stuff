#include<iostream>

using namespace std;

/*
Design a class Line that implements a line, which is represented by the for-
mula y = ax + b. Your class should store a and b as double member vari-
ables. Write a member function intersect(l) that returns the x coordinate
at which this line intersects line l. If the two lines are parallel, then your
function should throw an exception Parallel. Write a C++ program that
creates a number of Line objects and tests each pair for intersection. Your
program should print an appropriate error message for parallel lines.
*/

class Line {
    
    
    public:
    
  /*  Line(double a_toput, double b_toput)
    { 
        a = a_toput;
        b = b_toput;
    }
*/
    void getInput();

    double a;
    double b;
    double intersect(Line &);

};



int main()
{
    Line l1;
    Line l2;

    double x;
    l1.getInput();
    l2.getInput();
    x = l2.intersect(l1);
    cout<<x<<endl;
    getchar();
    return 0;
}

double Line::intersect(Line & l)
{
    try{
            s
            if ((l.a/a) == (l.b/b))
                throw "Line given is parallel to this line.";
       }
    catch(const char* error_msg)
    {
        cout<<error_msg<<endl;
        return 0;
    }

    return (l.b - b)/(a - l.a);
}


void Line::getInput()
{
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;    

}
