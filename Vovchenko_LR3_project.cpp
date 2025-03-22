#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>
#include <numeric>
#include <functional>
#include <string>

using namespace std;

//число А
int a;
void setA(int a);
int getA() {return a;};

//число В
int b;
void setB(int b);
int getB() {return b;};


bool git (string input)
{
    if (input.empty()) 
    {
        return false;
    }
    try
    {
        int number = stoi(input);
        if (number < 0)
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
    return true;
}

function<void()> Enter_Number(int& varLink, string label)
{
    return [&varLink, label]()
    {
        string get_input;
        cout << label << "= ";
        getline(cin, get_input);
        while (!git(get_input))
        {
            cout << label << "= ";
            getline(cin, get_input);
        }
        varLink = stoi(get_input);
    };
}


struct Menu1
{
    string title;
    function<void()> action;
};

//задание 1
void ShowAnum()
{
    Enter_Number(a, "Enter number A: ")();
    cout << a << endl;
}

//задание 2
double ShowB()
{
    Enter_Number(b, "Enter number B: ")();
    cout << b << endl;
}

//задание 3
double Operation1(int a = 5, int b = 7)
{
    //int a = 5;
    //int b = 7;
    //return a*b;
}

// задание 3
double Operation2()
{
    //int a = 5;
    //int b = 7;
    //return a/b;
}

int main()
{
    map<int, Menu1> menu =
    {
        {1, {"Вывести A", ShowAnum}},
        {2, {"Вывести B", ShowB}},
        {3, {"Выполнить операцию “*”", Operation1}},
        {4, {"Выполнить операцию “/”", Operation2}},
    };

    int choice = 0;

    cout << "Menu: " << endl;
    for (const auto& item : menu)
    {
        cout << "Task: " <<item.first << ". " << item.second.title << endl;
    }

    cout << "0. Quit." << endl;

    while (true)
    {
    Enter_Number(choice, "Enter Number: ")();
    if (choice == 0)
    {
        cout << endl;
        break;
    }

    cout << endl;

    if (menu.find(choice) != menu.end())
    {
        menu[choice].action();
    }
    else
    {
        cout << "Invalid input.";
    }

    cout << endl << endl;
    }
    return 0;
}

