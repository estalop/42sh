/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 01:13:21 by jbobin            #+#    #+#             */
/*   Updated: 2016/09/22 14:49:22 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_write(t_prstruct *proc, char **buf, int new, int i)
{
	int		input;
	int		output;

	input = (new >> 8) & 255;
	output = new & 255;
	if (input == 1 && i > 0 && buf[proc->i][i - 1] == '&')
	{
		close(STDOUT_FILENO);
		dup2(output, STDOUT_FILENO);
		close(STDERR_FILENO);
		dup2(STDOUT_FILENO, STDERR_FILENO);
	}
	dup2(output, input);
}

static void	ft_read(t_prstruct *proc, char **buf, int new, int i)
{
	int		input;
	int		output;
	int		pipes[2];
	t_hered	*tmp;

	if (buf[proc->i][i + 1] != '<')
	{
		input = (new >> 8) & 255;
		output = new & 255;
		dup2(output, input);
	}
	else
	{
		if (proc->herepipe == -1)
		{
			pipe(pipes);
			dup2(pipes[0], STDIN_FILENO);
			proc->herepipe = pipes[1];
		}
		write(proc->herepipe, proc->heredoc->str, ft_strlen(proc->heredoc->str));
		tmp = proc->heredoc;
		proc->heredoc = proc->heredoc->next;
		ft_strdel(&tmp->str);
		free(tmp);
	}
}

static char	*ft_trunc_buf(t_prstruct *proc, char **buf, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	int		j;
	int		start;

	start = 0;
	tmp = NULL;
	while (buf[proc->i][i] != '\0')
	{
		if (buf[proc->i][i] == '<' || buf[proc->i][i] == '>')
		{
			j = i - 1;
			while (ft_isdigit(buf[proc->i][j]) && j > 0)
				j--;
			if (tmp == NULL)
				tmp = ft_strsub(buf[proc->i], start, j - start);
			else
			{
				tmp2 = ft_strsub(buf[proc->i], start, j - start);
				tmp3 = ft_strjoin(tmp, tmp2);
				ft_strdel(&tmp);
				ft_strdel(&tmp2);
				tmp = tmp3;
			}
			while (buf[proc->i][i] == '<' || buf[proc->i][i] == '>' || \
					buf[proc->i][i] == '&')
				i++;
			while (buf[proc->i][i] == ' ')
				i++;
			while (buf[proc->i][i] != '\0' && buf[proc->i][i] != ' ')
				i++;
			start = i;
		}
		i++;
		if (buf[proc->i][i] == '\0' && tmp != NULL)
		{
			tmp2 = ft_strsub(buf[proc->i], start, i);
			tmp3 = ft_strjoin(tmp, tmp2);
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
			tmp = tmp3;
		}
	}
	return (tmp);
}

void		ft_redirect(t_prstruct *proc, char **buf)
{
	void	(*functionlist[2])(t_prstruct*, char**, int, int);
	int		i;
	int		new;
	char	*tmp;

	i = proc->s;
	functionlist[0] = ft_write;
	functionlist[1] = ft_read;
	tmp = ft_trunc_buf(proc, buf, i);
	while (buf[proc->i][i] != '\0')
	{
		if (buf[proc->i][i] == '>' || buf[proc->i][i] == '<')
		{
			new = ft_findr(proc, buf, i);
			if (new >> 16 == 3)
				new -= 3 << 16;
			if (new >> 16 < 2)
				functionlist[new >> 16](proc, buf, new, i);
			while (buf[proc->i][i] == '>' || buf[proc->i][i] == '<')
				i++;
		}
		i++;
	}
	ft_strdel(&buf[proc->i]);
	buf[proc->i] = tmp;
}
