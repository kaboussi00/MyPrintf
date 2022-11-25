NAME = libftprintf.a
INC = ft_printf.h
SRCS = ft_printf.c\
		ft_utils1.c\
		ft_utils2.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

AR = ar -r

CC = cc

all:$(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all