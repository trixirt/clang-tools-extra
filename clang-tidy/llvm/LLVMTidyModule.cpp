//===--- LLVMTidyModule.cpp - clang-tidy ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "../readability/NamespaceCommentCheck.h"
#include "../bugprone/HeaderGuardCheck.h"
#include "IncludeOrderCheck.h"
#include "PreferIsaOrDynCastInConditionalsCheck.h"
#include "TwineLocalCheck.h"

namespace clang {
namespace tidy {
namespace llvm_check {

class LLVMModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<bugprone::BugproneHeaderGuardCheck>(
	"llvm-header-guard");
    CheckFactories.registerCheck<IncludeOrderCheck>("llvm-include-order");
    CheckFactories.registerCheck<readability::NamespaceCommentCheck>(
        "llvm-namespace-comment");
    CheckFactories.registerCheck<PreferIsaOrDynCastInConditionalsCheck>(
        "llvm-prefer-isa-or-dyn-cast-in-conditionals");
    CheckFactories.registerCheck<TwineLocalCheck>("llvm-twine-local");
  }

  ClangTidyOptions getModuleOptions() override {
    ClangTidyOptions Options;
    ClangTidyOptions::OptionMap &Opts = Options.CheckOptions;

    Opts["llvm-header-guard.GuardStyle"] = "llvm";

    return Options;
  }

};

// Register the LLVMTidyModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<LLVMModule> X("llvm-module",
                                                  "Adds LLVM lint checks.");

} // namespace llvm_check

// This anchor is used to force the linker to link in the generated object file
// and thus register the LLVMModule.
volatile int LLVMModuleAnchorSource = 0;

} // namespace tidy
} // namespace clang
