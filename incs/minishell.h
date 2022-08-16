#ifndef MINISHELL_H
#define MINISHELL_H

#include <libft.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <readline/readline.h>
#include <readline/history.h>

#include <termios.h>
#include <term.h>

#include <fcntl.h>

typedef struct	s_shell {
	int	l_status;	//last status code TODO: maybe global?
}	t_shell;

#endif //MINISHELL_H
