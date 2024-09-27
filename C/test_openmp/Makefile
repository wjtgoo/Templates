CC        = gcc
# compile configs
CFLAGS = -Wall -fopenmp
# link configs
LDFLAGS = -shared -fPIC 
LIBS = -lm

# 目标:hello, 依赖文件: hello_world.o, $@: 代指目标, $^表示所有的依赖文件
# das: das.c
# 	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)