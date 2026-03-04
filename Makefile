CPP = main.cpp wrapper.cpp user.cpp plant.cpp tree.cpp
HPP = top.hpp wrapper.hpp user.hpp plant.hpp tree.hpp
other = Makefile userData.csv plants.csv
target = game

$(target):
	g++ -o $(target) $(CPP) $(HPP)
	chmod o=rwx $(target)
clean:
	rm -f game
save:
	git add $(CPP) $(HPP) $(other)
	git commit -m "new stuff"
	git push
reset:
	clear 
	make clean
	make 
	./game