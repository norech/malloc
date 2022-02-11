##
## EPITECH PROJECT, 2020
## malloc
## File description:
## Makefile
##

CC = gcc

AR = ar rc

CFLAGS = -fPIC -W -Wall -Werror -I./include -g3

CFLAGS_TEST = $(CFLAGS) -Wno-stringop-truncation -Wno-error=format --coverage

LFLAGS = \

LFLAGS_TEST = $(LFLAGS) -lcriterion

ifeq ($(DEBUG), 1)
	CFLAGS += -DDEBUG
endif

SRC =	src/alignment.c \
		src/alloc_free.c \
		src/alloc_list.c \
		src/allocate_memory.c \
		src/malloc.c \
		src/free.c \
		src/calloc.c \
		src/realloc.c \
		src/reallocarray.c \

TEST_FILES =	\

OBJ = $(SRC:.c=.o)

TARGET = libmy_malloc.so

TARGET_TEST = unit_tests

all: build_all

build_all: $(OBJ)
	gcc -shared -fPIC -o $(TARGET) $(OBJ)

tests_run: clean_tests
	$(CC) $(CFLAGS) $(CFLAGS_TEST) -o $(TARGET_TEST) $(SRC) $(TEST_FILES) \
		$(LFLAGS)
	./$(TARGET_TEST) --verbose

clean_tests:
	rm -rf $(TARGET_TEST)

coverage: tests_run
	gcovr

clean:
	rm -f $(OBJ) *.gc* unit_test

fclean: clean
	rm -f $(TARGET)

re: fclean all
