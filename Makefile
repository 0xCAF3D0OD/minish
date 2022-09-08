SHELL = /bin/sh

CFLAGS := ${CFLAGS}

CC     ?= gcc
LD     ?= gcc

INC_FLAGS := -Ilibft/incs
LIBS := -Llibft -lft -lreadline

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
#	NPROC := $(shell nproc)
else
#	NPROC := $(shell sysctl -n hw.ncpu)
	INC_FLAGS += -I$(HOME)/.brew/opt/readline/include
    LIBS += -L$(HOME)/.brew/opt/readline/lib
endif

MAKEFLAGS += --output-sync=target
MAKEFLAGS += --no-print-directory

NAME ?= minishell

BUILD_DIR ?= ./build
SRC_DIRS ?= ./srcs
INC_DIR ?= ./incs

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

INC_DIRS := $(shell find $(INC_DIR) -type d)
INC_FLAGS += $(addprefix -I,$(INC_DIRS))

LIB    := libft/libft.a

CFLAGS += -Wall -Wextra -g3 #-Werror
#CFLAGS += -O2 -march=native
#CFLAGS += -g3

all:
	@$(MAKE) $(NAME)

$(NAME): $(LIB) $(OBJS)
	@echo Linking $@
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $@
	@mkdir -p $(dir $@)
	@$(CC) -c  $(CFLAGS) $(INC_FLAGS) $< -o $@

$(LIB):
	@$(MAKE) -C libft
	@echo Libft done

docker:
	docker build -t archi .
	docker run -it archi

prune:
	docker system prune -a --volumes

clean:
	@rm -rf $(BUILD_DIR)
	@$(MAKE) -C libft clean
	@echo Clean done

fclean:
	@rm -rf $(BUILD_DIR)
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo Fclean done

re: fclean
	@$(MAKE) -j$(NPROC) $(NAME)


build:
	docker build -t archi .

run:
	docker run -it archi

prune:
	docker system prune -a --volumes

.PHONY: all clean fclean re
