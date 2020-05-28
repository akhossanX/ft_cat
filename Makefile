
TARGET	=	ft_cat

CFLAGS	=	-Werror -Wall -Wextra -g

CC		=	gcc

SRCDIR	=	srcs/

SRCS	=	$(shell ls $(SRCDIR))

INCDIR	=	includes/

LIBS	=	libft/libft.a

INC		=	-I$(INCDIR)

OBJDIR	=	objs/

OBJS	=	$(addprefix $(OBJDIR), $(SRCS:.c=.o))

HEADERS	=	$(addprefix $(INCDIR), $(shell ls $(INCDIR)))

all: $(OBJDIR) $(TARGET)

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
	$(CC) -c $< $(INC) -o $@

$(OBJDIR):
	@mkdir -p $@

$(TARGET): $(OBJS) $(LIBS) 
	$(CC) $^ -o $@

$(LIBS):
	@make -C libft/

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -rf $(TARGET)
	@make -C libft/ fclean

re: fclean all
