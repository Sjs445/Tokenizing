all:
	g++ -o token tokenizing.cpp
	./token
clean:
	rm token