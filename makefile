all:
	@make -C dataStructure
	@make -C graph
	@make -C number
	@make -C string
	@make -C Test

.PHONY: clean

clean:
	-make clean -C graph
	-make clean -C dataStruct
	-make clean -C string
	-make clean -C number
	-make clean -C Test
