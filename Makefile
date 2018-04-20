all: assignment_final

WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2

assignment_final: Makefile assignment_final.cc
	$(CXX) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) assignment_final.cc

clean:
	rm -f assignment_final

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"
	make run

# Builder uses this target to run your application.
run:
	./assignment_final

