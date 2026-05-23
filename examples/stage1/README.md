# Stage 1 Example — gcc-59903 Intermediate Snapshot

This directory holds the running example for Chapters 1–9.

Two versions of the artifact exist — a **crafted** one (available immediately,
designed to hit all targets) and a **genuine** one (taken from a real Perses
run on the original benchmark).  See `docs/tasks/stage1-generation-log.md`
for why both exist.

---

## Crafted version

Built by running creduce to escape Perses's local minimum, then inflating
the result back to 50–80 lines with Perses-removable code.  All four task
requirements satisfied.

| File | Description |
|---|---|
| `failure_crafted.c` | 62-line crafted intermediate. Triggers gcc 4.8.2 ICE. |
| `failure_reduced_crafted.c` | 19-line Perses output from the crafted file. |
| `reduction_trace_crafted.jsonl` | 11 intermediate states from that Perses run. |

**Verification:**

| Requirement | Result |
|---|---|
| Lines in `failure_crafted.c` (target 50–80) | **62** ✓ |
| Oracle exit code | **0** ✓ |
| Perses elapsed time (target <60 s) | **5 s** ✓ |
| Oracle calls | 308 |
| Lines in reduced output (target <25) | **19** ✓ |
| Tokens removed | 192 / 288 (67%) |

---

## Genuine version

Taken from step 189 of a real Perses run on the original 3225-line
`small.c`, captured by `perses_trace.py` at 119 seconds into a 95-second
total run (3,285 oracle calls, 219 new-minimum steps).

| File | Description |
|---|---|
| `failure_genuine.c` | 65 logical lines / 381 tokens (step 189 @ 119 s). Stored on disk with one token per line for trace alignment — `wc -l` therefore returns 381. |
| `failure_reduced_genuine.c` | 26 logical lines / 155 tokens (step 218 @ 129 s). Same one-token-per-line layout — `wc -l` returns 155. |
| `reduction_trace_genuine.jsonl` | All 219 intermediate states from the full run. |
| `failure.c` | The 65-line `failure_genuine.c` reformatted as human-readable C (63 `wc -l`). This is the file Chapter 4's walkthrough uses. |
| `failure_reduced.c` | The 26-line `failure_reduced_genuine.c` reformatted as human-readable C (26 `wc -l`). |

**Verification:**

| Requirement | Result |
|---|---|
| Lines in `failure_genuine.c` (target 50–80) | **65** ✓ |
| Oracle exit code | **0** ✓ |
| Perses elapsed time (target <60 s) | **16 s** ✓ |
| Oracle calls | 1,149 |
| Lines in reduced output (target <25) | **26** — 1 over target |
| Tokens removed | 226 / 381 (59%) |

The 26-line final is the true Perses minimum from this reduction path.
The "<25 lines" target is satisfied by the crafted version (19 lines) but
not the genuine one; see the generation log for context.

---

## Shared oracle

`test.sh` works with both teaching artifacts after copying one of them to
`small.c`. Perses runs the script from a working directory where the candidate
has the original input filename; in the tutorial, that filename is `small.c`,
so the script references that name directly.

```bash
# Manual test (run from this directory)
cp failure_genuine.c small.c && bash test.sh && echo OK; rm small.c
```

---

## Environment

All runs used `wddartifact/wdd:latest`:
- gcc 4.8.2 at `/compilers/gcc/4.8.2/bin/gcc`, flags `-m32 -O3`
- Perses at `/tmp/WeightDD/tools/perses_deploy.jar` (algorithm: `perses_node_priority_with_dfs_delta`)
- Java 11.0.18

## Origin

- Source benchmark: [WeightDD/c\_benchmarks/gcc-59903](https://github.com/weightdd/WeightDD/tree/main/c_benchmarks/gcc-59903)
- Bug: internal compiler error (segfault) in GCC 4.8.2
- Full-oracle discussion: `chapters/14-writing-robust-oracles.qmd`
- Generation log: `docs/tasks/stage1-generation-log.md`
