CPP = main.cpp wrapper.cpp
HPP = top.hpp wrapper.hpp
other = Makefile
target = game

$(target):
	g++ -o $(target) $(CPP) $(HPP)
	chmod o=rwx $(target)
clean:
	rm -f $(Target)
save:
	git add $(CPP) $(HPP) $(other)
	git commit -m "new stuff"
	git push
reset:
	clear 
	make clean
	make 
	./game