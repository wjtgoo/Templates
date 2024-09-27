CC        = gcc
# compile configs
CFLAGS = -g -Wall
CshareFLAGS = -Wall -fPIC 
# link configs
LFLAGS = -lm -lopenblas

# 目标:hello, 依赖文件: hello_world.o, $@: 代指目标, $^表示所有的依赖文件
hello: hello_world.c
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)
	