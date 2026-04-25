#include "hk_tracker.hpp"
using namespace std;

int main() {

  vector<string> toc_vector;

  if (!initiate_table_of_contents()) {
    return 0;
  } else {
    toc_vector = load_table_of_contents();
  }
  // call a menu
  // picking from table of contents
  bool running = true;
  while (running) {
    //
    running = main_menu(toc_vector);
    //
    //
  }
}
