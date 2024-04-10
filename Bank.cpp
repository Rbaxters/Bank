#include <iostream>
#include <string>

using namespace std;


void get_input(double& balanceInput, bool& goodInput);  //gain the first input from the user

void output_instructions(); //print the output instructions string


int main()
{
    double balanceInput;  //store the input

    bool goodInput = false;

    get_input(balanceInput, goodInput);  //call the get input function


    return 0;
}


void get_input(double& balanceInput, bool& goodInput)  //gain the first input from the user
{
    output_instructions();  //output the instructions to the user

    if (cin >> balanceInput)
    {
        cout << "Balance is valid" << endl;
        goodInput = true;  //valid input
    }
    else
    {
        while( !( cin >> balanceInput ) )
        {
            //this will be true if an error occurs. It could be while( cin.fail() )
            //but then you'd have to add the actual input
            string str;
            cin.clear();//you need to clear the flags before input
            getline( cin, str );//read what was written. Since you probably don't need this, look into cin.ignore()
            cout << str << " is not a number\n";
        }
        cout << "Balance is valid" << endl;
        goodInput = true;  //valid input
    }
}

void output_instructions() //print the instructions

{
    cout << "Please input the initial balance:  " << endl;
    cout << "" << endl;
}
