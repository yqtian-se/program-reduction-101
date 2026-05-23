#!/usr/bin/env bash
# Simplified oracle for Stage 1: check only for internal compiler error.
# The Stage 2 oracle discussed in Chapter 14 additionally verifies absence of
# undefined behaviour and output equivalence across compilers.
#
# Usage inside Perses: Perses runs this script from a working directory
# where the candidate is named small.c.  To test manually:
#   cd examples/stage1 && cp failure.c small.c && bash test.sh
#
# Requires: gcc 4.8.2 at /compilers/gcc/4.8.2/bin/gcc in the WDD Docker image.
# If you run this outside that image, adjust the compiler path below.
#
# Note: gcc exits non-zero on ICE, so we intentionally omit pipefail;
# the script return code comes from grep (0 = pattern found = bug present).
/compilers/gcc/4.8.2/bin/gcc -m32 -O3 small.c 2>&1 | grep -q "internal compiler error"
