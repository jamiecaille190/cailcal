#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <unistd.h>
using namespace std;

vector<pair<string, int>> months = {
  make_pair<string,int>("JAN", 31),
  make_pair<string,int>("FEB", 28),
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
  int begin_month = 1;
  int begin_day = 1;
  int end_month = 12;
  int end_day = 31;
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
  int day_counter = begin_day;
  int month_counter = begin_month;

  int last_day = months.at(begin_month).second;
  string month_cur = months.at(begin_month).first;
  
  while(true)
  {
    while(day_counter <= last_day)
    {
      output += month_cur + " " + to_string(day_counter) + "\t\t\t\t\t\t";
      newline++;
      if(newline == 4)
      {
        output += "\n\n\n\n\n\n";
        newline = 0;
      }
      day_counter++;
    }
    if(month_counter == end_month && day_counter == end_day + 1) break;
    day_counter = 1;
    month_counter ++;
    if(month_counter > 11) month_counter = 0;
    
    last_day = months.at(month_counter).second;
    if(month_counter == end_month) last_day = end_day;

    month_cur = months.at(month_counter).first;
  }

  ofstream output_file;
  output_file.open("cal.txt");
  output_file << output;
  output_file.close();
  
  return 0;
}