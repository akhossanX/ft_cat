# ft_cat
`Reproduce the same behavior of the Unix command 'cat'`

## Installation
Under the project root directory, there is a Makefile, once launched it will
build the entire project for you and generate an executable binary named `ft_cat` 

## Usage:
`./ft_cat [OPTION]... [FILE]...`

Concatenate FILE(s) to standard output.

With no FILE, or when FILE is `-`, read standard input.

  `-A, --show-all`           equivalent to `-vET`

  `-b, --number-nonblank`    number nonempty output lines, overrides `-n`

  `-e`                      equivalent to `-vE`

  `-E, --show-ends`          display `$` at end of each line

  `-n, --number `            number all output lines

  `-s, --squeeze-blank`      suppress repeated empty output lines

  `-t `                      equivalent to `-vT`

  `-T, --show-tabs`          display TAB characters as `^I`

  `-v, --show-nonprinting`   use `^` and `M-` notation, except for `LFD` and `TAB`.

   `--help `    display this help and exit

  ` --version`  output version information and exit

## Examples:
```bash
  $> ./ft_cat f - g
``` 
 Output `f`'s content, then standard input, then `g`'s content.

  ```bash 
  $> ./ft_cat 
  ```       
 Copy standard input to standard output.

