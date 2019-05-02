//===--- HeaderGuardCheck.h - clang-tidy ------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BUGPRONE_HEADERGUARDCHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BUGPRONE_HEADERGUARDCHECK_H

#include "../utils/HeaderGuard.h"

namespace clang {
namespace tidy {
namespace bugprone {

/// Finds and fixes missing header guards and does not enforce any style.
///
/// For the user-facing documentation see:
/// http://clang.llvm.org/extra/clang-tidy/checks/bugprone-header-guard.html
class BugproneHeaderGuardCheck : public utils::HeaderGuardCheck {
public:
  BugproneHeaderGuardCheck(StringRef Name, ClangTidyContext *Context);
  bool shouldSuggestToAddHeaderGuard(StringRef Filename) override;
  bool shouldSuggestEndifComment(StringRef Filename) override { return false; }
  std::string getHeaderGuard(StringRef Filename, StringRef OldGuard) override;

  enum GuardStyle { GS_Unsupported = 0, GS_Minimal, GS_LLVM };

private:
  const enum GuardStyle Style;
};

} // namespace bugprone
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_BUGPRONE_HEADERGUARDCHECK_H
