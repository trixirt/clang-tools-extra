// GuardStyle=default (minimal), HeaderFileExtension=cpp
// RUN: %check_clang_tidy %s bugprone-header-guard %t -- -config="{CheckOptions: [{key: bugprone-header-guard.HeaderFileExtensions, value: 'cpp'}]}" -header-filter=.* --
// GuardStyle=llvm,  HeaderFileExtension=cpp
// RUN: %check_clang_tidy -check-suffix=LLVM %s bugprone-header-guard %t -- -config="{CheckOptions: [{key: bugprone-header-guard.HeaderFileExtensions, value: 'cpp'}, {key: bugprone-header-guard.GuardStyle, value: 'llvm'}]}" -header-filter=.* --
// GuardStyle=minimal,  HeaderFileExtension=cpp
// RUN: %check_clang_tidy -check-suffix=MINIMAL %s bugprone-header-guard %t -- -config="{CheckOptions: [{key: bugprone-header-guard.HeaderFileExtensions, value: 'cpp'}, {key: bugprone-header-guard.GuardStyle, value: 'minimal'}]}" -header-filter=.* --

// CHECK-MESSAGES: 1:1: warning:  header is missing header guard
// CHECK-FIXES: #ifndef BUGPRONE_HEADER_GUARD_CPP_TMP_CPP
// CHECK-FIXES-NEXT: #define BUGPRONE_HEADER_GUARD_CPP_TMP_CPP
// CHECK-FIXES: #endif

// CHECK-MESSAGES-LLVM: 1:1: warning:  header is missing header guard
// CHECK-FIXES-LLVM: #ifndef LLVM_CLANG_TOOLS_EXTRA_TEST_CLANG_TIDY_OUTPUT_BUGPRONE_HEADER_GUARD_CPP_TMP_CPP
// CHECK-FIXES-NEXT-LLVM: #define LLVM_CLANG_TOOLS_EXTRA_TEST_CLANG_TIDY_OUTPUT_BUGPRONE_HEADER_GUARD_CPP_TMP_CPP
// CHECK-FIXES-LLVM: #endif

// CHECK-MESSAGES-MINIMAL: 1:1: warning:  header is missing header guard
// CHECK-FIXES-MINIMAL: #ifndef BUGPRONE_HEADER_GUARD_CPP_TMP_CPP
// CHECK-FIXES-NEXT-MINIMAL: #define BUGPRONE_HEADER_GUARD_CPP_TMP_CPP
// CHECK-FIXES-MINIMAL: #endif
