#include <minishell.h>

void	read_prompt()
{

}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
//	char	*line;
//	t_shell	shell;

//	t_shell.l_status = 0;
	/*while(1)
	{
		//line = read_prompt();
		if (!line)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			exit(shell.l_status);
		}
		if (ft_strlen(line) <= 0)
		{
			free(line);
			line = NULL;
			continue;
		}
		ft_printf(1, "%s\n", line);
	}*/
	ft_printf(1, "Hello minishell\n");
	exit(0);
}
