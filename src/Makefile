
#
# Makefile Projet C++
#

.PHONY: library test doxy

all: demo


library:
	@make -f Makefile.framework

test:
	@make -f Makefile.test

demo: library
	@make -f Makefile.demo


doxy:
	doxygen dox


.PHONY : clear clean clean-framework clean-test clear-framework clear-test

clear: clear-framework clear-test
clean: clean-framework clean-test clean-demo


clean-test:
	@make clean -f Makefile.test

clean-framework:
	@make clean -f Makefile.framework

clean-demo:
	@make clean -f Makefile.demo


clear-test: 
	@make clear -f Makefile.test

clear-framework:
	@make clear -f Makefile.framework

