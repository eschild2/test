
# list the name of each file (without the .cpp file at the end)
EXE = testPList IntegerSetWithIterator_test IntInf_test

all: $(EXE)

run: all $(addsuffix -run,$(EXE))

clean:
	rm -f $(EXE) *~ logfile.txt $(ECE)

%: %.cpp
	$(CXX) -o $@ $< -Wall -Werror -std=c++11 -I ../include -L ../lib -lece309

%-run:
	@./$*

