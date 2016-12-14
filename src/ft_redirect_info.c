/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 04:34:02 by jbobin            #+#    #+#             */
/*   Updated: 2016/12/14 17:49:00 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_input_num(t_prstruct *proc, char **buf, int i)
{
	unsigned int	info;
	char			*num;
	int				j;

	j = i - 1;
	info = buf[proc->i][i] == '>' ? 1 : 0;
	while (j >= 0 && ft_isdigit(buf[proc->i][j]))
		j--;
	if (++j != i)
	{
		num = ft_strsub(buf[proc->i], j, i - j);
		info = ft_atoi(num) << 8;
		ft_strdel(&num);
	}
	else if (buf[proc->i][i] == '>')
		info = 1 << 8;
	return (info);
}

static int	ft_file_descriptor(t_prstruct *proc, char **buf, int i, int j)
{
	char	*num;

	j++;
	if (buf[proc->i][j] == '-')
		return (4 << 16);
	else if (!ft_isdigit(buf[proc->i][j]))
	{
		ft_putendl_fd("42sh: file number expected", 2);
		exit(1);
	}
	i = j;
	while (ft_isdigit(buf[proc->i][j]))
		j++;
	if (buf[proc->i][j] != ' ' && buf[proc->i][j] != '\0')
	{
		ft_putendl_fd("42sh: file number expected", 2);
		exit(1);
	}
	num = ft_strsub(buf[proc->i], i, j - i);
	j = ft_atoi(num);
	ft_strdel(&num);
	return (j);
}

static int	ft_open_file(char *num, int info)
{
	int		j;
	mode_t	mode;

	if (access(num, F_OK) == -1 && info != 1)
	{
		mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
		if ((j = open(num, O_CREAT, mode)) != -1)
			close(j);
		else
		{
			ft_putstr_fd("42sh: error, cannot create file ", 2);
			ft_putendl_fd(num, 2);
		}
	}
	if (info == 3)
		j = open(num, O_APPEND | O_WRONLY);
	else if (info == 2)
		j = open(num, O_RDWR);
	else if (info == 1)
		j = open(num, O_RDONLY);
	else
		j = open(num, O_WRONLY | O_TRUNC);
	return (j);
}

static int	ft_output_num(t_prstruct *proc, char **buf, int i, int info)
{
	char	*num;
	int		j;

	j = i + 1;
	if (buf[proc->i][j] == '&')
		return (ft_file_descriptor(proc, buf, i, j));
	while (buf[proc->i][j] == ' ')
		j++;
	if ((i = j) && buf[proc->i][j] == '\0')
	{
		ft_putendl_fd("42sh: parse error near `\\n'", 2);
		exit(1);
	}
	while (buf[proc->i][j] != '\0' && buf[proc->i][j] != ' ' && \
		buf[proc->i][j] != '<' && buf[proc->i][j] != '>')
		j++;
	num = ft_strsub(buf[proc->i], i, j - i);
	if ((j = ft_open_file(num, info >> 16)) == -1)
	{
		ft_putstr_fd("42sh: no such file or directory: ", 2);
		ft_putendl_fd(num, 2);
		exit(1);
	}
	ft_strdel(&num);
	return (j);
}

int			ft_findr(t_prstruct *proc, char **buf, int i)
{
	unsigned int	info;

	info = 0;
	if (buf[proc->i][i] == '>')
	{
		if (buf[proc->i][i + 1] == '>')
		{
			info = 3 << 16;
			i++;
		}
	}
	else if (buf[proc->i][i + 1] == '>')
	{
		info = 2 << 16;
		i++;
	}
	else
		info = 1 << 16;
	if (buf[proc->i][i + 1] == '<')
		return (info);
	info += ft_input_num(proc, buf, i);
	info += ft_output_num(proc, buf, i, info);
	if (info >> 16 == 4)
		close(info >> 8 & 255);
	return (info);
}
