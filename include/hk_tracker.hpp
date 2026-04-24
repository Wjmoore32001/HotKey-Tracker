#pragma once
#include <string>
#include <vector>
using namespace std;
bool initiate_table_of_contents();
vector<string> load_table_of_contents();
void main_menu(vector<string> toc_vector);
