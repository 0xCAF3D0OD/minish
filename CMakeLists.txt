cmake_minimum_required(VERSION 3.22)
project(minish C)

set(CMAKE_C_STANDARD 11)

include_directories(incs)
include_directories(incs/minishell)
include_directories(libft/incs)
include_directories(libft/incs/libft)


add_compile_options(-Wall -Werror -Wextra)
add_link_options(-lreadline)

include_directories(~/.brew/opt/readline/include)
link_directories(~/.brew/opt/readline/lib)

add_executable(minish
        incs/minishell.h
        libft/incs/libft/ft_chars.h
        libft/incs/libft/ft_dlst.h
        libft/incs/libft/ft_fds.h
        libft/incs/libft/ft_lst.h
        libft/incs/libft/ft_mems.h
        libft/incs/libft/ft_nbrs.h
        libft/incs/libft/ft_printf.h
        libft/incs/libft/ft_strs.h
        libft/incs/libft.h
        libft/srcs/ft_chars/ft_isalnum.c
        libft/srcs/ft_chars/ft_isalpha.c
        libft/srcs/ft_chars/ft_isascii.c
        libft/srcs/ft_chars/ft_isdigit.c
        libft/srcs/ft_chars/ft_isprint.c
        libft/srcs/ft_chars/ft_isspace.c
        libft/srcs/ft_chars/ft_putchar.c
        libft/srcs/ft_chars/ft_tolower.c
        libft/srcs/ft_chars/ft_toupper.c
        libft/srcs/ft_dlst/ft_dlstnew.c
        libft/srcs/ft_fds/ft_putchar_fd.c
        libft/srcs/ft_fds/ft_putendl_fd.c
        libft/srcs/ft_fds/ft_putnbr_fd.c
        libft/srcs/ft_fds/ft_putstr_fd.c
        libft/srcs/ft_fds/get_next_line.c
        libft/srcs/ft_lst/ft_lstadd_back.c
        libft/srcs/ft_lst/ft_lstadd_front.c
        libft/srcs/ft_lst/ft_lstclear.c
        libft/srcs/ft_lst/ft_lstdelone.c
        libft/srcs/ft_lst/ft_lstiter.c
        libft/srcs/ft_lst/ft_lstlast.c
        libft/srcs/ft_lst/ft_lstmap.c
        libft/srcs/ft_lst/ft_lstnew.c
        libft/srcs/ft_lst/ft_lstsize.c
        libft/srcs/ft_mems/ft_bzero.c
        libft/srcs/ft_mems/ft_calloc.c
        libft/srcs/ft_mems/ft_memchr.c
        libft/srcs/ft_mems/ft_memcmp.c
        libft/srcs/ft_mems/ft_memcpy.c
        libft/srcs/ft_mems/ft_memmove.c
        libft/srcs/ft_mems/ft_memset.c
        libft/srcs/ft_nbrs/ft_atof.c
        libft/srcs/ft_nbrs/ft_atoi.c
        libft/srcs/ft_nbrs/ft_itoa.c
        libft/srcs/ft_printf/ft_print_c.c
        libft/srcs/ft_printf/ft_print_nbr.c
        libft/srcs/ft_printf/ft_print_str.c
        libft/srcs/ft_printf/ft_printf.c
        libft/srcs/ft_printf/utils.c
        libft/srcs/ft_strs/ft_putstr.c
        libft/srcs/ft_strs/ft_split.c
        libft/srcs/ft_strs/ft_strchr.c
        libft/srcs/ft_strs/ft_strdup.c
        libft/srcs/ft_strs/ft_striteri.c
        libft/srcs/ft_strs/ft_strjoin.c
        libft/srcs/ft_strs/ft_strlcat.c
        libft/srcs/ft_strs/ft_strlcpy.c
        libft/srcs/ft_strs/ft_strlen.c
        libft/srcs/ft_strs/ft_strmapi.c
        libft/srcs/ft_strs/ft_strncmp.c
        libft/srcs/ft_strs/ft_strnstr.c
        libft/srcs/ft_strs/ft_strrchr.c
        libft/srcs/ft_strs/ft_strtrim.c
        libft/srcs/ft_strs/ft_substr.c
        srcs/quotes/quotes.c
        srcs/arg_utils.c
        srcs/ascii_init.c
        srcs/builtin.c
        srcs/cmd_utils.c
        srcs/env_utils.c
        srcs/error.c
        srcs/exec_cmds.c
        srcs/fd_utils.c
        srcs/free.c
        srcs/ft_export.c
        srcs/heredocing.c
        srcs/main.c
        srcs/parsing.c
        srcs/path_utils.c
        srcs/pipe.c
        srcs/piping.c
        srcs/prompt.c
        srcs/quotes_utils.c
        srcs/redirection.c
        srcs/signal_utils.c
        srcs/str_utils.c
        srcs/tokenizing.c
        srcs/utils.c
        srcs/vars_utils.c)
