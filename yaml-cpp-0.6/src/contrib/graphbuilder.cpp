#include "graphbuilderadapter.h"

#include "yaml-cpp-0.6/parser.h"  // IWYU pragma: keep

namespace YAML_0_6 {
class GraphBuilderInterface;

void* BuildGraphOfNextDocument(Parser& parser,
                               GraphBuilderInterface& graphBuilder) {
  GraphBuilderAdapter eventHandler(graphBuilder);
  if (parser.HandleNextDocument(eventHandler)) {
    return eventHandler.RootNode();
  } else {
    return nullptr;
  }
}
}
