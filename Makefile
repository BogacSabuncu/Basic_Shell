# in EC327, we use the ${GCC} compiler
# therefore, we define the GCC variable
GCC = g++ 

myshell: myshell.o
	${GCC} myshell.o -o myshell

