
int loadStringFromFile(char *inputfile);
int toToken();
int printToFile(char *outputfile);


int main() {

  loadStringFromFile("input.txt");

  toToken();

  printToFile("infix.txt");

  return(0);
}
