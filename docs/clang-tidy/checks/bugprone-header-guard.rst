.. title:: clang-tidy - bugprone-header-guard

bugprone-header-guard
=====================

Finds and fixes missing header guards and does not enforce any style.

Options
-------

.. option:: HeaderFileExtensions

   A comma-separated list of filename extensions of header files (the filename
   extensions should not include "." prefix). Default is `h,hh,hpp,hxx`.
   For header files without an extension, use an empty string (if there are no
   other desired extensions) or leave an empty element in the list. e.g.,
   `h,hh,hpp,hxx,` (note the trailing comma).

.. option:: GuardStyle

   The style to use for the header guard. The values are

   .. option:: minimal

      If a guard is missing, use the uppercased filename as the guard.  This is
      the default.

   .. option:: llvm

      Finds and fixes header guards that do not adhere to LLVM style. Used by
      the `llvm-header-guard <llvm-header-guard.html>`_ checker.
