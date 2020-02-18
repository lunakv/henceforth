# Henceforth
This is Henceforth, a simple interpreter for a Forth-like stack-based language.

## Installation
For compiling from the source, clone this repository and then run
```bash
cd ${HF_DIR} && cmake . && make
```
where `${HF_DIR}` is the path to the cloned directory. The binary will then be compiled to `./henceforth`

## Usage
```bash
henceforth [-e] [file.fth ...]
```

Henceforth accepts any number of file names as arguments. It interprets all the files specified in order and then opens an interactive user shell on standard input. The interactive shell will not be spawned if the user supplies the `-e` option.
## Supported commands
Henceforth supports the following words from the Forth CORE dictionary:
- `+`, `-`, `*`, `/`, `MOD`, `/MOD`, `RSHIFT`, `LSHIFT`
- `1+`, `1-`, `2*`, `2/`, `0=`, `0<`
- `TRUE`, `FALSE`
- `<`, `>`, `=`, `<>`, `MAX`, `MIN`, `WITHIN`
- `AND`, `OR`, `XOR`, `NEGATE`, `INVERT`
- `DUP`, `DROP`, `.`, `CR`, `SWAP`, `OVER`, `DEPTH`
- `:`, `;`, `\`, `(` 

In addition, Henceforth supports the following Forth words exclusively in the compilation environment:
- `IF`, `ELSE`, `THEN`, `BEGIN`, `WHILE`, `REPEAT`, `AGAIN`
- `DO`, `?DO`, `LOOP`, `+LOOP`, `LEAVE`, `UNLOOP`, `I`, `J`
- `."`, `RECURSE`, `EXIT` 

To find out more about the usage of the words listed above, see the [Forth standard](https://forth-standard.org/standard/core) website.

## Differences from the Forth standard
While Henceforth generally tries to adhere to the Forth standard, there are a few notable exceptions:
- Henceforth only supports signed integers as a data type. No other data types are available for use on the stack. (Technically, _flags_ and _do-sys_ are emulated using signed integers.) 
- Other than `\` and `(`, Henceforth doesn't support immediate words at the moment.
- The `LOOP` word checks if the index is equal _or greater_ than the limit, rather than checking for strict equality. 

## Developer documentation
Documentation for developers is available both as part of the source code itself and in the [Wiki](https://github.com/lunakv/henceforth/wiki).
