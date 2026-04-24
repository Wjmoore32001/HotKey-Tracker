#include "hk_tracker.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void initiate_table_of_contents() {
  string table_of_contents = "data/table_of_contents.txt";

  ifstream if_toc_file(table_of_contents);
  if (!if_toc_file) {
    cout << "Table of Content File DNE\n"
         << "Would you like to create one?\n"
         << "y[Yes]"
         << "n[No]" << endl;
    string choice;
    cin >> choice;
    if (choice == "y") {
      ofstream of_toc_file(table_of_contents);
    } else {
      cout << "No, or an Invalid input was entered\n"
           << "Table of Contents is Required\n"
           << "Exiting Program" << endl;
      return;
    }
  }
  cout << "Table of Contents: \n";

  string line_text;
  while (getline(if_toc_file, line_text)) {
    cout << line_text << endl;
  }
  //
}
