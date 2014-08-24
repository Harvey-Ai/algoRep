all:
	@make -C dataStruct
	@make -C Test
#@make -C algorithm

.PHONY: clean

clean:
	@make clean -C algorithm
	@make clean -C dataStruct
	@make clean -C Test
