#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <unistd.h>
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
  int op;
  int begin_month = -1;
  int begin_day = -1;
  int end_month = -1;
  int end_day = -1;
  string date;
  while((op = getopt(argc, argv, "b:e:")) != -1)
  {
    switch(op) {
      case 'b':
        date = optarg;
        if(date.length() != 4)
        {
          cerr << "Length of begin date invalid, use mmdd format." << endl;
          return 1;
        }
        else
        {
          begin_month = stoi(date.substr(0, 2));
          if(begin_month < 1 || begin_month > 12)
          {
            cerr << "Begin date month must be between 1 (JAN) and 12 (DEC)." << endl;
            return 1;
          }
          begin_day = stoi(date.substr(2, 2));
          if(begin_day < 1 || begin_day > months.at(begin_month - 1).second)
          {
            cerr << "Begin date day must be between 1 and the amount of days in the month." << endl;
            return 1;
          }
        }
        
        break;
      case 'e':
        date = optarg;
        if(date.length() != 4)
        {
          cerr << "Length of end date invalid, use mmdd format." << endl;
          return 1;
        }
        else
        {
          end_month = stoi(date.substr(0, 2));
          if(end_month < 1 || end_month > 12)
          {
            cerr << "End date month must be between 1 (JAN) and 12 (DEC)." << endl;
            return 1;
          }
          end_day = stoi(date.substr(2, 2));
          if(end_day < 1 || end_day > months.at(end_month - 1).second)
          {
            cerr << "End date day must be between 1 and the amount of days in the month." << endl;
            return 1;
          }
        }
        if(begin_month == end_month && begin_day == end_day)
        {
          cerr << "Begin date can't be the same as end date." << endl;
          return 1;
        }

        break;
    }
  }

  string output = "";

  begin_month --;
  end_month --;
  int newline = 0;
  for(auto i : months)
  {
    for(int j = 1; j <= i.second; ++j)
    {
      output += i.first + " " + to_string(j) + "\t\t\t\t\t\t";
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