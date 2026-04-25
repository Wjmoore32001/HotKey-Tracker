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
    cout << "\nTable of Contents Found\n";
    return true;
  }
  return false;
}

vector<string> load_table_of_contents() {
  cout << "\nTable of Contents: \n";

  vector<string> table_of_contents_vector;
  string table_of_contents_path = "data/table_of_contents.txt";
  ifstream if_toc_file(table_of_contents_path);
  string line;
  while (getline(if_toc_file, line)) {
    table_of_contents_vector.push_back(line);
  }
  return table_of_contents_vector;
}

bool main_menu(vector<string> toc_vector) {
  display_toc(toc_vector);
  cout << "\n1-x[open a category] || "
       << "0[exit program] || ";
  int choice;
  cout << "Choice: ";
  cin >> choice;

  if (choice != 0) {
    string category = toc_vector[choice - 1];
    return category_viewer(category);
  } else {
    return false;
  }
}

bool category_viewer(string category) {
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
           << "Returning to Main Menu\n";
      return true;
      ;
    }
  }
  if (category_file) {
    cout << "\nCategory File Found\n\n";
    cout << "______________________________________\n\n";
    cout << "      " << category << " Short-Cuts: " << endl;
    cout << "______________________________________";
    int subcategory_toc_index = 0;
    int subcategory_toc_line_number = 0;
    vector<string> subcategories;
    vector<int> subcategories_line_numbers;
    vector<string> file_contents;
    string line;
    string subcategory_name;
    string shortcut_desc;
    string shortcut;
    bool subcategory_flag = false;
    // true is for desc
    // false is for shortcut
    bool desc_vs_shortcut_flag = true;
    int current_line_number = 0;
    int toc_index_subcategories = 0;
    int current_subcategory_index = 0;
    int shortcut_index = 1;
    while (getline(category_file, line)) {
      if (line == "___") {
        file_contents.push_back("");
        file_contents.push_back("");
        current_line_number++;
        current_line_number++;
        line = "|===================================";
        file_contents.push_back(line);
        subcategory_flag = true;
        current_line_number++;
        current_subcategory_index++;
        shortcut_index = 1;
        continue;
      }
      if (subcategory_flag == true && line != "---") {
        subcategory_name = line;
        line = to_string(current_subcategory_index) + ". " + subcategory_name;
        file_contents.push_back(line);
        subcategories.push_back(line);
        subcategories_line_numbers.push_back(current_line_number);
        current_line_number++;
        continue;
      }
      if (line == "---") {
        line = "|===================================";
        file_contents.push_back(line);
        subcategory_flag = false;
        desc_vs_shortcut_flag = true;
        current_line_number++;
        continue;
      }
      if (desc_vs_shortcut_flag == true) {
        shortcut_desc = line;
        line = to_string(current_subcategory_index) + "." +
               to_string(shortcut_index) + "-|| " + shortcut_desc + " ||-";
        shortcut_index++;
        file_contents.push_back(line);
        desc_vs_shortcut_flag = false;
        current_line_number++;
        continue;
      }
      if (desc_vs_shortcut_flag == false) {
        shortcut = line;
        line = "-----> " + shortcut;
        file_contents.push_back(line);
        line = "------------------------------------";
        file_contents.push_back(line);
        desc_vs_shortcut_flag = true;
        current_line_number++;
        continue;
      }
    }
    bool running = true;
    view_sub_categories(subcategories);
    while (running) {
      sub_category_options();
      string choice;
      cin >> choice;

      if (choice == "v" || choice == "V" || choice == "view" ||
          choice == "View") {
        view_entire_category_file(file_contents);
      }
      if (choice == "vs" || choice == "VS") {
        view_sub_categories(subcategories);
      }
      if (choice == "c" || choice == "C" || choice == "create" ||
          choice == "Create") {
      }
      if (choice == "q" || choice == "Q" || choice == "quit") {
        return true;
      }
    }
  }
  return false;
}

void view_entire_category_file(vector<string> file_contents) {
  //
  for (string line : file_contents) {
    cout << line << endl;
  }
}
void view_sub_categories(vector<string> subcategories) {
  //
  cout << endl;
  cout << "\nSub-Categories:";
  for (string category : subcategories) {
    cout << "\n" << category;
  }
}
void sub_category_options() {
  cout << "\n\nOptions: \n"
       << "1-x[view that category] || "
       << "v[view entire file] || "
       << "vs[view sub-categories] || "
       << "r[rename a sub-category] || "
       << "c[create new sub-category] || "
       << "q[quit to main menu] || "
       << "Choice: ";
}

void display_toc(vector<string> toc_vector) {
  int i = 1;
  for (string line : toc_vector) {
    cout << i << ". " << line << endl;
    i++;
  }
}
