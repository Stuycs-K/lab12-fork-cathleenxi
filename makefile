.PHONY: run compile clean
run: fork
	@./fork
compile fork: main.c
	@gcc -o fork -Wall main.c
clean:
	@rm -f *.o
	@rm fork
