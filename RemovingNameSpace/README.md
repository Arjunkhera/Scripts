## Removing Namespace and Brackets 

1. Declare directory name in local variable called dirName and export it

```bash
dirName=day1
export dirName
```

2. Here are the makefile instructions 

```make
create:
	bash removeNamespace.sh scriptTest
compile:
	g++ fileRemove.cpp -o test
run:
	./test scriptTest
clean:
	rm ./${dirName}/fileNames.txt

```