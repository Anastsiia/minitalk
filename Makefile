SRSS		= server.c
SRSC		= client.c

OBJS		= $(SRSS:.c=.o)
OBJC		= $(SRSC:.c=.o)

HEADER		= minitalk.h

CC = gcc

WWW = -Wall -Werror -Wextra

all:	server client

server:		$(OBJS) $(HEADER)
				$(CC) $(WWW) $(OBJS) -o server

client:		$(OBJC) $(HEADER)
				$(CC) $(WWW) $(OBJC) -o client

clean:
		rm -f $(OBJS)
		rm -f $(OBJC)

fclean:	 clean
		rm -f server client

re:	fclean all

.PHONY:	all clean fclean re
