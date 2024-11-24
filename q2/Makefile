CC=gcc
CFLAGS=-Wall -Wextra

all: custom_shell custom_cat custom_ls custom_pwd custom_mkdir custom_rmdir custom_wc

custom_shell: shell.c
	$(CC) $(CFLAGS) -o custom_shell shell.c

custom_cat: custom_cat.c
	$(CC) $(CFLAGS) -o custom_cat custom_cat.c

custom_ls: custom_ls.c
	$(CC) $(CFLAGS) -o custom_ls custom_ls.c

custom_pwd: custom_pwd.c
	$(CC) $(CFLAGS) -o custom_pwd custom_pwd.c

custom_mkdir: custom_mkdir.c
	$(CC) $(CFLAGS) -o custom_mkdir custom_mkdir.c

custom_rmdir: custom_rmdir.c
	$(CC) $(CFLAGS) -o custom_rmdir custom_rmdir.c

custom_wc: custom_wc.c
	$(CC) $(CFLAGS) -o custom_wc custom_wc.c

clean:
	rm -f custom_shell custom_cat custom_ls custom_pwd custom_mkdir custom_rmdir custom_wc