/*******************************************************************************
 * Copyright (C) 2022 by Andreas Zenk
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 ******************************************************************************/

#ifndef TEST_H_
#define TEST_H_

#include <iostream>
#include <string>

namespace test {

class StringContainer final {
public:
  StringContainer() noexcept : str_{"Default string."} {}
  StringContainer(std::string str) noexcept : str_{str} {}

  StringContainer &operator=(StringContainer const &other) {
    this->str_ = other.str_;
    return *this;
  }
  StringContainer(StringContainer const &other) : str_{other.str_} {}

  StringContainer &operator=(StringContainer &&other) {
    this->str_ = std::move(other.str_);
    other.str_ = "Moved-from string.";
    return *this;
  }
  StringContainer(StringContainer &&other) : str_{std::move(other.str_)} {
    other.str_ = "Moved-from string.";
  }

  std::string GetString() const noexcept { return str_; }
  void SetString(std::string str) noexcept { str_ = str; }

private:
  std::string str_;
};

//------------------------------------------------------------------------------

// For testing call to free function.
void FreeFunction(StringContainer message) noexcept;

// For testing call to free template function + testing passing template
// parameter.
template <typename T> void FreeTemplateFunction(T message) noexcept {
  std::cout << "Real FreeTemplateFunction: " << message.GetString()
            << std::endl;
}

class Normal final {
public:
  // For testing call to normal constructor.
  Normal(StringContainer content) noexcept;

  // For testing call to copy constructor.
  Normal(Normal const &other) noexcept;

  // For testing call to move constructor.
  Normal(Normal &&other) noexcept;

  // For testing call to copy assignment operator.
  Normal &operator=(Normal const &other) noexcept;

  // For testing call to move assignment operator.
  Normal &operator=(Normal &&other) noexcept;

  // For testing call to member function.
  void MemberFunction(StringContainer message) const noexcept;

  // For testing call to static member function.
  static void StaticMemberFunction(StringContainer message) noexcept;

  // For testing passing parameter by value. Use const value to test that this
  // non-relevant qualifier (foo(T const) and foo(T) are equivalent) does not
  // cause issues.
  void ParamVal(StringContainer const message) const noexcept;

  // For testing passing parameter by reference.
  void ParamRef(StringContainer &message) const noexcept;

  // For testing passing parameter by const reference.
  void ParamConstRef(StringContainer const &message) const noexcept;

  // For testing passing parameter by pointer.
  void ParamPtr(StringContainer *message) const noexcept;

  // For testing passing parameter by const pointer.
  void ParamConstPtr(StringContainer const *const message) const noexcept;

  // For testing passing parameter as move-only value.
  void ParamMove(StringContainer &&message) const noexcept;

  // For testing passing multiple parameters.
  void ParamMultiple(StringContainer message1,
                     StringContainer message2) const noexcept;

  // For testing returning by value.
  StringContainer RetVal() const noexcept;

  // For testing returning by reference.
  StringContainer &RetRef() const noexcept;

  // For testing returning by const reference.
  StringContainer const &RetConstRef() const noexcept;

  // For testing returning by pointer.
  StringContainer *RetPtr() const noexcept;

  // For testing returning by const pointer.
  StringContainer const *const RetConstPtr() const noexcept;

  // For testing returning move-only value.
  StringContainer &&RetMove() noexcept;

  // For testing overloads.
  void Overload() const noexcept;
  void Overload(StringContainer message) const noexcept;

  // For testing functions whose names are prefixes of other names.
  void Prefix() const noexcept;
  void PrefixPostfix() const noexcept;

  // For testing prefix increment operator as member.
  Normal &operator++() noexcept;

  // For testing postfix increment operator as member.
  Normal &operator++(int) noexcept;

  // For testing prefix decrement operator as member.
  Normal &operator--() noexcept;

  // For testing postfix decrement operator as member.
  Normal &operator--(int) noexcept;

  // For testing addition-assignment operator as member.
  Normal &operator+=(StringContainer &message) noexcept;

  // For testing subtraction-assignment operator as member.
  Normal &operator-=(StringContainer &message) noexcept;

  // For testing multiplication-assignment operator as member.
  Normal &operator*=(StringContainer &message) noexcept;

  // For testing division-assignment operator as member.
  Normal &operator/=(StringContainer &message) noexcept;

  // For testing modulo-assignment operator as member.
  Normal &operator%=(StringContainer &message) noexcept;

  // For testing bitwise-xor-assignment operator as member.
  Normal &operator^=(StringContainer &message) noexcept;

  // For testing bitwise-and-assignment operator as member.
  Normal &operator&=(StringContainer &message) noexcept;

  // For testing bitwise-or-assignment operator as member.
  Normal &operator|=(StringContainer &message) noexcept;

  // For testing right-bitshift-assignment operator as member.
  Normal &operator>>=(StringContainer &message) noexcept;

  // For testing left-bitshift-assignment operator as member.
  Normal &operator<<=(StringContainer &message) noexcept;

  // For testing non-equal operator as member.
  bool operator!=(StringContainer const &message) const noexcept;

  // For testing less-or-equal operator as member.
  bool operator<=(StringContainer const &message) const noexcept;

  // For testing greater-or-equal operator as member.
  bool operator>=(StringContainer const &message) const noexcept;

  // For testing equality operator as member.
  bool operator==(StringContainer const &message) const noexcept;

  // For testing right-bitshift operator as member.
  Normal &operator>>(StringContainer &message) noexcept;

  // For testing left-bitshift operator as member.
  Normal &operator<<(StringContainer &message) noexcept;

  // For testing function call operator as member.
  StringContainer &operator()(StringContainer &message) noexcept;

  // For testing array access operator as member.
  StringContainer &operator[](StringContainer &message) noexcept;

  // For testing logical-and operator as member.
  bool operator&&(StringContainer &message) const noexcept;

  // For testing logical-or operator as member.
  bool operator||(StringContainer &message) const noexcept;

  // For testing negation operator as member.
  bool operator!() const noexcept;

  // For testing addition operator as member.
  StringContainer operator+(StringContainer &message) const noexcept;

  // For testing subtraction operator as member.
  StringContainer operator-(StringContainer &message) const noexcept;

  // For testing multiplication operator as member.
  StringContainer operator*(StringContainer &message) const noexcept;

  // For testing division operator as member.
  StringContainer operator/(StringContainer &message) const noexcept;

  // For testing modulo operator as member.
  StringContainer operator%(StringContainer &message) const noexcept;

  // For testing bitwise-xor operator as member.
  StringContainer operator^(StringContainer &message) const noexcept;

  // For testing bitwise-and operator as member.
  StringContainer operator&(StringContainer &message) const noexcept;

  // For testing bitwise-or operator as member.
  StringContainer operator|(StringContainer &message) const noexcept;

  // For testing bitwise-negation operator as member.
  StringContainer operator~() const noexcept;

  // For testing less-than operator as member.
  bool operator<(StringContainer &message) const noexcept;

  // For testing greater-than operator as member.
  bool operator>(StringContainer &message) const noexcept;

  // For testing comma operator as member.
  StringContainer operator,(StringContainer &message) const noexcept;

  // For testing pointer dereference operator as member.
  StringContainer operator*() const noexcept;

  // For testing address-of operator as member.
  Normal *operator&() noexcept;

  StringContainer content_;
  // WARNING: move_content_ is moved-from by member
  StringContainer move_content_{};
};

class Base {
public:
  Base(StringContainer content) noexcept;

  // For testing call to virtual function.
  virtual void Virt(StringContainer message) const noexcept;

  // For testing call to virtual function.
  virtual void PureVirt(StringContainer message) const noexcept = 0;

  StringContainer content_;
};

class Derived final : public Base {
public:
  Derived(StringContainer content) noexcept;

  // For testing call to virtual function.
  void Virt(StringContainer message) const noexcept final;

  // For testing call to virtual function.
  virtual void PureVirt(StringContainer message) const noexcept final;
};

// For testing call no non-overriden virtual function.
class NonOverride final : public Base {
public:
  NonOverride(StringContainer content) noexcept;
  virtual void PureVirt(StringContainer) const noexcept final {}
};

template <typename ClassType> class Template final {
public:
  Template(ClassType input) noexcept;

  // For testing call to member function of template class.
  void Member(StringContainer message) const noexcept;

  // For testing call to template member function of template class.
  template <typename FunctionType>
  void TemplateMember(FunctionType message) const noexcept;

  ClassType content_;
};

template <typename ClassType>
Template<ClassType>::Template(ClassType message) noexcept : content_{message} {}

template <typename ClassType>
void Template<ClassType>::Member(StringContainer message) const noexcept {
  std::cout << "Real Member, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

template <typename ClassType>
template <typename FunctionType>
void Template<ClassType>::TemplateMember(FunctionType message) const noexcept {
  std::cout << "Real TemplateMember, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

// For testing prefix increment operator as free function.
StringContainer &operator++(StringContainer &message) noexcept;

// For testing postfix increment operator as free function.
StringContainer operator++(StringContainer &message, int) noexcept;

// For testing prefix decrement operator as free function.
StringContainer &operator--(StringContainer &message) noexcept;

// For testing postfix decrement operator as free function.
StringContainer operator--(StringContainer &message, int) noexcept;

// For testing addition-assignment operator as free function.
StringContainer &operator+=(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing subtraction-assignment operator as free function.
StringContainer &operator-=(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing multiplication-assignment operator as free function.
StringContainer &operator*=(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing division-assignment operator as free function.
StringContainer &operator/=(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing modulo-assignment operator as free function.
StringContainer &operator%=(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing bitwise-xor-assignment operator as free function.
StringContainer &operator^=(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing bitwise-and-assignment operator as free function.
StringContainer &operator&=(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing bitwise-or-assignment operator as free function.
StringContainer &operator|=(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing right-bitshift-assignment operator as free function.
StringContainer &operator>>=(StringContainer &message1,
                             StringContainer &message2) noexcept;

// For testing left-bitshift-assignment operator as free function.
StringContainer &operator<<=(StringContainer &message1,
                             StringContainer &message2) noexcept;

// For testing non-equal operator as free function.
bool operator!=(StringContainer const &message1,
                StringContainer const &message2) noexcept;

// For testing less-or-equal operator as free function.
bool operator<=(StringContainer const &message1,
                StringContainer const &message2) noexcept;

// For testing greater-or-equal operator as free function.
bool operator>=(StringContainer const &message1,
                StringContainer const &message2) noexcept;

// For testing equality operator as free function.
bool operator==(StringContainer const &message1,
                StringContainer const &message2) noexcept;

// For testing right-bitshift operator as free function.
StringContainer &operator>>(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing left-bitshift operator as free function.
StringContainer &operator<<(StringContainer &message1,
                            StringContainer &message2) noexcept;

// For testing logical-and operator as free function.
bool operator&&(StringContainer &message1, StringContainer &message2) noexcept;

// For testing logical-or operator as free function.
bool operator||(StringContainer &message1, StringContainer &message2) noexcept;

// For testing negation operator as free function.
bool operator!(StringContainer &message) noexcept;

// For testing addition operator as free function.
StringContainer operator+(StringContainer &message1,
                          StringContainer &message2) noexcept;

// For testing subtraction operator as free function.
StringContainer operator-(StringContainer &message1,
                          StringContainer &message2) noexcept;

// For testing multiplication operator as free function.
StringContainer operator*(StringContainer &message1,
                          StringContainer &message2) noexcept;

// For testing division operator as free function.
StringContainer operator/(StringContainer &message1,
                          StringContainer &message2) noexcept;

// For testing modulo operator as free function.
StringContainer operator%(StringContainer &message1,
                          StringContainer &message2) noexcept;

// For testing bitwise-xor operator as free function.
StringContainer operator^(StringContainer &message1,
                          StringContainer &message2) noexcept;

// For testing bitwise-and operator as free function.
StringContainer operator&(StringContainer &message1,
                          StringContainer &message2) noexcept;

// For testing bitwise-or operator as free function.
StringContainer operator|(StringContainer &message1,
                          StringContainer &message2) noexcept;

// For testing bitwise-negation operator as free function.
StringContainer operator~(StringContainer &message) noexcept;

// For testing less-than operator as free function.
bool operator<(StringContainer &message1, StringContainer &message2) noexcept;

// For testing greater-than operator as free function.
bool operator>(StringContainer &message1, StringContainer &message2) noexcept;

// For testing comma operator as free function.
StringContainer operator,(StringContainer &message1,
                          StringContainer &message2) noexcept;

// For testing pointer dereference operator as free function.
StringContainer operator*(StringContainer &message) noexcept;

// For testing address-of operator as free function.
StringContainer *operator&(StringContainer &message) noexcept;

} // namespace test

#endif // TEST_H_
