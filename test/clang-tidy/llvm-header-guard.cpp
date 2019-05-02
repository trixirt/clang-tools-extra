// RUN: %check_clang_tidy %s llvm-header-guard %t -- \
// RUN:   -config="{CheckOptions: [{key: llvm-header-guard.HeaderFileExtensions, value: 'cpp'}]}" \
// RUN:   -header-filter=.* --

// CHECK-MESSAGES: 1:1: warning:  header is missing header guard

// CHECK-FIXES: #ifndef LLVM_CLANG_TOOLS_EXTRA_TEST_CLANG_TIDY_OUTPUT_LLVM_HEADER_GUARD_CPP_TMP_CPP
// CHECK-FIXES-NEXT: #define LLVM_CLANG_TOOLS_EXTRA_TEST_CLANG_TIDY_OUTPUT_LLVM_HEADER_GUARD_CPP_TMP_CPP
// CHECK-FIXES: #endif
