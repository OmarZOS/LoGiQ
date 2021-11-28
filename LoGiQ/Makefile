


VV=~/Proj/LoGiQ/
DIE=OBJ_files
OBJS=LoGiQ.o main.o




all: $(OBJS) 
	g++ $(OBJS) -o exe -lsfml-graphics -lsfml-audio  -lsfml-window -lsfml-system
	@./exe&

.PHONY: all



$(OBJS)::%.o: %.cpp
%.cpp: %.h
	g++ -c $@

main.o:: main.cpp
	g++ -c main.cpp
test:
	@./exe
install:
	sudo apt-get install libsfml-dev
org: $(DIE)
	mv *.o $(DIE)
clr:
	rm -rf $(DIE)
	rm tst
	rm *.o
OBJ_files:
	mkdir $(DIE)
hey:
	cd -
	cd $(VV)
	ls
	


