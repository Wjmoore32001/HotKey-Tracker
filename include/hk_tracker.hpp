#pragma once
#include <string>
#include <vector>
using namespace std;
bool initiate_table_of_contents();
vector<string> load_table_of_contents();
bool main_menu(vector<string> toc_vector);
void display_toc(vector<string> toc_vector);
bool category_viewer(string category);
