all: tokenizer i2p codeGen vm test

tokenizer: tokenizermain.c tokenizer.c
	gcc -o tokenizer tokenizermain.c tokenizer.c

i2p: i2p_main.c infix_to_postfix.c
	gcc -o i2p i2p_main.c infix_to_postfix.c

codeGen: main_codeGen.c codeGen.c
	gcc -o codeGen main_codeGen.c codeGen.c

vm: vm_main.c vm.c
	gcc -o vm vm_main.c vm.c

test: test.c
	gcc -o test test.c
	./test
