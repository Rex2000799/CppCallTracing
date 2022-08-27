// ATTENTION: GENERATED FILE, DO NOT MODIFY.


#ifndef TRACING_GENERATED_CALLOUTS_H_
#define TRACING_GENERATED_CALLOUTS_H_


#include "test.h"


namespace tracing {


void entrytestc_o_lFreeFunctionr_otestc_o_lStringContainerr_c(test::StringContainer param0) noexcept;
void exittestc_o_lFreeFunctionr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lFreeTemplateFunctiont_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c(test::StringContainer param0) noexcept;
void exittestc_o_lFreeTemplateFunctiont_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lNormalc_o_lNormalr_otestc_o_lStringContainerr_c(test::Normal * param0, test::StringContainer param1) noexcept;
void exittestc_o_lNormalc_o_lNormalr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lNormalc_o_lNormalr_otestc_o_lNormalconstrefr_c(test::Normal * param0, test::Normal const & param1) noexcept;
void exittestc_o_lNormalc_o_lNormalr_otestc_o_lNormalconstrefr_c() noexcept;

void entrytestc_o_lNormalc_o_lNormalr_otestc_o_lNormalrefrefr_c(test::Normal * param0, test::Normal & param1) noexcept;
void exittestc_o_lNormalc_o_lNormalr_otestc_o_lNormalrefrefr_c() noexcept;

void entrytestc_o_lNormalc_o_lop_asr_otestc_o_lNormalconstrefr_c(test::Normal * param0, test::Normal const & param1) noexcept;
void exittestc_o_lNormalc_o_lop_asr_otestc_o_lNormalconstrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_asr_otestc_o_lNormalrefrefr_c(test::Normal * param0, test::Normal & param1) noexcept;
void exittestc_o_lNormalc_o_lop_asr_otestc_o_lNormalrefrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lMemberFunctionr_otestc_o_lStringContainerr_c(test::Normal const * param0, test::StringContainer param1) noexcept;
void exittestc_o_lNormalc_o_lMemberFunctionr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lNormalc_o_lStaticMemberFunctionr_otestc_o_lStringContainerr_c(test::StringContainer param0) noexcept;
void exittestc_o_lNormalc_o_lStaticMemberFunctionr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lNormalc_o_lParamValr_otestc_o_lStringContainerr_c(test::Normal * param0, test::StringContainer param1) noexcept;
void exittestc_o_lNormalc_o_lParamValr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lNormalc_o_lParamRefr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lParamRefr_otestc_o_lStringContainerrefr_c() noexcept;

void entrytestc_o_lNormalc_o_lParamConstRefr_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept;
void exittestc_o_lNormalc_o_lParamConstRefr_otestc_o_lStringContainerconstrefr_c() noexcept;

void entrytestc_o_lNormalc_o_lParamPtrr_otestc_o_lStringContainerptrr_c(test::Normal const * param0, test::StringContainer * param1) noexcept;
void exittestc_o_lNormalc_o_lParamPtrr_otestc_o_lStringContainerptrr_c() noexcept;

void entrytestc_o_lNormalc_o_lParamConstPtrr_otestc_o_lStringContainerconstptrr_c(test::Normal const * param0, test::StringContainer const * param1) noexcept;
void exittestc_o_lNormalc_o_lParamConstPtrr_otestc_o_lStringContainerconstptrr_c() noexcept;

void entrytestc_o_lNormalc_o_lParamMover_otestc_o_lStringContainerrefrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lParamMover_otestc_o_lStringContainerrefrefr_c() noexcept;

void entrytestc_o_lNormalc_o_lParamMultipler_otestc_o_lStringContainerc_o_mtestc_o_lStringContainerr_c(test::Normal const * param0, test::StringContainer param1, test::StringContainer param2) noexcept;
void exittestc_o_lNormalc_o_lParamMultipler_otestc_o_lStringContainerc_o_mtestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lNormalc_o_lRetValr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lRetValr_or_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lRetRefr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lRetRefr_or_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lNormalc_o_lRetConstRefr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lRetConstRefr_or_c(test::StringContainer const& retval) noexcept;

void entrytestc_o_lNormalc_o_lRetPtrr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lRetPtrr_or_c(test::StringContainer* retval) noexcept;

void entrytestc_o_lNormalc_o_lRetConstPtrr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lRetConstPtrr_or_c(test::StringContainer const * const retval) noexcept;

void entrytestc_o_lNormalc_o_lRetMover_or_c(test::Normal * param0) noexcept;
void exittestc_o_lNormalc_o_lRetMover_or_c(test::StringContainer&& retval) noexcept;

void entrytestc_o_lNormalc_o_lOverloadr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lOverloadr_or_c() noexcept;

void entrytestc_o_lNormalc_o_lOverloadr_otestc_o_lStringContainerr_c(test::Normal const * param0, test::StringContainer param1) noexcept;
void exittestc_o_lNormalc_o_lOverloadr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lNormalc_o_lPrefixr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lPrefixr_or_c() noexcept;

void entrytestc_o_lNormalc_o_lPrefixPostfixr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lPrefixPostfixr_or_c() noexcept;

void entrytestc_o_lNormalc_o_lop_ir_or_c(test::Normal * param0) noexcept;
void exittestc_o_lNormalc_o_lop_ir_or_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_ir_ointr_c(test::Normal * param0, int param1) noexcept;
void exittestc_o_lNormalc_o_lop_ir_ointr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_dr_or_c(test::Normal * param0) noexcept;
void exittestc_o_lNormalc_o_lop_dr_or_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_dr_ointr_c(test::Normal * param0, int param1) noexcept;
void exittestc_o_lNormalc_o_lop_dr_ointr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_plar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_plar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_miar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_miar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_muar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_muar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_diar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_diar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_moar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_moar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_xar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_xar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_aar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_aar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_oar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_oar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_srar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_srar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_slar_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_slar_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_ner_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept;
void exittestc_o_lNormalc_o_lop_ner_otestc_o_lStringContainerconstrefr_c(bool retval) noexcept;

void entrytestc_o_lNormalc_o_lop_ler_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept;
void exittestc_o_lNormalc_o_lop_ler_otestc_o_lStringContainerconstrefr_c(bool retval) noexcept;

void entrytestc_o_lNormalc_o_lop_ger_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept;
void exittestc_o_lNormalc_o_lop_ger_otestc_o_lStringContainerconstrefr_c(bool retval) noexcept;

void entrytestc_o_lNormalc_o_lop_eqr_otestc_o_lStringContainerconstrefr_c(test::Normal const * param0, test::StringContainer const & param1) noexcept;
void exittestc_o_lNormalc_o_lop_eqr_otestc_o_lStringContainerconstrefr_c(bool retval) noexcept;

void entrytestc_o_lNormalc_o_lop_srr_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_srr_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_slr_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_slr_otestc_o_lStringContainerrefr_c(test::Normal& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_car_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_car_otestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_arr_otestc_o_lStringContainerrefr_c(test::Normal * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_arr_otestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lNormalc_o_lop_lar_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_lar_otestc_o_lStringContainerrefr_c(bool retval) noexcept;

void entrytestc_o_lNormalc_o_lop_lor_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_lor_otestc_o_lStringContainerrefr_c(bool retval) noexcept;

void entrytestc_o_lNormalc_o_lop_lnr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lop_lnr_or_c(bool retval) noexcept;

void entrytestc_o_lNormalc_o_lop_plr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_plr_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_mir_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_mir_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_mur_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_mur_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_dir_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_dir_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_mor_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_mor_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_bxr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_bxr_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_bar_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_bar_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_bor_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_bor_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_bnr_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lop_bnr_or_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_ltr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_ltr_otestc_o_lStringContainerrefr_c(bool retval) noexcept;

void entrytestc_o_lNormalc_o_lop_gtr_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_gtr_otestc_o_lStringContainerrefr_c(bool retval) noexcept;

void entrytestc_o_lNormalc_o_lop_cor_otestc_o_lStringContainerrefr_c(test::Normal const * param0, test::StringContainer & param1) noexcept;
void exittestc_o_lNormalc_o_lop_cor_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_mur_or_c(test::Normal const * param0) noexcept;
void exittestc_o_lNormalc_o_lop_mur_or_c(test::StringContainer retval) noexcept;

void entrytestc_o_lNormalc_o_lop_bar_or_c(test::Normal * param0) noexcept;
void exittestc_o_lNormalc_o_lop_bar_or_c(test::Normal* retval) noexcept;

void entrytestc_o_lBasec_o_lVirtr_otestc_o_lStringContainerr_c(test::Base const * param0, test::StringContainer param1) noexcept;
void exittestc_o_lBasec_o_lVirtr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lDerivedc_o_lVirtr_otestc_o_lStringContainerr_c(test::Derived const * param0, test::StringContainer param1) noexcept;
void exittestc_o_lDerivedc_o_lVirtr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lDerivedc_o_lPureVirtr_otestc_o_lStringContainerr_c(test::Derived const * param0, test::StringContainer param1) noexcept;
void exittestc_o_lDerivedc_o_lPureVirtr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lMemberr_otestc_o_lStringContainerr_c(test::Template<test::StringContainer> const * param0, test::StringContainer param1) noexcept;
void exittestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lMemberr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lTemplateMembert_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c(test::Template<test::StringContainer> const * param0, test::StringContainer param1) noexcept;
void exittestc_o_lTemplatet_otestc_o_lStringContainert_cc_o_lTemplateMembert_otestc_o_lStringContainert_cr_otestc_o_lStringContainerr_c() noexcept;

void entrytestc_o_lop_ir_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept;
void exittestc_o_lop_ir_otestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_ir_otestc_o_lStringContainerrefc_o_mintr_c(test::StringContainer & param0, int param1) noexcept;
void exittestc_o_lop_ir_otestc_o_lStringContainerrefc_o_mintr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_dr_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept;
void exittestc_o_lop_dr_otestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_dr_otestc_o_lStringContainerrefc_o_mintr_c(test::StringContainer & param0, int param1) noexcept;
void exittestc_o_lop_dr_otestc_o_lStringContainerrefc_o_mintr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_plar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_plar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_miar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_miar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_muar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_muar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_diar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_diar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_moar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_moar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_xar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_xar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_aar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_aar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_oar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_oar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_srar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_srar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_slar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_slar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_ner_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(test::StringContainer const & param0, test::StringContainer const & param1) noexcept;
void exittestc_o_lop_ner_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(bool retval) noexcept;

void entrytestc_o_lop_ler_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(test::StringContainer const & param0, test::StringContainer const & param1) noexcept;
void exittestc_o_lop_ler_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(bool retval) noexcept;

void entrytestc_o_lop_ger_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(test::StringContainer const & param0, test::StringContainer const & param1) noexcept;
void exittestc_o_lop_ger_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(bool retval) noexcept;

void entrytestc_o_lop_eqr_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(test::StringContainer const & param0, test::StringContainer const & param1) noexcept;
void exittestc_o_lop_eqr_otestc_o_lStringContainerconstrefc_o_mtestc_o_lStringContainerconstrefr_c(bool retval) noexcept;

void entrytestc_o_lop_srr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_srr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_slr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_slr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer& retval) noexcept;

void entrytestc_o_lop_lar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_lar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(bool retval) noexcept;

void entrytestc_o_lop_lor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_lor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(bool retval) noexcept;

void entrytestc_o_lop_lnr_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept;
void exittestc_o_lop_lnr_otestc_o_lStringContainerrefr_c(bool retval) noexcept;

void entrytestc_o_lop_plr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_plr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_mir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_mir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_mur_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_mur_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_dir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_dir_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_mor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_mor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_bxr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_bxr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_bar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_bar_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_bor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_bor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_bnr_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept;
void exittestc_o_lop_bnr_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_ltr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_ltr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(bool retval) noexcept;

void entrytestc_o_lop_gtr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_gtr_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(bool retval) noexcept;

void entrytestc_o_lop_cor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer & param0, test::StringContainer & param1) noexcept;
void exittestc_o_lop_cor_otestc_o_lStringContainerrefc_o_mtestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_mur_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept;
void exittestc_o_lop_mur_otestc_o_lStringContainerrefr_c(test::StringContainer retval) noexcept;

void entrytestc_o_lop_bar_otestc_o_lStringContainerrefr_c(test::StringContainer & param0) noexcept;
void exittestc_o_lop_bar_otestc_o_lStringContainerrefr_c(test::StringContainer* retval) noexcept;



}  // namespace tracing

#endif // TRACING_GENERATED_CALLOUTS_H_
