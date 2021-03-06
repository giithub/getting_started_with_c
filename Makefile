OUT = bin/
$(shell mkdir -p $(OUT))

all:
	gcc input_output.c -o bin/choose_number
	gcc command_line.c -o bin/command_line
	gcc data_type.c -o bin/data_type
	gcc function.c -o bin/function
	gcc loop.c -o bin/loop
	gcc read_file.c -o bin/read_file
	gcc reference.c -o bin/ref
	gcc sscanf.c -o bin/sscanf
	gcc hello.c -o bin/say_hello
	gcc cond.c -o bin/root_two
	gcc switch_case.c -o bin/switch
	gcc pointer.c -o bin/pointer
	gcc structure.c -o bin/structure
clean:
	rm -rf bin

