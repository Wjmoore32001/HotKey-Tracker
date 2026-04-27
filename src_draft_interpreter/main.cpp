#include "hk_tracker.hpp"
using namespace std;

int main() {

  vector<string> toc_vector;
  bool running = true;
  while (running) {
    //
    if (!initiate_table_of_contents()) {
      return 0;
    } else {
      toc_vector = load_table_of_contents();
    }
    running = main_menu(toc_vector);
  }
}
