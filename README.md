## TO USE IN WINDOWS
First, install latex or miktex.
Second, install all package involve in file content\tex\kactlpkg.sty (in \usepackage tag).
Next, copy content\tex folder, which contain kactlpkg.sty, to local root package (https://miktex.org/kb/texmf-roots might helpful).
Enjoy, by using bash.
# My notebook

This repo customize the KACTL notebook, [KTH](https://en.wikipedia.org/wiki/KTH_Royal_Institute_of_Technology), for my team icpc notebook.
It consists of about 20 pages of copy-pasteable C++ code, for use in ICPC-style programming competitions. 
I haven't stress-test my code in notebook yet, so be careful when using it.


## Customizing KACTL

While KACTL is usable as is, it's also easy to modify if you want to create a personalized copy.
In particular, you may want to change the cover page, or make your own choice of algorithms to include --
due to space concerns, not all algorithms in the repo are included in the pdf.
You may also want to enable colored syntax highlighting.

`content/kactl.tex` is the main file of KACTL, and can be edited to change team name, logo, syntax highlighting, etc.
It imports `chapter.tex` files from each of the `content/` subdirectories, which define the contents of each chapter.
These include source code, text and math in the form of LaTeX.
To add/remove code from a chapter, add/remove a corresponding `\kactlimport` line from the `chapter.tex` file.
For nicer alignment you might want to insert `\hardcolumnbreak`, `\columnbreak` or `\newpage` commands,
though this is usually only done before important contests, and not on the main branch.
The algorithms that are not included in the pdf are left commented out in `chapter.tex`.

To build KACTL, type `make kactl` (or `make fast`) on a \*nix machine -- this will update `kactl.pdf`.
(Windows might work as well, but is not tested.) `doc/README` has a few more notes about this.
.


## License

As usual for competitive programming, the licensing situation is a bit unclear.
Many source files are marked with license (we try to go with
[CC0](https://creativecommons.org/share-your-work/public-domain/cc0/)), but many also aren't.
Presumably good will is to be assumed from other authors, though, and in many cases permission should not be needed since the code is not distributed.
To help trace things back, sources and authors are noted in source files.

Everything in `stress-tests` is implicitly CC0, except reference implementations taken from around the Internet.
