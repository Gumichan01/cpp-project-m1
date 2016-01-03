
#
# Makefile Projet C++
#

.PHONY: library doxy

all: demo


library:
	@make -f Makefile.framework

demo: library
	@make -f Makefile.demo


doxy:
	doxygen dox


.PHONY : clear clean clean-framework clean-test clear-framework clear-test

clear: clear-framework
clean: clean-framework clean-demo


clean-framework:
	@make clean -f Makefile.framework

clean-demo:
	@make clean -f Makefile.demo

clear-framework:
	@make clear -f Makefile.framework

