gcc -g3 -fsanitize=address main.c ft_export.c builtin.c tokenizing.c parsing.c prompt.c exec_cmds.c piping.c ascii_init.c free.c error.c str_utils.c quotes/quotes.c quotes_utils.c arg_utils.c vars_utils.c cmd_utils.c fd_utils.c heredocing.c redirection.c signal_utils.c env_utils.c path_utils.c ../libs/libft/libft.a -I ~/.brew/Cellar/readline/8.1.1/include -lreadline -L ~/.brew/Cellar/readline/8.1.1/lib -o minishell && ./minishell