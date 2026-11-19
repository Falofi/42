CC			= cc
CFLAGS		= -Wall -Wextra -Werror
BUFFER_SIZE	?= 42

SRC			= get_next_line.c \
			  get_next_line_utils.c

OBJ			= $(SRC:.c=.o)

all: $(OBJ)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
