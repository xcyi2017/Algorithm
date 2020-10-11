CC = gcc 
# 生成多个可执行文件: all 第一条命令 第二条命令 ....
CFLAGS = -lm -Wall -g # 链接外部库
main: findKthLargest_.c utils.o # 默认只执行第一条可以生成可执行文件的命令
	$(CC) $(CFLAGS) findKthLargest_.c utils.o -o main
utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c
clean:
	rm *.o main
