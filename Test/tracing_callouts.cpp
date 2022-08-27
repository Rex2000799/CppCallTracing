// ATTENTION: GENERATED FILE, ONLY MODIFY EXPLICITLY MARKED PARTS.

// Disable clang format to avoid that it breaks the user
// change area marker comments.
// clang-format off



#include "tracing_callouts.h"


// Insert required includes in following area. These includes
// will be preserved for new generations of this file.

// -----------------------------------------------------------
// USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.
// AREA ID: INCLUDES
// -----------------------------------------------------------
#include <iostream>
// -----------------------------------------------------------
// USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
// -----------------------------------------------------------


namespace tracing {


// Entry callout for function void test::FreeFunction(test::StringContainer)
void entrytestc_o_lFreeFunctionr_otestc_o_lStringContainerr_c(test::StringContainer param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lFreeFunctionr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout FreeFunction: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::FreeFunction(test::StringContainer)
void exittestc_o_lFreeFunctionr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lFreeFunctionr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout FreeFunction" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::FreeTemplateFunction<test::StringContainer>(test::StringContainer)
void entrytestc_o_lFreeTemplateFunctiont_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c(test::StringContainer param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lFreeTemplateFunctiont_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout FreeTemplateFunction: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::FreeTemplateFunction<test::StringContainer>(test::StringContainer)
void exittestc_o_lFreeTemplateFunctiont_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lFreeTemplateFunctiont_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout FreeTemplateFunction" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::Normal(test::StringContainer)
void entrytestc_o_lNormalc_o_lNormalr_otestc_o_lStringContainerr_c(test::Normal * param0, test::StringContainer param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lNormalr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout ctor: input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::Normal(test::StringContainer)
void exittestc_o_lNormalc_o_lNormalr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lNormalr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout ctor" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::Normal(test::Normal const &)
void entrytestc_o_lNormalc_o_lNormalr_otestc_o_lNormalconstrefr_c(test::Normal * param0, test::Normal const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lNormalr_otestc_o_lNormalconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout copy ctor: input: " << param1.content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::Normal(test::Normal const &)
void exittestc_o_lNormalc_o_lNormalr_otestc_o_lNormalconstrefr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lNormalr_otestc_o_lNormalconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout copy ctor" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::Normal(test::Normal &&)
void entrytestc_o_lNormalc_o_lNormalr_otestc_o_lNormalrefrefr_c(test::Normal * param0, test::Normal & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lNormalr_otestc_o_lNormalrefrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout move ctor: input: " << param1.content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::Normal(test::Normal &&)
void exittestc_o_lNormalc_o_lNormalr_otestc_o_lNormalrefrefr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lNormalr_otestc_o_lNormalrefrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout move ctor" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator=(test::Normal const &)
void entrytestc_o_lNormalc_o_lop_asr_otestc_o_lNormalconstrefr_c(test::Normal * param0, test::Normal const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_asr_otestc_o_lNormalconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout copy assignment: content: " << param0->content_.GetString() << ", input: " << param1.content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator=(test::Normal const &)
void exittestc_o_lNormalc_o_lop_asr_otestc_o_lNormalconstrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_asr_otestc_o_lNormalconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout copy assignment" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator=(test::Normal &&)
void entrytestc_o_lNormalc_o_lop_asr_otestc_o_lNormalrefrefr_c(test::Normal * param0, test::Normal & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_asr_otestc_o_lNormalrefrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout move assignment: content: " << param0->content_.GetString() << ", input: " << param1.content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator=(test::Normal &&)
void exittestc_o_lNormalc_o_lop_asr_otestc_o_lNormalrefrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_asr_otestc_o_lNormalrefrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout move assignment" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::MemberFunction(test::StringContainer)
void entrytestc_o_lNormalc_o_lMemberFunctionr_otestc_o_lStringContainerr_c(test::Normal const * param0, test::StringContainer param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lMemberFunctionr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout MemberFunction: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::MemberFunction(test::StringContainer)
void exittestc_o_lNormalc_o_lMemberFunctionr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lMemberFunctionr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout MemberFunction" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::StaticMemberFunction(test::StringContainer)
void entrytestc_o_lNormalc_o_lStaticMemberFunctionr_otestc_o_lStringContainerr_c(test::StringContainer param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lStaticMemberFunctionr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout StaticMemberFunction: input: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::StaticMemberFunction(test::StringContainer)
void exittestc_o_lNormalc_o_lStaticMemberFunctionr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lStaticMemberFunctionr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout StaticMemberFunction" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::ParamVal(test::StringContainer)
void entrytestc_o_lNormalc_o_lParamValr_otestc_o_lStringContainerr_c(test::Normal * param0, test::StringContainer param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lParamValr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout ParamVal: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::ParamVal(test::StringContainer)
void exittestc_o_lNormalc_o_lParamValr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lParamValr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout ParamVal" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::ParamRef(test::StringContainer &)
void entrytestc_o_lNormalc_o_lParamRefr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lParamRefr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout ParamRef: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::ParamRef(test::StringContainer &)
void exittestc_o_lNormalc_o_lParamRefr_otestc_o_lStringContainerrefr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lParamRefr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout ParamRef" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::ParamConstRef(test::StringContainer const &)
void entrytestc_o_lNormalc_o_lParamConstRefr_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lParamConstRefr_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout ParamConstRef: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::ParamConstRef(test::StringContainer const &)
void exittestc_o_lNormalc_o_lParamConstRefr_otestc_o_lStringContainerconstrefr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lParamConstRefr_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout ParamConstRef" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::ParamPtr(test::StringContainer *)
void entrytestc_o_lNormalc_o_lParamPtrr_otestc_o_lStringContainerptrr_c(test::Normal const * param0, test::StringContainer * param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lParamPtrr_otestc_o_lStringContainerptrr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout ParamPtr: content: " << param0->content_.GetString() << ", input: " << param1->GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::ParamPtr(test::StringContainer *)
void exittestc_o_lNormalc_o_lParamPtrr_otestc_o_lStringContainerptrr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lParamPtrr_otestc_o_lStringContainerptrr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout ParamPtr" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::ParamConstPtr(test::StringContainer const *)
void entrytestc_o_lNormalc_o_lParamConstPtrr_otestc_o_lStringContainerconstptrr_c(test::Normal const * param0, test::StringContainer const * param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lParamConstPtrr_otestc_o_lStringContainerconstptrr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout ParamConstPtr: content: " << param0->content_.GetString() << ", input: " << param1->GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::ParamConstPtr(test::StringContainer const *)
void exittestc_o_lNormalc_o_lParamConstPtrr_otestc_o_lStringContainerconstptrr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lParamConstPtrr_otestc_o_lStringContainerconstptrr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout ParamConstPtr" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::ParamMove(test::StringContainer &&)
void entrytestc_o_lNormalc_o_lParamMover_otestc_o_lStringContainerrefrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lParamMover_otestc_o_lStringContainerrefrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout ParamMove: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::ParamMove(test::StringContainer &&)
void exittestc_o_lNormalc_o_lParamMover_otestc_o_lStringContainerrefrefr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lParamMover_otestc_o_lStringContainerrefrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout ParamMove" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::ParamMultiple(test::StringContainer, test::StringContainer)
void entrytestc_o_lNormalc_o_lParamMultipler_otestc_o_lStringContainerc_o_mtestc_o_lStringContainerr_c(test::Normal const * param0, test::StringContainer param1, test::StringContainer param2) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  static_cast<void>(param2);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lParamMultipler_otestc_o_lStringContainerc_o_mtestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout ParamMultiple: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << ", " << param2.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::ParamMultiple(test::StringContainer, test::StringContainer)
void exittestc_o_lNormalc_o_lParamMultipler_otestc_o_lStringContainerc_o_mtestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lParamMultipler_otestc_o_lStringContainerc_o_mtestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout ParamMultiple" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::RetVal()
void entrytestc_o_lNormalc_o_lRetValr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lRetValr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout RetVal: content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::RetVal()
void exittestc_o_lNormalc_o_lRetValr_or_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lRetValr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout RetVal: output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::Normal::RetRef()
void entrytestc_o_lNormalc_o_lRetRefr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lRetRefr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout RetRef: content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::Normal::RetRef()
void exittestc_o_lNormalc_o_lRetRefr_or_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lRetRefr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout RetRef: output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer const& test::Normal::RetConstRef()
void entrytestc_o_lNormalc_o_lRetConstRefr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lRetConstRefr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout RetConstRef: content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer const& test::Normal::RetConstRef()
void exittestc_o_lNormalc_o_lRetConstRefr_or_c(test::StringContainer const& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lRetConstRefr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout RetConstRef: output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer* test::Normal::RetPtr()
void entrytestc_o_lNormalc_o_lRetPtrr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lRetPtrr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout RetPtr: content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer* test::Normal::RetPtr()
void exittestc_o_lNormalc_o_lRetPtrr_or_c(test::StringContainer* retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lRetPtrr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout RetPtr: output: " << retval->GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer const * const test::Normal::RetConstPtr()
void entrytestc_o_lNormalc_o_lRetConstPtrr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lRetConstPtrr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout RetConstPtr: content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer const * const test::Normal::RetConstPtr()
void exittestc_o_lNormalc_o_lRetConstPtrr_or_c(test::StringContainer const * const retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lRetConstPtrr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout RetConstPtr: output: " << retval->GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer&& test::Normal::RetMove()
void entrytestc_o_lNormalc_o_lRetMover_or_c(test::Normal * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lRetMover_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout RetMove: content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer&& test::Normal::RetMove()
void exittestc_o_lNormalc_o_lRetMover_or_c(test::StringContainer&& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lRetMover_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout RetMove: output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::Overload()
void entrytestc_o_lNormalc_o_lOverloadr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lOverloadr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout Overload (no param): content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::Overload()
void exittestc_o_lNormalc_o_lOverloadr_or_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lOverloadr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout Overload (no param)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::Overload(test::StringContainer)
void entrytestc_o_lNormalc_o_lOverloadr_otestc_o_lStringContainerr_c(test::Normal const * param0, test::StringContainer param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lOverloadr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout Overload (with param): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::Overload(test::StringContainer)
void exittestc_o_lNormalc_o_lOverloadr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lOverloadr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout Overload (with param)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::Prefix()
void entrytestc_o_lNormalc_o_lPrefixr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lPrefixr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout Prefix: content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::Prefix()
void exittestc_o_lNormalc_o_lPrefixr_or_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lPrefixr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout Prefix" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Normal::PrefixPostfix()
void entrytestc_o_lNormalc_o_lPrefixPostfixr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lPrefixPostfixr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout PrefixPostfix: content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Normal::PrefixPostfix()
void exittestc_o_lNormalc_o_lPrefixPostfixr_or_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lPrefixPostfixr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout PrefixPostfix" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator++()
void entrytestc_o_lNormalc_o_lop_ir_or_c(test::Normal * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_ir_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout prefix increment operator (member): content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator++()
void exittestc_o_lNormalc_o_lop_ir_or_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_ir_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout prefix increment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator++(int)
void entrytestc_o_lNormalc_o_lop_ir_ointr_c(test::Normal * param0, int param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_ir_ointr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout postfix increment operator (member): content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator++(int)
void exittestc_o_lNormalc_o_lop_ir_ointr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_ir_ointr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout postfix increment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator--()
void entrytestc_o_lNormalc_o_lop_dr_or_c(test::Normal * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_dr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout prefix decrement operator (member): content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator--()
void exittestc_o_lNormalc_o_lop_dr_or_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_dr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout prefix decrement operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator--(int)
void entrytestc_o_lNormalc_o_lop_dr_ointr_c(test::Normal * param0, int param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_dr_ointr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout postfix decrement operator (member): content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator--(int)
void exittestc_o_lNormalc_o_lop_dr_ointr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_dr_ointr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout postfix decrement operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator+=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_plar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_plar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout addition-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator+=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_plar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_plar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout addition-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator-=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_miar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_miar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout subtraction-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator-=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_miar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_miar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout subtraction-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator*=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_muar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_muar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout multiplication-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator*=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_muar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_muar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout multiplication-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator/=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_diar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_diar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout division-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator/=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_diar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_diar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout division-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator%=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_moar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_moar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout modulo-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator%=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_moar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_moar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout modulo-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator^=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_xar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_xar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-xor-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator^=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_xar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_xar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-xor-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator&=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_aar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_aar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-and-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator&=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_aar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_aar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-and-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator|=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_oar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_oar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-or-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator|=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_oar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_oar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-or-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator>>=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_srar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_srar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout right-bitshift-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator>>=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_srar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_srar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout right-bitshift-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator<<=(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_slar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_slar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout left-bitshift-assignment operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator<<=(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_slar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_slar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout left-bitshift-assignment operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::Normal::operator!=(test::StringContainer const &)
void entrytestc_o_lNormalc_o_lop_ner_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_ner_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout non-equal operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::Normal::operator!=(test::StringContainer const &)
void exittestc_o_lNormalc_o_lop_ner_otestc_o_lStringContainerconstrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_ner_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout non-equal operator (member): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::Normal::operator<=(test::StringContainer const &)
void entrytestc_o_lNormalc_o_lop_ler_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_ler_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout less-or-equal (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::Normal::operator<=(test::StringContainer const &)
void exittestc_o_lNormalc_o_lop_ler_otestc_o_lStringContainerconstrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_ler_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout less-or-equal (member): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::Normal::operator>=(test::StringContainer const &)
void entrytestc_o_lNormalc_o_lop_ger_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_ger_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout greater-or-equal (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::Normal::operator>=(test::StringContainer const &)
void exittestc_o_lNormalc_o_lop_ger_otestc_o_lStringContainerconstrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_ger_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout greater-or-equal (member): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::Normal::operator==(test::StringContainer const &)
void entrytestc_o_lNormalc_o_lop_eqr_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_eqr_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout equality operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::Normal::operator==(test::StringContainer const &)
void exittestc_o_lNormalc_o_lop_eqr_otestc_o_lStringContainerconstrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_eqr_otestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout equality operator (member): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator>>(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_srr_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_srr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout right-bitshift operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator>>(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_srr_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_srr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout right-bitshift operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal& test::Normal::operator<<(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_slr_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_slr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout left-bitshift operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal& test::Normal::operator<<(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_slr_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_slr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout left-bitshift operator (member)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::Normal::operator()(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_car_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_car_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout function call operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::Normal::operator()(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_car_otestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_car_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout function call operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::Normal::operator[](test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_arr_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_arr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout array-access operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::Normal::operator[](test::StringContainer &)
void exittestc_o_lNormalc_o_lop_arr_otestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_arr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout array-access operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::Normal::operator&&(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_lar_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_lar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout logical-and operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::Normal::operator&&(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_lar_otestc_o_lStringContainerrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_lar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout logical-and operator (member): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::Normal::operator||(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_lor_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_lor_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout logical-or operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::Normal::operator||(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_lor_otestc_o_lStringContainerrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_lor_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout logical-or operator (member): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::Normal::operator!()
void entrytestc_o_lNormalc_o_lop_lnr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_lnr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout negation operator (member): content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::Normal::operator!()
void exittestc_o_lNormalc_o_lop_lnr_or_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_lnr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout negation operator (member): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator+(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_plr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_plr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout addition operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator+(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_plr_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_plr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout addition operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator-(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_mir_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_mir_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout subtraction operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator-(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_mir_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_mir_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout subtraction operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator*(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_mur_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_mur_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout multiplication operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator*(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_mur_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_mur_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout multiplication operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator/(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_dir_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_dir_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout division operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator/(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_dir_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_dir_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout division operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator%(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_mor_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_mor_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout modulo operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator%(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_mor_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_mor_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout modulo operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator^(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_bxr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_bxr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-xor operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator^(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_bxr_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_bxr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-xor operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator&(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_bar_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_bar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-and operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator&(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_bar_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_bar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-and operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator|(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_bor_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_bor_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-or operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator|(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_bor_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_bor_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-or operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator~()
void entrytestc_o_lNormalc_o_lop_bnr_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_bnr_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-negation operator (member): content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator~()
void exittestc_o_lNormalc_o_lop_bnr_or_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_bnr_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-negation operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::Normal::operator<(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_ltr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_ltr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout less-than operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::Normal::operator<(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_ltr_otestc_o_lStringContainerrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_ltr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout less-than operator (member): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::Normal::operator>(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_gtr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_gtr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout greater-than operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::Normal::operator>(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_gtr_otestc_o_lStringContainerrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_gtr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout greater-than operator (member): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator,(test::StringContainer &)
void entrytestc_o_lNormalc_o_lop_cor_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_cor_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout comma operator (member): content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator,(test::StringContainer &)
void exittestc_o_lNormalc_o_lop_cor_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_cor_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout comma operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::Normal::operator*()
void entrytestc_o_lNormalc_o_lop_mur_or_c(test::Normal const * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_mur_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout pointer-dereference operator (member): content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::Normal::operator*()
void exittestc_o_lNormalc_o_lop_mur_or_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_mur_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout pointer-dereference operator (member): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::Normal* test::Normal::operator&()
void entrytestc_o_lNormalc_o_lop_bar_or_c(test::Normal * param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lNormalc_o_lop_bar_or_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout address-of operator (member): content: " << param0->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::Normal* test::Normal::operator&()
void exittestc_o_lNormalc_o_lop_bar_or_c(test::Normal* retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lNormalc_o_lop_bar_or_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout address-of operator (member): output: " << retval->content_.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Base::Virt(test::StringContainer)
void entrytestc_o_lBasec_o_lVirtr_otestc_o_lStringContainerr_c(test::Base const * param0, test::StringContainer param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lBasec_o_lVirtr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout virtual function base class: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Base::Virt(test::StringContainer)
void exittestc_o_lBasec_o_lVirtr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lBasec_o_lVirtr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout virtual function base class" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Derived::Virt(test::StringContainer)
void entrytestc_o_lDerivedc_o_lVirtr_otestc_o_lStringContainerr_c(test::Derived const * param0, test::StringContainer param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lDerivedc_o_lVirtr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout virtual function derived class: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Derived::Virt(test::StringContainer)
void exittestc_o_lDerivedc_o_lVirtr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lDerivedc_o_lVirtr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout virtual function derived class" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Derived::PureVirt(test::StringContainer)
void entrytestc_o_lDerivedc_o_lPureVirtr_otestc_o_lStringContainerr_c(test::Derived const * param0, test::StringContainer param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lDerivedc_o_lPureVirtr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout pure virtual function derived class: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Derived::PureVirt(test::StringContainer)
void exittestc_o_lDerivedc_o_lPureVirtr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lDerivedc_o_lPureVirtr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout pure virtual function derived class" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Template<test::StringContainer>::Member(test::StringContainer)
void entrytestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lMemberr_otestc_o_lStringContainerr_c(test::Template<test::StringContainer> const * param0, test::StringContainer param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lMemberr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout template class normal member function: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Template<test::StringContainer>::Member(test::StringContainer)
void exittestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lMemberr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lMemberr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout template class normal member function" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function void test::Template<test::StringContainer>::TemplateMember<test::StringContainer>(test::StringContainer)
void entrytestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lTemplateMembert_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c(test::Template<test::StringContainer> const * param0, test::StringContainer param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lTemplateMembert_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout template class template member function: content: " << param0->content_.GetString() << ", input: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function void test::Template<test::StringContainer>::TemplateMember<test::StringContainer>(test::StringContainer)
void exittestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lTemplateMembert_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c() noexcept {
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lTemplateMembert_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout template class template member function" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator++(test::StringContainer &)
void entrytestc_o_lop_ir_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_ir_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout prefix increment operator (free function): input: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator++(test::StringContainer &)
void exittestc_o_lop_ir_otestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_ir_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout prefix increment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator++(test::StringContainer &, int)
void entrytestc_o_lop_ir_otestc_o_lStringContainerrefc_o_mintr_c(test::StringContainer & param0, int param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_ir_otestc_o_lStringContainerrefc_o_mintr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout postfix increment operator (free function): input: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator++(test::StringContainer &, int)
void exittestc_o_lop_ir_otestc_o_lStringContainerrefc_o_mintr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_ir_otestc_o_lStringContainerrefc_o_mintr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout postfix increment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator--(test::StringContainer &)
void entrytestc_o_lop_dr_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_dr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout prefix decrement operator (free function): input: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator--(test::StringContainer &)
void exittestc_o_lop_dr_otestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_dr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout prefix decrement operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator--(test::StringContainer &, int)
void entrytestc_o_lop_dr_otestc_o_lStringContainerrefc_o_mintr_c(test::StringContainer & param0, int param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_dr_otestc_o_lStringContainerrefc_o_mintr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout postfix decrement operator (free function): input: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator--(test::StringContainer &, int)
void exittestc_o_lop_dr_otestc_o_lStringContainerrefc_o_mintr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_dr_otestc_o_lStringContainerrefc_o_mintr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout postfix decrement operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator+=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_plar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_plar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout addition-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator+=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_plar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_plar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout addition-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator-=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_miar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_miar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout subtraction-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator-=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_miar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_miar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout subtraction-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator*=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_muar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_muar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout multiplication-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator*=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_muar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_muar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout multiplication-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator/=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_diar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_diar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout division-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator/=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_diar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_diar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout division-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator%=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_moar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_moar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout modulo-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator%=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_moar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_moar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout modulo-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator^=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_xar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_xar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-xor-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator^=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_xar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_xar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-xor-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator&=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_aar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_aar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-and-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator&=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_aar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_aar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-and-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator|=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_oar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_oar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-or-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator|=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_oar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_oar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-or-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator>>=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_srar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_srar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout right-bitshift-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator>>=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_srar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_srar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout right-bitshift-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator<<=(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_slar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_slar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout left-bitshift-assignment operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator<<=(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_slar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_slar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout left-bitshift-assignment operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::operator!=(test::StringContainer const &, test::StringContainer const &)
void entrytestc_o_lop_ner_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(test::StringContainer const & param0, test::StringContainer const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_ner_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout non-equal operator operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::operator!=(test::StringContainer const &, test::StringContainer const &)
void exittestc_o_lop_ner_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_ner_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout non-equal operator (free function): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::operator<=(test::StringContainer const &, test::StringContainer const &)
void entrytestc_o_lop_ler_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(test::StringContainer const & param0, test::StringContainer const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_ler_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout less-or-equal operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::operator<=(test::StringContainer const &, test::StringContainer const &)
void exittestc_o_lop_ler_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_ler_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout less-or-equal operator (free function): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::operator>=(test::StringContainer const &, test::StringContainer const &)
void entrytestc_o_lop_ger_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(test::StringContainer const & param0, test::StringContainer const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_ger_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout greater-or-equal operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::operator>=(test::StringContainer const &, test::StringContainer const &)
void exittestc_o_lop_ger_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_ger_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout greater-or-equal operator (free function): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::operator==(test::StringContainer const &, test::StringContainer const &)
void entrytestc_o_lop_eqr_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(test::StringContainer const & param0, test::StringContainer const & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_eqr_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout equality operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::operator==(test::StringContainer const &, test::StringContainer const &)
void exittestc_o_lop_eqr_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_eqr_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout equality operator (free function): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator>>(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_srr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_srr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout right-bitshift operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator>>(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_srr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_srr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout right-bitshift operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer& test::operator<<(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_slr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_slr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout left-bitshift operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer& test::operator<<(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_slr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_slr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout left-bitshift operator (free function)" << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::operator&&(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_lar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_lar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout logical-and operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::operator&&(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_lar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_lar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout logical-and operator (free function): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::operator||(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_lor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_lor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout logical-or operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::operator||(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_lor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_lor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout logical-or operator (free function): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::operator!(test::StringContainer &)
void entrytestc_o_lop_lnr_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_lnr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout negation operator (free function): input: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::operator!(test::StringContainer &)
void exittestc_o_lop_lnr_otestc_o_lStringContainerrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_lnr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout negation operator (free function): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator+(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_plr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_plr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout addition operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator+(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_plr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_plr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout addition operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator-(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_mir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_mir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout subtraction operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator-(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_mir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_mir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout subtraction operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator*(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_mur_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_mur_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout multiplication operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator*(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_mur_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_mur_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout multiplication operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator/(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_dir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_dir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout division operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator/(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_dir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_dir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout division operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator%(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_mor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_mor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout modulo operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator%(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_mor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_mor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout modulo operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator^(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_bxr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_bxr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-xor operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator^(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_bxr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_bxr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-xor operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator&(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_bar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_bar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-and operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator&(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_bar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_bar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-and operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator|(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_bor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_bor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-or operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator|(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_bor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_bor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-or operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator~(test::StringContainer &)
void entrytestc_o_lop_bnr_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_bnr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout bitwise-negation operator (free function): input: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator~(test::StringContainer &)
void exittestc_o_lop_bnr_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_bnr_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout bitwise-negation operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::operator<(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_ltr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_ltr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout less-than operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::operator<(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_ltr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_ltr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout less-than operator (free function): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function bool test::operator>(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_gtr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_gtr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout greater-than operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function bool test::operator>(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_gtr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(bool retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_gtr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout greater-than operator (free function): output: " << (retval ? "true" : "false") << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator,(test::StringContainer &, test::StringContainer &)
void entrytestc_o_lop_cor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept {
  static_cast<void>(param0);
  static_cast<void>(param1);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_cor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout comma operator (free function): input 1: " << param0.GetString() << ", input 2: " << param1.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator,(test::StringContainer &, test::StringContainer &)
void exittestc_o_lop_cor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_cor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout comma operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer test::operator*(test::StringContainer &)
void entrytestc_o_lop_mur_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_mur_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout pointer-dereference operator (free function): input: " << param0.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer test::operator*(test::StringContainer &)
void exittestc_o_lop_mur_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_mur_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout pointer-dereference operator (free function): output: " << retval.GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Entry callout for function test::StringContainer* test::operator&(test::StringContainer &)
void entrytestc_o_lop_bar_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept {
  static_cast<void>(param0);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::entrytestc_o_lop_bar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Entry Callout address-of operator (free function): input: " << param0.GetString()  << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}

// Exit callout for function test::StringContainer* test::operator&(test::StringContainer &)
void exittestc_o_lop_bar_otestc_o_lStringContainerrefr_c(test::StringContainer* retval) noexcept {
  static_cast<void>(retval);
  // -----------------------------------------------------------
  // USER CHANGE AREA START MARKER - DO NOT CHANGE THIS COMMENT.  
  // AREA ID: tracing::exittestc_o_lop_bar_otestc_o_lStringContainerrefr_c
  // -----------------------------------------------------------
  std::cout << "Exit Callout address-of operator (free function): output: " << retval->GetString() << std::endl;
  // -----------------------------------------------------------
  // USER CHANGE AREA END MARKER - DO NOT CHANGE THIS COMMENT.  
  // -----------------------------------------------------------
}



}  // namespace tracing
// clang-format on
