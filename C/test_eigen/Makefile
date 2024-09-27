CC        = g++
# compile configs
CFLAGS = -Wall -I /usr/local/include/eigen3
# link configs
LIBS = -lm

# 目标:hello, 依赖文件: hello_world.o, $@: 代指目标, $^表示所有的依赖文件
# das: das.c
# 	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

hello: helloworld.cpp
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)