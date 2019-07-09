#
# this makefile can be use to build and run the entire suite pn all VMs
#
#     make -f tests.mk ALETH=aleth EVMONE=path-to-evmone GETH=evm PARITY=parity-evm all
#
# or build and run only a single test on a single VM
#
#     make -f tests.mk ALETH=aleth pop.ran
#
# or build but not run the entire suite 
#
#     make -f tests.mk all
#
# or many other such possibilities

# the VM programs don't need to be at global scope
#
#     make -f tests.mk ALETH=../../../build/aleth/aleth all

# define a path to these programs on make command line to pick one or more of them to run
# the default is to do nothing
#
ifdef GETH
	GETH_ = $(call STATS,geth,$*) $(GETH) --codefile $*.bin  --statdump run 2>&1 touch $*.ran
endif
ifdef PARITY
	PARITY_ = $(call STATS,parity,$*) $(PARITY) stats --gas 10000000000 --code `cat $*.bin`; touch $*.ran
endif
ifdef ALETH
	ALETH_ = $(call STATS,aleth,$*) $(ALETH) --vm interpreter test $*.bin; touch $*.ran
endif
ifdef EVMONE
	EVMONE_ = $(call STATS,evmone,$*) $(ALETH) --vm $(EVMONE) test $*.bin; touch $*.ran
endif
ifdef WASM
	WASM_ = $(call STATS,wasm,$*) $(WASM) ./$*.wasm; touch $*.wran
endif

STATS = echo $(1) $(2) 1>&2 ; time -p

#
# to support new clients
#   *  add new calls here
#   *  add corresponding functions above
#   *  add corresponding .ran targets below
#
# ran files are just empty targets that indicate a program ran
%.ran : %.bin
	$(call GETH_)
	$(call PARITY_)
	$(call ALETH_)
	$(call EVMONE_)

%.cran : %.c
	gcc -O3 -S -I . $*.c
	gcc -o $* $*.s
	$(call STATS,C,$*) ./$*; touch $*.cran
	
%.cran : %.cpp
	g++ -O3 -S -std=c++11 -I . $*.cpp
	g++ -o $* $*.s
	$(call STATS,C,$*) ./$*; touch $*.cran
	
%.wran : %.wasm
	$(call WASM_)

# hold on to intermediate binaries until source changes
.PRECIOUS : %.bin %.wast %.wasm

%.bin : %.asm
	solc --assemble $*.asm | grep '^[0-9a-f]\+$\' > $*.bin

%.bin : %.sol
	solc -o . --overwrite --optimize --asm --bin $*.sol 

%.wasm : %.c
	emcc -s WASM=1 -O3 $*.c -o $*.js

%.wasm : %.cpp
	emcc -s WASM=1 -O3 -std=c++11 $*.cpp -o $*.js

%.wasm : %.bin
	evm2wasm $*.bin > $*.wast
	wat2wasm $*.wast -o $*.wasm


all : ops programs C  # W

# EVM assembly programs for timing individual operators
#
# for many purposes the raw times will suffice.  when more accurate estimates
# are wanted these formulas isolate the times for operators from the overhead
#   * t(nop) = user time for nop is just start up, shut down, and interpreter overhead
#   * t(pop) = user time for pop can be much less than big arithmetic OPs
#   * (t(OP) - (t(pop) + t(nop))/2)/N = estimated time per OP, less all overhead
# for all tests except exp N = 2**27, for exp N=2**17 and the last formula gets trickier
ops : \
	nop.ran \
	pop.ran \
	add64.ran \
	add128.ran \
	add256.ran \
	sub64.ran \
	sub128.ran \
	sub256.ran \
	mul64.ran \
	mul128.ran \
	mul256.ran \
	div64.ran \
	div128.ran \
	div256.ran \
	exp.ran

# Solidity programs for more realistic timing
programs : \
	loop.ran \
	fun.ran \
	pmul.ran \
	rng.ran \
	rc5.ran \
	mix.ran

# C/C++ versions for comparison
# note that except for mul64.c these use a different library than the EVM version
# so results are not entirely comparable
C : \
	popincc.cran \
	poplnkc.cran \
	mul64c.cran \
	add256c.cran \
	sub256c.cran \
	mul256c.cran \
	div256c.cran \
	expc.cran \
	func.cran \
	rc5c.cran \
	mixc.cran \
	rngc.cran \
	pmulc.cran

# wasm versions for comparison
W : \
	add256.wran \
	sub256.wran \
	mul256.wran \
	div256.wran \
	exp.wran \
	add256c.wran \
	sub256c.wran \
	mul256c.wran \
	div256c.wran \
	expc.wran \
	fun.wran \
	rc5.wran \
	mix.wran \
	rng.wran \
	pmul.wran \
	func.wran \
	rc5c.wran \
	mixc.wran \
	rngc.wran \
	pmulc.wran

clean :
	rm *.ran *.cran *.wran *.wast* *.wasm *c.js *.bin *.evm *.s mul64c poplnkc popincc
	
rerun :
	rm *.ran
