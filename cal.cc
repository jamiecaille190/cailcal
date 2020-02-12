#include <string>
#include <iostream>
using namespace std;

string months[12] = {
  "JAN",
  "FEB",
  "MAR",
  "APR",
  "MAY",
  "JUN",
  "JUL",
  "AUG",
  "SEP",
  "OCT",
  "NOV",
  "DEC"};

int main()
{
  for(int i = 1; i <= 3; i++)
  {
    for(int j = 1; j <= 31; j++)
    {
      cout << "" + months[i] << " " << j << endl;
    }
  }

  /*for(int i = JAN; i <= DEC; i++)
  {
    for(int i = 1; i <= 31; i++)
    {
      
    }
  }*/
}