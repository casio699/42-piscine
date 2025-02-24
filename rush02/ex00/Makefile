NAME = rush-02

SRCS = main.c \
       dict_utils.c \
       number_utils.c \
	   number_utils2.c \
       string_utils.c \
	   string_utils2.c \
	   get_written_form.c \


OBJECTS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run

