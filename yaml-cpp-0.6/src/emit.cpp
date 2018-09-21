#include "yaml-cpp-0.6/node/emit.h"
#include "yaml-cpp-0.6/emitfromevents.h"
#include "yaml-cpp-0.6/emitter.h"
#include "nodeevents.h"

namespace YAML_0_6 {
Emitter& operator<<(Emitter& out, const Node& node) {
  EmitFromEvents emitFromEvents(out);
  NodeEvents events(node);
  events.Emit(emitFromEvents);
  return out;
}

std::ostream& operator<<(std::ostream& out, const Node& node) {
  Emitter emitter(out);
  emitter << node;
  return out;
}

std::string Dump(const Node& node) {
  Emitter emitter;
  emitter << node;
  return emitter.c_str();
}
}  // namespace YAML_0_6
