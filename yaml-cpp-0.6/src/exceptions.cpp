#include "yaml-cpp-0.6/exceptions.h"

// This is here for compatibility with older versions of Visual Studio
// which don't support noexcept
#if defined(_MSC_VER) && _MSC_VER < 1900
    #define YAML_0_6_CPP_NOEXCEPT _NOEXCEPT
#else
    #define YAML_0_6_CPP_NOEXCEPT noexcept
#endif

namespace YAML_0_6 {

// These destructors are defined out-of-line so the vtable is only emitted once.
Exception::~Exception() YAML_0_6_CPP_NOEXCEPT {}
ParserException::~ParserException() YAML_0_6_CPP_NOEXCEPT {}
RepresentationException::~RepresentationException() YAML_0_6_CPP_NOEXCEPT {}
InvalidScalar::~InvalidScalar() YAML_0_6_CPP_NOEXCEPT {}
KeyNotFound::~KeyNotFound() YAML_0_6_CPP_NOEXCEPT {}
InvalidNode::~InvalidNode() YAML_0_6_CPP_NOEXCEPT {}
BadConversion::~BadConversion() YAML_0_6_CPP_NOEXCEPT {}
BadDereference::~BadDereference() YAML_0_6_CPP_NOEXCEPT {}
BadSubscript::~BadSubscript() YAML_0_6_CPP_NOEXCEPT {}
BadPushback::~BadPushback() YAML_0_6_CPP_NOEXCEPT {}
BadInsert::~BadInsert() YAML_0_6_CPP_NOEXCEPT {}
EmitterException::~EmitterException() YAML_0_6_CPP_NOEXCEPT {}
BadFile::~BadFile() YAML_0_6_CPP_NOEXCEPT {}
}

#undef YAML_0_6_CPP_NOEXCEPT
