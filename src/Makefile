
#
# Makefile Projet C++
#

.PHONY: library test

all: library test


library:
	make -f Makefile.framework

test:
	make -f Makefile.test



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

