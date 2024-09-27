CC        = gcc


# compile configs
CFLAGS = -g -Wall
# -fPIC: Position-Independent Code
CLDFLAGS = -shared -Wall -fPIC 
# link configs
LFLAGS = -lm

# 当make发现.o目标不存在或者老的时候，自动运行以下命令. Note: $< 表示所依赖的第一个文件名xxx.c
# %.o : %.c
# 	$(CC) $(CFLAGS) -c $<
# 	@echo "Compiled $< to $@"
# 目标:hello, 依赖文件: hello_world.o, $@: 代指目标, $^表示所有的依赖文件



naive_cal_pi: naive_cal_pi.c
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)
	
libcal_pi.so: cal_pi.c
	$(CC) $(CLDFLAGS) -o $@ $^ $(LFLAGS)