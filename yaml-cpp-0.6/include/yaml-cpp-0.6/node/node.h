#ifndef NODE_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define NODE_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <stdexcept>

#include "yaml-cpp-0.6/dll.h"
#include "yaml-cpp-0.6/emitterstyle.h"
#include "yaml-cpp-0.6/mark.h"
#include "yaml-cpp-0.6/node/detail/bool_type.h"
#include "yaml-cpp-0.6/node/detail/iterator_fwd.h"
#include "yaml-cpp-0.6/node/ptr.h"
#include "yaml-cpp-0.6/node/type.h"

namespace YAML_0_6 {
namespace detail {
class node;
class node_data;
struct iterator_value;
}  // namespace detail
}  // namespace YAML_0_6

namespace YAML_0_6
{
class YAML_0_6_CPP_API Node
{
 public:
  friend class NodeBuilder;
  friend class NodeEvents;
  friend struct detail::iterator_value;
  friend class detail::node;
  friend class detail::node_data;
  template <typename>
  friend class detail::iterator_base;
  template <typename T, typename S>
  friend struct as_if;

  typedef YAML_0_6::iterator iterator;
  typedef YAML_0_6::const_iterator const_iterator;

  Node();
  explicit Node(NodeType::value type);
  template <typename T>
  explicit Node(const T& rhs);
  explicit Node(const detail::iterator_value& rhs);
  Node(const Node& rhs);
  ~Node();

  YAML_0_6::Mark Mark() const;
  NodeType::value Type() const;
  bool IsDefined() const;
  bool IsNull() const { return Type() == NodeType::Null; }
  bool IsScalar() const { return Type() == NodeType::Scalar; }
  bool IsSequence() const { return Type() == NodeType::Sequence; }
  bool IsMap() const { return Type() == NodeType::Map; }

  // bool conversions
  YAML_0_6_CPP_OPERATOR_BOOL()
  bool operator!() const { return !IsDefined(); }

  // access
  template <typename T>
  T as() const;
  template <typename T, typename S>
  T as(const S& fallback) const;
  const std::string& Scalar() const;

  const std::string& Tag() const;
  void SetTag(const std::string& tag);

  // style
  // WARNING: This API might change in future releases.
  EmitterStyle::value Style() const;
  void SetStyle(EmitterStyle::value style);

  // assignment
  bool is(const Node& rhs) const;
  template <typename T>
  Node& operator=(const T& rhs);
  Node& operator=(const Node& rhs);
  void reset(const Node& rhs = Node());

  // size/iterator
  std::size_t size() const;

  const_iterator begin() const;
  iterator begin();

  const_iterator end() const;
  iterator end();

  // sequence
  template <typename T>
  void push_back(const T& rhs);
  void push_back(const Node& rhs);

  // indexing
  template <typename Key>
  const Node operator[](const Key& key) const;
  template <typename Key>
  Node operator[](const Key& key);
  template <typename Key>
  bool remove(const Key& key);

  const Node operator[](const Node& key) const;
  Node operator[](const Node& key);
  bool remove(const Node& key);

  // map
  template <typename Key, typename Value>
  void force_insert(const Key& key, const Value& value);

 private:
  enum Zombie { ZombieNode };
  explicit Node(Zombie);
  explicit Node(detail::node& node, detail::shared_memory_holder pMemory);

  void EnsureNodeExists() const;

  template <typename T>
  void Assign(const T& rhs);
  void Assign(const char* rhs);
  void Assign(char* rhs);

  void AssignData(const Node& rhs);
  void AssignNode(const Node& rhs);

 private:
  bool m_isValid;
  mutable detail::shared_memory_holder m_pMemory;
  mutable detail::node* m_pNode;
};

YAML_0_6_CPP_API bool operator==(const Node& lhs, const Node& rhs);

YAML_0_6_CPP_API Node Clone(const Node& node);

template <typename T>
struct convert;
}

#endif  // NODE_NODE_H_62B23520_7C8E_11DE_8A39_0800200C9A66
