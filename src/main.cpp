#include "hk_tracker.hpp"
#include <iostream>
using namespace std;

int main() {

  vector<string> toc_vector;

  if (!initiate_table_of_contents()) {
    return 0;
  } else {
    toc_vector = load_table_of_contents();
  }
}
