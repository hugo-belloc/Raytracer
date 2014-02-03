#include <iostream>
#include <string>
#include "WindowContent.hpp"
#include "WindowModel.hpp"

using namespace std;

class TTYNumberContent : public gui::WindowContent
{
public :
    TTYNumberContent(int number):_number(number)
    {}

    virtual ~TTYNumberContent()
    {
    }

    virtual void display()
    {
        cout<<"Number="<<_number<<endl;
    }

private:
    int _number;
};

class TTYStringContent : public gui::WindowContent
{
public :
    TTYStringContent(const string & str):_str(str)
    {}

    virtual ~TTYStringContent()
    {
    }

    virtual void  display()
    {
        cout<<"String="<<_str<<endl;
    }

private:
    string _str;
};

int main()
{
    return 0;
}
