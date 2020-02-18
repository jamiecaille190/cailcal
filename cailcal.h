#include <string>
#include <vector>
#include <utility>

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

int begin_month = 1;
int begin_day = 1;
int end_month = 12;
int end_day = 31;
string file_name = "cal";
string tab_string = "\t";
string enter_string = "\n";

int resolve_flags(int argc, char** argv);
