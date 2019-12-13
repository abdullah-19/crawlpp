//===----------------------------------------------------------------------===//
//
//                              Crawlpp 
//
//===----------------------------------------------------------------------===//
//
//  Copyright (C) 2019. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#ifndef _STRINGREF_
#define _STRINGREF_

#include <algorithm>
#include <cassert>
#include <string>
#include <type_traits>

namespace crawlpp {

// https://llvm.org/doxygen/StringRef_8h_source.html
class StringRef {
public:
  using iterator = const char *;
  using const_iterator = const char *;
  using size_type = size_t;

private:
  /// The start of the string, in an external buffer.
  const char *Data = nullptr;

  /// The length of the string.
  size_t Length = 0;

  // Workaround memcmp issue with null pointers (undefined behavior)
  // by providing a specialized version
  static int compareMemory(const char *Lhs, const char *Rhs, size_t Length) {
    if (Length == 0) {
      return 0;
    }
    return ::memcmp(Lhs, Rhs, Length);
  }

  // Constexpr version of std::strlen.
  static constexpr size_t strLen(const char *Str) {
#if __cplusplus > 201402L
    return std::char_traits<char>::length(Str);
#elif __has_builtin(__builtin_strlen) || defined(__GNUC__)
    return __builtin_strlen(Str);
#else
    const char *Begin = Str;
    while (*Str != '\0')
      ++Str;
    return Str - Begin;
#endif
  }

public:
  StringRef() = default;
  StringRef(std::nullptr_t) = delete;
  constexpr StringRef(const char *Str)
      : Data(Str), Length(Str ? strLen(Str) : 0) {}
  constexpr StringRef(const char *data, size_t len) : Data(data), Length(len) {}

  StringRef(const std::string &Str) : Data(Str.data()), Length(Str.length()) {}

  iterator begin() const { return Data; }

  iterator end() const { return Data + Length; }

  const char *data() const { return Data; }

  bool empty() const { return Length == 0; }

  size_t size() const { return Length; }

  char front() const {
    assert(!empty());
    return Data[0];
  }

  char back() const {
    assert(!empty());
    return Data[Length - 1];
  }

  bool equlas(StringRef RHS) const {
    return (Length == RHS.Length &&
            compareMemory(Data, RHS.Data, RHS.Length) == 0);
  }

  int compare(StringRef RHS) const {
    // Check the prefix for a mismatch.
    if (int Res = compareMemory(Data, RHS.Data, std::min(Length, RHS.Length)))
      return Res < 0 ? -1 : 1;

    // Otherwise the prefixes match, so we only need to check the lengths.
    if (Length == RHS.Length)
      return 0;
    return Length < RHS.Length ? -1 : 1;
  }

  std::string str() const {
    if (!Data)
      return std::string();
    return std::string(Data, Length);
  }

  char operator[](size_t Index) const {
    assert(Index < Length && "Invalid index!");
    return Data[Index];
  }

  operator std::string() const { return str(); }
};

} // namespace pytype

#endif