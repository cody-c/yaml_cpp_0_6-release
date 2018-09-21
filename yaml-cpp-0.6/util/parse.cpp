#include <fstream>
#include <iostream>
#include <vector>

#include "yaml-cpp-0.6/eventhandler.h"
#include "yaml-cpp-0.6/yaml.h"  // IWYU pragma: keep

struct Params {
  bool hasFile;
  std::string fileName;
};

Params ParseArgs(int argc, char** argv) {
  Params p;

  std::vector<std::string> args(argv + 1, argv + argc);

  return p;
}

class NullEventHandler : public YAML_0_6::EventHandler {
 public:
  void OnDocumentStart(const YAML_0_6::Mark&) override {}
  void OnDocumentEnd() override {}

  void OnNull(const YAML_0_6::Mark&, YAML_0_6::anchor_t) override {}
  void OnAlias(const YAML_0_6::Mark&, YAML_0_6::anchor_t) override {}
  void OnScalar(const YAML_0_6::Mark&, const std::string&, YAML_0_6::anchor_t,
                const std::string&) override {}

  void OnSequenceStart(const YAML_0_6::Mark&, const std::string&, YAML_0_6::anchor_t,
                       YAML_0_6::EmitterStyle::value) override {}
  void OnSequenceEnd() override {}

  void OnMapStart(const YAML_0_6::Mark&, const std::string&, YAML_0_6::anchor_t,
                  YAML_0_6::EmitterStyle::value) override {}
  void OnMapEnd() override {}
};

void parse(std::istream& input) {
  try {
    YAML_0_6::Node doc = YAML_0_6::Load(input);
    std::cout << doc << "\n";
  } catch (const YAML_0_6::Exception& e) {
    std::cerr << e.what() << "\n";
  }
}

int main(int argc, char** argv) {
  Params p = ParseArgs(argc, argv);

  if (argc > 1) {
    std::ifstream fin;
    fin.open(argv[1]);
    parse(fin);
  } else {
    parse(std::cin);
  }

  return 0;
}
