#include <iostream>

#include "yaml-cpp-0.6/emitterstyle.h"
#include "yaml-cpp-0.6/eventhandler.h"
#include "yaml-cpp-0.6/yaml.h"  // IWYU pragma: keep

class NullEventHandler : public YAML_0_6::EventHandler {
 public:
  typedef YAML_0_6::Mark Mark;
  typedef YAML_0_6::anchor_t anchor_t;

  NullEventHandler() {}

  virtual void OnDocumentStart(const Mark&) {}
  virtual void OnDocumentEnd() {}
  virtual void OnNull(const Mark&, anchor_t) {}
  virtual void OnAlias(const Mark&, anchor_t) {}
  virtual void OnScalar(const Mark&, const std::string&, anchor_t,
                        const std::string&) {}
  virtual void OnSequenceStart(const Mark&, const std::string&, anchor_t,
                               YAML_0_6::EmitterStyle::value style) {}
  virtual void OnSequenceEnd() {}
  virtual void OnMapStart(const Mark&, const std::string&, anchor_t,
                          YAML_0_6::EmitterStyle::value style) {}
  virtual void OnMapEnd() {}
};

int main() {
  YAML_0_6::Node root;

  for (;;) {
    YAML_0_6::Node node;
    root = node;
  }
  return 0;
}
