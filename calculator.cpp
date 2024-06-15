#include<bits/stdc++.h>
using namespace std;
int main(){
 double number1,number2;
    string operation;
    cout <<"Enter number1: ";
    cin >> number1;
    cout << "Enter  operation (+,-,*,/) : ";
    cin >> operation;
     cout <<"Enter number2: ";
    cin >> number2;

    if(operation == "+")
    cout << number1 + number2;
    else if(operation == "-")
    cout << number1 - number2;
    else if(operation == "*")
    cout << number1 * number2;
   else if(operation == "/")
    cout << number1 / number2;
    else
    cout << "Please check your operator";

}