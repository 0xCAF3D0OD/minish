/*int	child_process(int *fd, char **cmd, char **env)
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		printf("Error:\n");
	close(fd[1]);
	if (execve(cmd[0], cmd, env) < 0)
	{
		printf("minishell: %s command execution failed\n", cmd[0]);
		return (0);
	}
	return (1);
}

int	parent_process(int *fd, char **cmd, char **env)
{
	int	pid;

	close(fd[1]);
	pid = fork();
	if (!pid)
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
		{
			printf("Error: duplicating filedescriptor 0\n");
			exit (EXIT_FAILURE);
		}
		printf("path test: %s\n", cmd[1]);
		if (execve(cmd[0], cmd, env) < 0)
		{
			printf("Minishell: %s executing command failed\n", cmd[0]);
			exit (EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		close(fd[0]);
	else
	{
		printf("Minishell: error in parrent pocess\n");
	}
	return (1);
}
*/
