 // I think it can be easy if a number from 1-100 or 0-99
 #include<bits/stdc++.h>
using namespace std;
int main()
{
    srand((unsigned int) time(NULL));
    int number = (rand());

int guess = 0;

do
{
    cout << "Enter guess :";
    cin >> guess;
  

    if(guess > number)
    cout << "Guess lower!" << endl;
    else if (guess < number)
    cout << "Guess higher!" << endl;
    else
    cout <<" YOU WON!" << endl;
} while (guess != number);
 return 0;

}