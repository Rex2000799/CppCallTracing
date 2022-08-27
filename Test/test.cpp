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

#include <iostream>
#include <memory>
#include <utility>

#include "test.h"

namespace test {

void FreeFunction(StringContainer message) noexcept {
  std::cout << "Real FreeFunction: " << message.GetString() << std::endl;
}

template void FreeTemplateFunction<StringContainer>(StringContainer);

Normal::Normal(StringContainer content) noexcept : content_{content} {
  std::cout << "Real ctor, content: " << content_.GetString() << std::endl;
}

Normal::Normal(Normal const &other) noexcept : content_{other.content_} {
  std::cout << "Real copy ctor, content: " << content_.GetString() << std::endl;
}

Normal::Normal(Normal &&other) noexcept : content_{other.content_} {
  std::cout << "Real move ctor, content: " << content_.GetString() << std::endl;
}

Normal &Normal::operator=(Normal const &other) noexcept {
  std::cout << "Real copy assignment operator, content: "
            << content_.GetString() << ", input: " << other.content_.GetString()
            << std::endl;
  content_.SetString(other.content_.GetString());
  return *this;
}

Normal &Normal::operator=(Normal &&other) noexcept {
  std::cout << "Real move assignment operator, content " << content_.GetString()
            << ", input: " << other.content_.GetString() << std::endl;
  content_.SetString(other.content_.GetString());
  return *this;
}

void Normal::MemberFunction(StringContainer message) const noexcept {
  std::cout << "Real MemberFunction, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

void Normal::StaticMemberFunction(StringContainer message) noexcept {
  std::cout << "Real StaticMemberFunction, input: " << message.GetString()
            << std::endl;
}

void Normal::ParamVal(StringContainer const message) const noexcept {
  std::cout << "Real ParamVal, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

void Normal::ParamRef(StringContainer &message) const noexcept {
  std::cout << "Real ParamRef, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

void Normal::ParamConstRef(StringContainer const &message) const noexcept {
  std::cout << "Real ParamConstRef, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

void Normal::ParamPtr(StringContainer *message) const noexcept {
  std::cout << "Real ParamPtr, content: " << content_.GetString()
            << ", input: " << message->GetString() << std::endl;
}

void Normal::ParamConstPtr(
    StringContainer const *const message) const noexcept {
  std::cout << "Real ParamConstPtr, content: " << content_.GetString()
            << ", input: " << message->GetString() << std::endl;
}

void Normal::ParamMove(StringContainer &&message) const noexcept {
  std::cout << "Real ParamMove, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

void Normal::ParamMultiple(StringContainer message1,
                           StringContainer message2) const noexcept {
  std::cout << "Real ParamMultiple, content: " << content_.GetString()
            << ", input 1: " << message1.GetString()
            << ", input 2: " << message2.GetString() << std::endl;
}

StringContainer Normal::RetVal() const noexcept {
  std::cout << "Real RetVal, content: " << content_.GetString() << std::endl;
  return StringContainer{"Returning by value."};
}

StringContainer &Normal::RetRef() const noexcept {
  std::cout << "Real RetRef, content: " << content_.GetString() << std::endl;
  // Using a static variable will implicitly test that the tooling takes the
  // mangled name of the function itself and does not confuse it with the
  // name of the variable (as both names may have same infixes).
  static StringContainer reference_target{"Returning by reference."};
  return reference_target;
}

StringContainer const &Normal::RetConstRef() const noexcept {
  std::cout << "Real RetConstRef, content: " << content_.GetString()
            << std::endl;
  // Using a static variable will implicitly test that the tooling takes the
  // mangled name of the function itself and does not confuse it with the
  // name of the variable (as both names may have same infixes).
  static StringContainer reference_target{"Returning by const reference."};
  return reference_target;
}

StringContainer *Normal::RetPtr() const noexcept {
  std::cout << "Real RetPtr, content: " << content_.GetString() << std::endl;
  // Using a static variable will implicitly test that the tooling takes the
  // mangled name of the function itself and does not confuse it with the
  // name of the variable (as both names may have same infixes).
  static StringContainer pointer_target{"Returning by pointer."};
  return std::addressof(pointer_target);
}

StringContainer const *const Normal::RetConstPtr() const noexcept {
  std::cout << "Real RetConstPtr, content: " << content_.GetString()
            << std::endl;
  // Using a static variable will implicitly test that the tooling takes the
  // mangled name of the function itself and does not confuse it with the
  // name of the variable (as both names may have same infixes).
  static StringContainer pointer_target{"Returning by const pointer."};
  return std::addressof(pointer_target);
}

StringContainer &&Normal::RetMove() noexcept {
  std::cout << "Real RetMove, content: " << content_.GetString() << std::endl;
  move_content_ = StringContainer{"Returning by move."};
  return std::move(move_content_);
}

void Normal::Overload() const noexcept {
  std::cout << "Real Overload(), content: " << content_.GetString()
            << std::endl;
}

void Normal::Overload(StringContainer message) const noexcept {
  std::cout << "Real Overload(StringContainer), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
}

void Normal::Prefix() const noexcept {
  std::cout << "Real Prefix(), content: " << content_.GetString() << std::endl;
}

void Normal::PrefixPostfix() const noexcept {
  std::cout << "Real PrefixPostfix(), content: " << content_.GetString()
            << std::endl;
}

Normal &Normal::operator++() noexcept {
  std::cout << "Real prefix increment operator (member), content: "
            << content_.GetString() << std::endl;
  return *this;
}

Normal &Normal::operator++(int) noexcept {
  std::cout << "Real postfix increment operator (member), content: "
            << content_.GetString() << std::endl;
  return *this;
}

Normal &Normal::operator--() noexcept {
  std::cout << "Real prefix decrement operator (member), content: "
            << content_.GetString() << std::endl;
  return *this;
}

Normal &Normal::operator--(int) noexcept {
  std::cout << "Real postfix decrement operator (member), content: "
            << content_.GetString() << std::endl;
  return *this;
}

Normal &Normal::operator+=(StringContainer &message) noexcept {
  std::cout << "Real addition-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator-=(StringContainer &message) noexcept {
  std::cout << "Real subtraction-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator*=(StringContainer &message) noexcept {
  std::cout << "Real multiplication-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator/=(StringContainer &message) noexcept {
  std::cout << "Real division-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator%=(StringContainer &message) noexcept {
  std::cout << "Real modulo-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator^=(StringContainer &message) noexcept {
  std::cout << "Real bitwise-xor-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator&=(StringContainer &message) noexcept {
  std::cout << "Real bitwise-and-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator|=(StringContainer &message) noexcept {
  std::cout << "Real bitwise-or-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator>>=(StringContainer &message) noexcept {
  std::cout << "Real right-bitshift-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator<<=(StringContainer &message) noexcept {
  std::cout << "Real left-bitshift-assignment operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

bool Normal::operator!=(StringContainer const &message) const noexcept {
  std::cout << "Real non-equal operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return true;
}

bool Normal::operator<=(StringContainer const &message) const noexcept {
  std::cout << "Real less-or-equal operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return true;
}

bool Normal::operator>=(StringContainer const &message) const noexcept {
  std::cout << "Real greater-or-equal operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return true;
}

bool Normal::operator==(StringContainer const &message) const noexcept {
  std::cout << "Real equality operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return true;
}

Normal &Normal::operator>>(StringContainer &message) noexcept {
  std::cout << "Real right-bitshift operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

Normal &Normal::operator<<(StringContainer &message) noexcept {
  std::cout << "Real left-bitshift operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return *this;
}

StringContainer &Normal::operator()(StringContainer &message) noexcept {
  std::cout << "Real function call operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

StringContainer &Normal::operator[](StringContainer &message) noexcept {
  std::cout << "Real array-access operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

bool Normal::operator&&(StringContainer &message) const noexcept {
  std::cout << "Real logical-and operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return true;
}

bool Normal::operator||(StringContainer &message) const noexcept {
  std::cout << "Real logical-or operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return true;
}

bool Normal::operator!() const noexcept {
  std::cout << "Real negation operator (member), content: "
            << content_.GetString() << std::endl;
  return true;
}

StringContainer Normal::operator+(StringContainer &message) const noexcept {
  std::cout << "Real addition operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

StringContainer Normal::operator-(StringContainer &message) const noexcept {
  std::cout << "Real subtraction operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

StringContainer Normal::operator*(StringContainer &message) const noexcept {
  std::cout << "Real multiplication operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

StringContainer Normal::operator/(StringContainer &message) const noexcept {
  std::cout << "Real division operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

StringContainer Normal::operator%(StringContainer &message) const noexcept {
  std::cout << "Real modulo operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

StringContainer Normal::operator^(StringContainer &message) const noexcept {
  std::cout << "Real bitwise-xor operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

StringContainer Normal::operator&(StringContainer &message) const noexcept {
  std::cout << "Real bitwise-and operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

StringContainer Normal::operator|(StringContainer &message) const noexcept {
  std::cout << "Real bitwise-or operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return message;
}

StringContainer Normal::operator~() const noexcept {
  std::cout << "Real bitwise-negation operator (member), content: "
            << content_.GetString() << std::endl;
  return content_;
}

bool Normal::operator<(StringContainer &message) const noexcept {
  std::cout << "Real less-than operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return true;
}

bool Normal::operator>(StringContainer &message) const noexcept {
  std::cout << "Real greater-than operator (member), content: "
            << content_.GetString() << ", input : " << message.GetString()
            << std::endl;
  return true;
}

StringContainer Normal::operator,(StringContainer &message) const noexcept {
  std::cout << "Real comma operator (member), content: " << content_.GetString()
            << ", input : " << message.GetString() << std::endl;
  return message;
}

StringContainer Normal::operator*() const noexcept {
  std::cout << "Real pointer-dereference operator (member), content: "
            << content_.GetString() << std::endl;
  return content_;
}

Normal *Normal::operator&() noexcept {
  std::cout << "Real address-of operator (member), content: "
            << content_.GetString() << std::endl;
  return this;
}

Base::Base(StringContainer content) noexcept : content_{content} {}

void Base::Virt(StringContainer message) const noexcept {
  std::cout << "Real Base::Virt, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

Derived::Derived(StringContainer content) noexcept : Base{content} {}

void Derived::Virt(StringContainer message) const noexcept {
  std::cout << "Real Derived::Virt, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

void Derived::PureVirt(StringContainer message) const noexcept {
  std::cout << "Real Derived::PureVirt, content: " << content_.GetString()
            << ", input: " << message.GetString() << std::endl;
}

NonOverride::NonOverride(StringContainer content) noexcept : Base{content} {}

template Template<StringContainer>::Template(StringContainer message) noexcept;

template void
Template<StringContainer>::Member(StringContainer message) const noexcept;

template void Template<StringContainer>::TemplateMember<StringContainer>(
    StringContainer message) const noexcept;

StringContainer &operator++(StringContainer &message) noexcept {
  std::cout << "Real prefix increment operator (free function), input: "
            << message.GetString() << std::endl;
  return message;
}

StringContainer operator++(StringContainer &message, int) noexcept {
  std::cout << "Real postfix increment operator (free function), input: "
            << message.GetString() << std::endl;
  return message;
}

StringContainer &operator--(StringContainer &message) noexcept {
  std::cout << "Real prefix decrement operator (free function), input: "
            << message.GetString() << std::endl;
  return message;
}

StringContainer operator--(StringContainer &message, int) noexcept {
  std::cout << "Real postfix decrement operator (free function), input: "
            << message.GetString() << std::endl;
  return message;
}

StringContainer &operator+=(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout << "Real addition-assignment operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer &operator-=(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout << "Real subtraction-assignment operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer &operator*=(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout
      << "Real multiplication-assignment operator (free function), input 1: "
      << message1.GetString() << ", input 2: " << message2.GetString()
      << std::endl;
  return message1;
}

StringContainer &operator/=(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout << "Real division-assignment operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer &operator%=(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout << "Real modulo-assignment operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer &operator^=(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout << "Real bitwise-xor-assignment operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer &operator&=(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout << "Real bitwise-and-assignment operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer &operator|=(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout << "Real bitwise-or-assignment operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer &operator>>=(StringContainer &message1,
                             StringContainer &message2) noexcept {
  std::cout
      << "Real right-bitshift-assignment operator (free function), input 1: "
      << message1.GetString() << ", input 2: " << message2.GetString()
      << std::endl;
  return message1;
}

StringContainer &operator<<=(StringContainer &message1,
                             StringContainer &message2) noexcept {
  std::cout
      << "Real left-bitshift-assignment operator (free function), input 1: "
      << message1.GetString() << ", input 2: " << message2.GetString()
      << std::endl;
  return message1;
}

bool operator!=(StringContainer const &message1,
                StringContainer const &message2) noexcept {
  std::cout << "Real non-equal operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return true;
}

bool operator<=(StringContainer const &message1,
                StringContainer const &message2) noexcept {
  std::cout << "Real less-or-equal operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return true;
}

bool operator>=(StringContainer const &message1,
                StringContainer const &message2) noexcept {
  std::cout << "Real greater-or-equal operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return true;
}

bool operator==(StringContainer const &message1,
                StringContainer const &message2) noexcept {
  std::cout << "Real equality operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return true;
}

StringContainer &operator>>(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout << "Real right-bitshift operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer &operator<<(StringContainer &message1,
                            StringContainer &message2) noexcept {
  std::cout << "Real left-bitshift operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

bool operator&&(StringContainer &message1, StringContainer &message2) noexcept {
  std::cout << "Real logical-and operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return true;
}

bool operator||(StringContainer &message1, StringContainer &message2) noexcept {
  std::cout << "Real logical-or operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return true;
}

bool operator!(StringContainer &message) noexcept {
  std::cout << "Real negation operator (free function), input: "
            << message.GetString() << std::endl;
  return true;
}

StringContainer operator+(StringContainer &message1,
                          StringContainer &message2) noexcept {
  std::cout << "Real addition operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer operator-(StringContainer &message1,
                          StringContainer &message2) noexcept {
  std::cout << "Real subtraction operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer operator*(StringContainer &message1,
                          StringContainer &message2) noexcept {
  std::cout << "Real multiplication operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer operator/(StringContainer &message1,
                          StringContainer &message2) noexcept {
  std::cout << "Real division operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer operator%(StringContainer &message1,
                          StringContainer &message2) noexcept {
  std::cout << "Real modulo operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer operator^(StringContainer &message1,
                          StringContainer &message2) noexcept {
  std::cout << "Real bitwise-xor operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer operator&(StringContainer &message1,
                          StringContainer &message2) noexcept {
  std::cout << "Real bitwise-and operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer operator|(StringContainer &message1,
                          StringContainer &message2) noexcept {
  std::cout << "Real bitwise-or operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer operator~(StringContainer &message) noexcept {
  std::cout << "Real bitwise-negation operator (free function), input: "
            << message.GetString() << std::endl;
  return message;
}

bool operator<(StringContainer &message1, StringContainer &message2) noexcept {
  std::cout << "Real less-than operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return true;
}

bool operator>(StringContainer &message1, StringContainer &message2) noexcept {
  std::cout << "Real greater-than operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return true;
}

StringContainer operator,(StringContainer &message1,
                          StringContainer &message2) noexcept {
  std::cout << "Real comma operator (free function), input 1: "
            << message1.GetString() << ", input 2: " << message2.GetString()
            << std::endl;
  return message1;
}

StringContainer operator*(StringContainer &message) noexcept {
  std::cout << "Real pointer-dereference operator (free function), input: "
            << message.GetString() << std::endl;
  return message;
}

StringContainer *operator&(StringContainer &message) noexcept {
  std::cout << "Real address-of operator (free function), input: "
            << message.GetString() << std::endl;
  return std::addressof(message);
}

} // namespace test
