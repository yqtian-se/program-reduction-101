# Program Reduction 101

Program Reduction 101 is a practical, research-oriented introduction to program reduction: the craft of turning large failure-inducing inputs into small, useful bug reports.

The book starts with Delta Debugging, then moves through Perses and syntax-guided reduction, reducer evaluation, robust oracles, compiler-bug reduction, and the Perses-family research line.

Read the book online:

<https://yqtian-se.github.io/program-reduction-101/>

## What Is Included

- Quarto book source in `index.qmd` and `chapters/`
- Bibliography in `bibliography/references.bib`
- Styling in `assets/`
- Small runnable examples in `examples/`
- GitHub Pages workflow in `.github/workflows/pages.yml`

## Build Locally

Install Quarto, then run:

```bash
quarto render
```

Or use the official Quarto Docker image:

```bash
docker run --rm \
  -v "$PWD:/project" \
  -w /project \
  ghcr.io/quarto-dev/quarto \
  quarto render
```

## Questions and Suggestions

For questions, suggestions, or corrections, please contact:

`yongqiang.tian@monash.edu`
