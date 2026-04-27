#pragma once
#include <string>
using namespace std;

enum class token_type { CATEGORY, SUB_CATEGORY, DESCRIPTION, SHORT_CUT };

struct token {
  token_type type;
  string value;
  int line;
};
