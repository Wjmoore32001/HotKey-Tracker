#include "hk_tracker.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool initiate_table_of_contents() {
  string table_of_contents = "data/table_of_contents.txt";

  ifstream if_toc_file(table_of_contents);
  if (!if_toc_file) {
    if_toc_file.close();
    cout << "Table of Content File DNE\n"
         << "Would you like to create one?\n"
         << "y[Yes]"
         << "n[No]" << endl;
    string choice;
    cin >> choice;
    if (choice == "y") {
      ofstream of_toc_file(table_of_contents);
      of_toc_file.close();
    } else {
      cout << "No, or an Invalid input was entered\n"
           << "Table of Contents is Required\n"
           << "Exiting Program" << endl;
      return false;
    }
  }
  if (if_toc_file) {
    cout << "Table of Contents Found\n";
    return true;
  }
  return false;
}

vector<string> load_table_of_contents() {
  cout << "Table of Contents: \n";

  vector<string> table_of_contents_vector;
  string table_of_contents = "data/table_of_contents.txt";
  ifstream if_toc_file(table_of_contents);
  string line_text;
  while (getline(if_toc_file, line_text)) {
    cout << line_text << endl;
    table_of_contents_vector.push_back(line_text + ".txt");
  }
  return table_of_contents_vector;
}
