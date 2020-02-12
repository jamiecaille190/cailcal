#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

vector<pair<string, int>> months = {
  make_pair<string,int>("JAN", 31),
  make_pair<string,int>("FEB", 29),
  make_pair<string,int>("MAR", 31),
  make_pair<string,int>("APR", 30),
  make_pair<string,int>("MAY", 31),
  make_pair<string,int>("JUN", 30),
  make_pair<string,int>("JUL", 31),
  make_pair<string,int>("AUG", 31),
  make_pair<string,int>("SEP", 30),
  make_pair<string,int>("OCT", 31),
  make_pair<string,int>("NOV", 30),
  make_pair<string,int>("DEC", 31),
};

int main(int argc, char** argv)
{

  string output = "";

  /*bool setBegin = false;
  bool setEnd = false;
  int beginMonth = 0;
  int beginDay = 0;
  int endMonth = 0;
  int endDay = 0;
  for(int args = 0; args < argc; args++)
  {

  }*/

  /*int newline = 0; //actual one, below one is for my use
  for(auto i : months)
  {
    for(int j = 1; j <= i.second; ++j)
    {
      cout << i.first << " " << j << "\t\t\t\t\t\t";
      if(newline == 3) cout << "\n\n\n\n\n";
      newline = (++newline % 4);
    }
  }*/


  int newline = 0;
  for(int i = 1; i <= 3; i++)
  {
    for(int j = 1; j < months.at(i).second; ++j)
    {
      output += months.at(i).first + " " + to_string(j) + "\t\t\t\t\t\t";
      if(newline == 3) output += "\n\n\n\n\n";
      newline = (++newline % 4);
    }
  }
  ofstream output_file;
  output_file.open("cailcal.txt");
  output_file << output;
  output_file.close();
  
  return 0;
}