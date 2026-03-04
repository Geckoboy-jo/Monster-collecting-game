CPP = main.cpp wrapper.cpp user.cpp plant.cpp tree.cpp list.cpp shop.cpp game.cpp
HPP = top.hpp wrapper.hpp user.hpp plant.hpp tree.hpp list.hpp shop.hpp game.hpp
other = Makefile userData.csv plants.csv gameData.csv
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