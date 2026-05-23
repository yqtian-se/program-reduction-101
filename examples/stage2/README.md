# Stage 2 Reference — gcc-59903 Full Benchmark

This directory documents the full gcc-59903 benchmark used as the advanced
reference point in Chapters 14–18. The full benchmark input and production
oracle are not vendored in this repository yet.

## Expected Files for a Runnable Stage 2

| File | Description |
|---|---|
| `failure.c` | Original CSmith-generated input, several thousand lines. |
| `test.sh` | Full differential oracle from WeightDD: UB check + reference execution + ICE check. |

Until those files are added, treat Chapters 14 and 16 as annotated workflow
guidance rather than a directly runnable Stage 2 tutorial.

## Setup

Requires:
- `gcc-4.8.2` (the buggy compiler — the "bad" compiler)
- `ccomp` (CompCert — the "good" reference compiler)
- `clang` with `-fsanitize=undefined,address` support

Chapter 16 discusses the oracle patterns needed for this setup, but the
repository does not yet provide a complete Docker reproduction for Stage 2.

## Origin

- Source: [WeightDD/c_benchmarks/gcc-59903](https://github.com/weightdd/WeightDD/tree/main/c_benchmarks/gcc-59903)
- Bug: internal compiler error in GCC 4.8.2; this book's simplified Stage 1
  oracle uses `-O3`, following the captured Stage 1 artifact.
- Exact Stage 2 compiler flags should be verified against the original
  WeightDD oracle when the full input and script are vendored here.
- First described in the WeightDD paper
