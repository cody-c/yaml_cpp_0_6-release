#include "yaml-cpp-0.6/null.h"

namespace YAML_0_6 {
_Null Null;

bool IsNullString(const std::string& str) {
  return str.empty() || str == "~" || str == "null" || str == "Null" ||
         str == "NULL";
}
}
