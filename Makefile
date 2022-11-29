NAME = libftprintf.a
INC = ft_printf.h
SRCS = ft_printf.c\
		ft_utils1.c\
		ft_utils2.c	

SRCS_B = ft_utilsbonus.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)
RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

AR = ar -r

CC = cc

all:$(NAME)
$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus:$(OBJS_B)
	$(AR) $(NAME) $(OBJS_B)

%.o:%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:clean
	$(RM) $(NAME)

re: fclean all