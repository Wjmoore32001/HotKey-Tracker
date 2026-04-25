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
      ifstream if_toc_file(table_of_contents);
      of_toc_file.close();
    } else {
      cout << "No, or an Invalid input was entered\n"
           << "Table of Contents is Required\n"
           << "Exiting Program" << endl;
      return false;
    }
  }
  if (if_toc_file) {
    if_toc_file.close();
    cout << "Table of Contents Found\n";
    return true;
  }
  return false;
}

vector<string> load_table_of_contents() {
  cout << "Table of Contents: \n";

  vector<string> table_of_contents_vector;
  string table_of_contents_path = "data/table_of_contents.txt";
  ifstream if_toc_file(table_of_contents_path);
  string line;
  while (getline(if_toc_file, line)) {
    table_of_contents_vector.push_back(line);
  }
  return table_of_contents_vector;
}

void main_menu(vector<string> toc_vector) {
  bool running = true;
  while (running) {
    display_toc(toc_vector);
    cout << "Enter Number to open a Category\n "
         << "or\n"
         << "Press 0 to edit a category name" << endl;
    int choice;
    cout << "Choice: ";
    cin >> choice;

    if (choice != 0) {
      string category = toc_vector[choice - 1];
      category_viewer(category);
      continue;
    } else {
      running = false;
    }
  }
}

void category_viewer(string category) {
  string category_file_path = "data/category/" + category + ".txt";
  ifstream category_file(category_file_path);
  if (!category_file) {
    cout << "File For Selected Category Not Found\n"
         << "Would you like to create one?\n"
         << "y[Yes]"
         << "n[No]" << endl;
    string choice;
    cin >> choice;
    if (choice == "y") {
      ofstream category_file(category_file_path);
      category_file.close();
    } else {
      cout << "No, or an Invalid input was entered\n"
           << "Table of Contents is Required\n"
           << "Exiting Program" << endl;
      return;
    }
  }
  if (category_file) {
    cout << "\nCategory File Found\n\n";
    cout << "---------------------------------\n";
    cout << category << " Short-Cuts: " << endl;
    cout << "---------------------------------\n";
    int subcategory_toc_index = 0;
    int subcategory_toc_line_number = 0;
    vector<string> subcategories;
    vector<int> subcategories_line_numbers;
    vector<string> file_contents;
    string line;
    bool subcategory_flag = false;
    // true is for desc
    // false is for shortcut
    bool desc_vs_shortcut_flag = true;
    int current_line_number = 0;
    int toc_index_subcategories = 0;
    while (getline(category_file, line)) {
      if (line == "___") {
        file_contents.push_back(line);
        subcategory_flag = true;
        current_line_number++;
        continue;
      }
      if (subcategory_flag == true && line != "---") {
        file_contents.push_back(line);
        subcategories.push_back(line);
        subcategories_line_numbers.push_back(current_line_number);
        current_line_number++;
        continue;
      }
      if (line == "---") {
        file_contents.push_back(line);
        subcategory_flag = false;
        desc_vs_shortcut_flag = true;
        current_line_number++;
        continue;
      }
      if (desc_vs_shortcut_flag == true) {
        file_contents.push_back(line);
        cout << "-|| " << line << " ||-" << endl;
        desc_vs_shortcut_flag = false;
        current_line_number++;
        continue;
      }
      if (desc_vs_shortcut_flag == false) {
        file_contents.push_back(line);
        cout << "--> " << line << endl;
        cout << "\n";
        desc_vs_shortcut_flag = true;
        current_line_number++;
        continue;
      }
    }
    category_file.close();
  }
  //
}

void display_toc(vector<string> toc_vector) {
  int i = 1;
  for (string line : toc_vector) {
    cout << i << ". " << line << endl;
    i++;
  }
}
