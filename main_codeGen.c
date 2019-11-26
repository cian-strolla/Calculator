/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
This program takes postfix notation and generates
the code for the virtual machine.
*/


#include <stdio.h>
#include "codeGen.h"

int main() {
  readFile();
  codeGenerator();
  writeFile();
}
