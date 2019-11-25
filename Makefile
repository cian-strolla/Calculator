all: tokenizer i2p codeGen vm

tokenizer: tokenizermain.c tokenizer.c
	gcc -o tokenizer tokenizermain.c tokenizer.c

i2p: i2p_main.c infix_to_postfix.c
	gcc -o i2p i2p_main.c infix_to_postfix.c

codeGen: main_codeGen.c codeGen.c
	gcc -o codeGen main_codeGen.c codeGen.c

vm: vm_main.c vm.c
	gcc -o vm vm_main.c vm.c

test: test.c test_tokenizer test_i2p test_codeGen test_vm
	gcc -o tester test.c
	./tester

test_tokenizer: tokenizer.c test_tokenizer.c
	gcc -o test_tokenizer tokenizer.c test_tokenizer.c
	./test_tokenizer
	prove ./test_tokenizer

test_i2p: infix_to_postfix.c test_i2p.c
	gcc -o test_i2p infix_to_postfix.c test_i2p.c
	./test_i2p
	prove ./test_i2p

test_codeGen: codeGen.c test_codeGen.c
	gcc -o test_codeGen codeGen.c test_codeGen.c
	./test_codeGen
	prove ./test_codeGen

test_vm: vm.c test_vm.c
	gcc -o test_vm vm.c test_vm.c
	./test_vm
	prove ./test_vm