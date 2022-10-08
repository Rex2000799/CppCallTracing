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

void RunTests() {
  // ---------------------------------------------------------------------------
  // Test inputs.
  // ---------------------------------------------------------------------------

  // Inputs for function calls.
  test::StringContainer message1{"Test Message 1"};
  test::StringContainer message2{"Test Message 2"};
  test::StringContainer message3{"Test Message 3"}; // Overwritten later.

  // Data held by objects.
  test::StringContainer content1{"Content 1"};
  test::StringContainer content2{"Content 2"};

  test::StringContainer derived_message{"test message derived class call"};
  test::StringContainer base_ref_message{
      "test message base class call reference"};
  test::StringContainer base_refconst_message{
      "test message base class call const reference"};
  test::StringContainer base_ptr_message{
      "test message base class call pointer"};
  test::StringContainer base_ptrconst_message{
      "test message base class call const pointer"};
  test::StringContainer non_override_message{"test message non-override call"};

  // ---------------------------------------------------------------------------
  // Objects to run tests on.
  // ---------------------------------------------------------------------------

  test::Normal inst1{content1};
  test::Normal inst2{content2};

  test::Derived virtinst{content1};
  test::Base &baseref{virtinst};
  test::Base &baseconstref{virtinst};
  test::Base *baseptr{&virtinst};
  test::Base const *const baseconstptr{&virtinst};
  test::NonOverride nonoverrideinst{content1};

  test::Template<test::StringContainer> templ{content1};

  // ---------------------------------------------------------------------------
  // Free normal functions.
  // ---------------------------------------------------------------------------

  test::FreeFunction(message1);
  test::FreeTemplateFunction(message1);

  // ---------------------------------------------------------------------------
  // Class special member functions.
  // ---------------------------------------------------------------------------

  test::Normal inst3{inst1};            // Copy Ctor
  inst3 = inst2;                        // Copy assignment operator
  test::Normal inst4{std::move(inst3)}; // Move Ctor
  inst3 = std::move(inst4);             // Move assignment operator

  // ---------------------------------------------------------------------------
  // Normal class member functions.
  // ---------------------------------------------------------------------------

  inst1.MemberFunction(message1);
  test::Normal::StaticMemberFunction(message1);
  inst1.ParamVal(message1);
  inst1.ParamRef(message1);
  inst1.ParamConstRef(message1);
  inst1.ParamPtr(std::addressof(message1));
  inst1.ParamConstPtr(std::addressof(message1));
  inst1.ParamMove(std::move(message3));
  inst1.ParamMultiple(message1, message2);

  message3 = inst1.RetVal();
  std::cout << "RetVal() returned " << message3.GetString() << std::endl;
  message3 = inst1.RetRef();
  std::cout << "RetRef() returned " << message3.GetString() << std::endl;
  message3 = inst1.RetConstRef();
  std::cout << "RetConstRef() returned " << message3.GetString() << std::endl;
  test::StringContainer *message_ptr{inst1.RetPtr()};
  std::cout << "RetPtr() returned " << message_ptr->GetString() << std::endl;
  test::StringContainer const *const message_const_ptr{inst1.RetConstPtr()};
  std::cout << "RetConstPtr() returned " << message_const_ptr->GetString()
            << std::endl;
  message3 = inst1.RetMove();
  std::cout << "RetMove() returned " << message3.GetString() << std::endl;

  inst1.Overload();
  inst1.Overload(message1);

  inst1.Prefix();
  inst1.PrefixPostfix();

  // ---------------------------------------------------------------------------
  // Operator overloads in class.
  // ---------------------------------------------------------------------------

  ++inst1;
  inst1++;
  --inst1;
  inst1--;

  inst1 += message1;
  inst1 -= message1;
  inst1 *= message1;
  inst1 /= message1;
  inst1 %= message1;
  inst1 ^= message1;
  inst1 &= message1;
  inst1 |= message1;
  inst1 >>= message1;
  inst1 <<= message1;

  bool const res_neq_member{inst1 != message1};
  std::cout << "operator!= (member) returned "
            << (res_neq_member ? "true" : "false") << std::endl;
  bool const res_le_member{inst1 <= message1};
  std::cout << "operator<= (member) returned "
            << (res_le_member ? "true" : "false") << std::endl;
  bool const res_ge_member{inst1 >= message1};
  std::cout << "operator>= (member) returned "
            << (res_ge_member ? "true" : "false") << std::endl;
  bool const res_eq_member{inst1 == message1};
  std::cout << "operator== (member) returned "
            << (res_eq_member ? "true" : "false") << std::endl;

  inst1 >> message1;
  inst1 << message1;

  message3 = inst1(message1);
  std::cout << "operator() returned " << message3.GetString() << std::endl;
  message3 = inst1[message1];
  std::cout << "operator[] returned " << message3.GetString() << std::endl;

  bool const res_and_member{inst1 && message1};
  std::cout << "operator&& (member) returned "
            << (res_and_member ? "true" : "false") << std::endl;
  bool const res_or_member{inst1 || message1};
  std::cout << "operator|| (member) returned "
            << (res_or_member ? "true" : "false") << std::endl;
  bool const res_not_member{!inst1};
  std::cout << "operator! (member) returned "
            << (res_not_member ? "true" : "false") << std::endl;

  message3 = inst1 + message1;
  std::cout << "operator+ (member) returned " << message3.GetString()
            << std::endl;
  message3 = inst1 - message1;
  std::cout << "operator- (member) returned " << message3.GetString()
            << std::endl;
  message3 = inst1 * message1;
  std::cout << "operator* (member) returned " << message3.GetString()
            << std::endl;
  message3 = inst1 / message1;
  std::cout << "operator/ (member) returned " << message3.GetString()
            << std::endl;
  message3 = inst1 % message1;
  std::cout << "operator% (member) returned " << message3.GetString()
            << std::endl;
  message3 = inst1 ^ message1;
  std::cout << "operator^ (member) returned " << message3.GetString()
            << std::endl;
  message3 = inst1 & message1;
  std::cout << "operator& (member) returned " << message3.GetString()
            << std::endl;
  message3 = inst1 | message1;
  std::cout << "operator| (member) returned " << message3.GetString()
            << std::endl;
  message3 = ~inst1;
  std::cout << "operator~ (member) returned " << message3.GetString()
            << std::endl;

  bool const res_lt_member{inst1 < message1};
  std::cout << "operator< (member) returned "
            << (res_lt_member ? "true" : "false") << std::endl;
  bool const res_gt_member{inst1 > message1};
  std::cout << "operator> (member) returned "
            << (res_gt_member ? "true" : "false") << std::endl;

  message3 = (inst1, message1);
  std::cout << "operator, (member) returned " << message3.GetString()
            << std::endl;
  message3 = *inst1;
  std::cout << "operator* (member) returned " << message3.GetString()
            << std::endl;
  test::Normal *inst_ptr_member{&inst1};
  std::cout << "operator& (member) returned "
            << inst_ptr_member->content_.GetString() << std::endl;

  // ---------------------------------------------------------------------------
  // Virtual functions.
  // ---------------------------------------------------------------------------

  virtinst.Virt(derived_message);
  virtinst.PureVirt(derived_message);

  baseref.Virt(base_ref_message);
  baseref.PureVirt(base_ref_message);

  baseconstref.Virt(base_refconst_message);
  baseconstref.PureVirt(base_refconst_message);

  baseptr->Virt(base_ptr_message);
  baseptr->PureVirt(base_ptr_message);

  baseconstptr->Virt(base_ptrconst_message);
  baseconstptr->PureVirt(base_ptrconst_message);

  nonoverrideinst.Virt(non_override_message);

  // ---------------------------------------------------------------------------
  // Template class.
  // ---------------------------------------------------------------------------

  templ.Member(message1);
  templ.TemplateMember(message1);

  // ---------------------------------------------------------------------------
  // Free operator overloads.
  // ---------------------------------------------------------------------------

  ++message1;
  message1++;
  --message1;
  message1--;

  message1 += message2;
  message1 -= message2;
  message1 *= message2;
  message1 /= message2;
  message1 %= message2;
  message1 ^= message2;
  message1 &= message2;
  message1 |= message2;
  message1 >>= message2;
  message1 <<= message2;

  bool const res_neq_free{message1 != message2};
  std::cout << "operator!= (free) returned "
            << (res_neq_free ? "true" : "false") << std::endl;
  bool const res_le_free{message1 <= message2};
  std::cout << "operator<= (free) returned " << (res_le_free ? "true" : "false")
            << std::endl;
  bool const res_ge_free{message1 >= message2};
  std::cout << "operator>= (free) returned " << (res_ge_free ? "true" : "false")
            << std::endl;
  bool const res_eq_free{message1 == message2};
  std::cout << "operator== (free) returned " << (res_eq_free ? "true" : "false")
            << std::endl;

  message1 >> message2;
  message1 << message2;

  bool const res_and_free{message1 && message2};
  std::cout << "operator&& (free) returned "
            << (res_and_free ? "true" : "false") << std::endl;
  bool const res_or_free{message1 || message2};
  std::cout << "operator|| (free) returned " << (res_or_free ? "true" : "false")
            << std::endl;
  bool const res_not_free{!message1};
  std::cout << "operator! (free) returned " << (res_not_free ? "true" : "false")
            << std::endl;

  message3 = message1 + message2;
  std::cout << "operator+ (free) returned " << message3.GetString()
            << std::endl;
  message3 = message1 - message2;
  std::cout << "operator- (free) returned " << message3.GetString()
            << std::endl;
  message3 = message1 * message2;
  std::cout << "operator* (free) returned " << message3.GetString()
            << std::endl;
  message3 = message1 / message2;
  std::cout << "operator/ (free) returned " << message3.GetString()
            << std::endl;
  message3 = message1 % message2;
  std::cout << "operator% (free) returned " << message3.GetString()
            << std::endl;
  message3 = message1 ^ message2;
  std::cout << "operator^ (free) returned " << message3.GetString()
            << std::endl;
  message3 = message1 & message2;
  std::cout << "operator& (free) returned " << message3.GetString()
            << std::endl;
  message3 = message1 | message2;
  std::cout << "operator| (free) returned " << message3.GetString()
            << std::endl;
  message3 = ~message1;
  std::cout << "operator~ (free) returned " << message3.GetString()
            << std::endl;

  bool const res_lt_free{message1 < message2};
  std::cout << "operator< (free) returned " << (res_lt_free ? "true" : "false")
            << std::endl;
  bool const res_gt_free{message1 > message2};
  std::cout << "operator> (free) returned " << (res_gt_free ? "true" : "false")
            << std::endl;

  message3 = (message1, message2);
  std::cout << "operator, (free) returned " << message3.GetString()
            << std::endl;
  message3 = *message1;
  std::cout << "operator* (free) returned " << message3.GetString()
            << std::endl;
  test::StringContainer *inst_ptr_free{&message1};
  std::cout << "operator& (free) returned " << inst_ptr_free->GetString()
            << std::endl;
}
