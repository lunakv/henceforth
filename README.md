# Henceforth
This is Henceforth, a simple interpreter for a Forth-like stack-based language.

## Installation
For compiling from the source, clone this repository and then run
```
cd $HF_DIR && cmake . && make
```
where $HF_DIR is the path to the cloned directory. The binary will then be compiled to `./henceforth`

## Supported commands
Henceforth supports the following words from the Forth CORE dictionary:
- `+`, `-`, `*`, `/`, `MOD`, `/MOD`, `RSHIFT`, `LSHIFT`, `MAX`, `MIN`, `WITHIN`
- `TRUE`, `FALSE`
- `<`, `>`, `=`
- `AND`, `OR`, `XOR`
- `DUP`, `DROP`, `.`, `CR` 
- `:`, `;`, `\`

In addition, Henceforth supports the following Forth words exclusively in the compilation environment:
- `IF`, `ELSE`, `THEN`, `BEGIN`, `WHILE`, `REPEAT`, `AGAIN`
- `DO`, `LOOP`, `+LOOP`, `LEAVE`
- `."`, `RECURSE`

To find out more about the usage of the words listed above, see the [Forth standard](https://forth-standard.org/standard/core) website

## Differences from the Forth standard (or common Forth implementations)
While Henceforth generally tries to adhere to the Forth standard, there are a few notable exceptions:
- Henceforth only supports signed integers as a data type. No other data types are available for use on the stack. (Though technically, _flags_ and _do-sys_ are emulated using signed integers.) 
- Words in Henceforth are case-sensitive. While this is actually standard compliant, common Forth parsers are mostly case-insensitive.
- Other than `\`, Henceforth doesn't support immediate words at the moment.

## Developer documentation
Documentation for developers is available both as part of the source code itself and in the [Wiki](https://github.com/lunakv/henceforth/wiki).
