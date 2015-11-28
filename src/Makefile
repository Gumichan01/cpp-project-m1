
#
# Makefile Projet C++
#


all: library test

test:
	@make -f Makefile.test

library:
	@make -f Makefile.framework


.PHONY : clear clean clean-framework clean-test clear-framework clear-test

clear: clear-framework clear-test
clean: clean-framework clean-test clear-framework clear-test

clean-test:
	@make clean -f Makefile.test

clean-framework:
	@make clean -f Makefile.framework
	
clear-test: 
	@make clear -f Makefile.test

clear-framework:
	@make clear -f Makefile.framework

