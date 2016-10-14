/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayet <tbayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:17:57 by tbayet            #+#    #+#             */
/*   Updated: 2016/10/14 15:46:54 by tviviand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOCOMPLETION_H
# define AUTOCOMPLETION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include "libft/includes/libft.h"

# define MAX_NB_AFF 120

typedef struct		s_files
{
	char			*name;
	struct s_files	*prev;
	struct s_files	*next;
}					t_files;

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_exec
{
	char			c;
	char			*name;
	int				nbelems;
	struct s_exec	*next;
	struct s_exec	*change;
}					t_exec;

typedef struct		s_dim
{
	int				x;
	int				y;
}					t_dim;

char				**tfiles_totab(t_files **lst);
char				**tfiles_getlst(char *pwd, char *str);
t_files				*tfiles_del(t_files **lst);
t_exec				*texec_new(char c, char *name);
char				**complete_me(char *str, t_exec *tree);
int					texec_check(char *name, t_exec *tree);
t_exec				**texec_add(char *file, t_exec **tree);
t_exec				*files_sort(char **files);
t_exec				*texec_del(t_exec **tree);
t_exec				*create_tree(char **env);
char				**ft_get_path(char **environ);

#endif
