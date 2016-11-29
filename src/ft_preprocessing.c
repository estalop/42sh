/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <jbobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:52:02 by jbobin            #+#    #+#             */
/*   Updated: 2016/11/29 15:54:04 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_pipe(t_prstruct *proc, char **buf, char **path)
{
	int	e;

	while (proc->i <= proc->npipe)
	{
		proc->s = 0;
		while (buf[proc->i][proc->s] == '\t' || buf[proc->i][proc->s] == ' ')
			proc->s++;
		e = ft_exe_builtin(proc->s, buf[proc->i], proc);
		if ((proc->bin = ft_check_bin(buf[proc->i], proc->env[2], path, 0)))
		{
			proc->father = ft_fork(&proc->list);
			if (proc->father == 0)
				ft_son(proc, buf, proc->env, e);
			else if (proc->i > 0)
				ft_close_pipe(proc->pipe, proc);
		}
		else if (proc->i > 0)
			ft_close_pipe(proc->pipe, proc);
		ft_strdel(&proc->bin);
		proc->i++;
	}
	while (proc->father && proc->father != proc->id)
	{
		proc->id = wait(&proc->stat_lock);
		ft_kill_process(&proc->list, proc->id);
	}
}

static void	ft_process(char *buf, t_prstruct *process, char **path, \
						t_hered *heredoc)
{
	char	**tmp;

	process->i = 0;
	while (buf[process->i] == ' ' || buf[process->i] == '\t')
		process->i++;
	if (buf[process->i] == '\0')
		return ;
	signal(2, &ft_sig_stop_ex);
	process->list = NULL;
	process->i = 0;
	process->heredoc = heredoc;
	if ((process->npipe = ft_count_pipe(buf)) == -1)
	{
		ft_putendl_fd("42sh: parse error", 2);
		signal(2, &ft_signal_stop);
		return ;
	}
	process->pipe = ft_create_pipe(process->npipe);
	tmp = ft_strsplit(buf, '|');
	ft_pipe(process, tmp, path);
	ft_free_tab(&tmp);
	ft_free_list(&process->list);
	process->stat_lock = ft_returnofprocess(process->stat_lock);
	signal(2, &ft_signal_stop);
}

char		**ft_preprocesssplit(char *l, t_operators *t)
{
	char	**com;
	int		i;
	int		j;
	char	*c;

	//DECLARATIONS
	j = 0;
	com = NULL;
	i = 0;
	c = NULL;
	//ANTI CRASH
	if (!l)
		return (NULL);
	//COMPTE LE NOMBRE DE SPLITS THEORIQUES STOCK DANS I
	i += ft_strcnts(l, "&&");
	i += ft_strcnts(l, "||");
	i ? i = i / 2 : i;
	i += ft_strcnt(l, ';');
	//ALLOCATIONS DU TABLEAU COM CONTENANT LES COMMANDES ET OPERATEURS
	if (!(com = ft_memalloc((sizeof(char **) * i) + 2)))
		return (NULL);
	//REMISE A ZERO DE I POUR REUTILISATION
	i = 0;
	//Revoir le systeme de split pour prendre plus de trucs a virer que \t
	//BOUCLE PRINCIPALE
	while (l[i])
	{
		//ICI CHECK DES ERREURS GENRE &&& OU ||| OU ;; SI OPERATEUR DETECTE
		if ((l[i] == '&' && l[i + 1] == '&') ||
		(l[i] == '|' && l[i + 1] == '|') || l[i] == ';')
		{
			if (l[i] == ';')
			{
				l[i + 1] == ';' ? t->err = 1 : i;
				//NE PAS REDUIRE GENRE OU RISQUE DE CRASH PAR DEPASSEMENT ! (genre juste ecrire ;  ferais crash)
			}
			else if (com[j + 2])
			{
				if (com[j + 2] == com[j])
					t->err = 1;
			}
			if (t->err)
			{
				ft_printf("42sh: parse error near '%c%c'", com[j], com[j]);
				break ;
			}
			//AJOUT DANS LE TABLEAU DE L OPERATEUR
			j++;
			l[i] == '&' ? com[j] = ft_strdup("&&") : l;
			l[i] == '|' ? com[j] = ft_strdup("||") : l;
			l[i] == ';' ? com[j] = ft_strdup(";") : l;
			(l[i] == '&' || l[i] == '|') ? i = i + 1 : i;
			j++;
		}
		else
		{
			//RENTRE SI PAS D OPERATEUR DETECTE

			// SI LA LIGNE DU TABLEAU EST DEJA ALLOUEE
			// ATTENTION !!! : ICI SERRAIS LE SOUCI D ALLOCATION !
			// UN CAFE A CELUI QUI RESOUT LE SOUCI !
			if (com[j] && l[i] != '\t')
			{
				if (!(c = ft_strdup(com[j])))
					return (NULL);
				ft_strdel(&com[j]);
				if (!(com[j] = ft_strnew(sizeof(char) * ft_strlen(c) + 2)))
					return (NULL);
				com[j] = ft_strcpy(com[j], c);
				com[j][ft_strlen(c) + 1] = l[i];
				ft_strdel(&c);
			}
			else if (!com[j] && l[i] != '\t')
			{
				// SI LA LIGNE DU TABLEAU EST PAS ALLOUEE
				if (!(com[j] = ft_strnew(sizeof(char) * 2)))
					return (NULL);
				com[j][0] = l[i];
			}
		}
		i++;
	}
	return (com);
}

void		ft_preprocess(char **tmp, t_prstruct *proc, char **path, \
						t_hered *heredoc)
{
	t_operators	t;

	//CETTE PARTIE DU CODE N A PAS ETE NI OPTI NI MODIFIEE GRANDEMENT AVANT AJOUT DE LA FONCTION DESSUS!

	//MISE A NULL DE LA STRUCTURE
	t.l = NULL;
	t.com = NULL;
	t.j = 0;
	t.op = 0;
	t.com = NULL;
	t.err = 0;
	//APPEL DE LA FONCTION AU DESSUS
	t.com = ft_preprocesssplit(*tmp, &t);
	ft_strdel(tmp);
	//TANT QUE PAS NULL ET PAS ERREUR
	while (t.com != NULL && t.com[t.j] != NULL && !t.err)
	{
		//DETECTE SI OPERATEUR DETECTE
		!ft_strcmp(t.com[t.j], "&&") ? t.op = 1 : t.j;
		!ft_strcmp(t.com[t.j], "||") ? t.op = 2 : t.j;
		!ft_strcmp(t.com[t.j], ";") ? t.op = 3 : t.j;
		//A faite : Rajout des autres trucs a elimine pendant le split
		//RAJOUT DANS LE TABLEAU DES STRINGS ?
		if (t.com[t.j][0] != '\t' && t.com[t.j][0] != '\n' &&
		ft_strcmp(t.com[t.j], "&&") && ft_strcmp(t.com[t.j], "||") &&
		ft_strcmp(t.com[t.j], ";"))
		{
			//SI PAS OPERATEUR EST DETECTE CA RENTRE
			t.l ? t.l = ft_strjoind(t.l, " ", 1, 0) : t.l;
			t.l ? t.l = ft_strjoind(t.l, t.com[t.j], 1, 0) : t.l;
			!t.l ? t.l = ft_strdup(t.com[t.j]) : t.l;
			if (!t.l)
				break ;
			//VERIFIE SI OPERATEUR APRES
			if (t.com[t.j + 1])
			{
				if (!ft_strcmp(t.com[t.j + 1], "&&") ||
				!ft_strcmp(t.com[t.j + 1], "||") ||
				!ft_strcmp(t.com[t.j + 1], ";"))
				{
					//SI UN OPERATEUR EST DETECTE
					if (t.op == 3 || (t.op == 1 && proc->stat_lock == 0) ||
					(t.op == 2 && proc->stat_lock != 0) || t.op == 0)
						ft_process(t.l, proc, path, heredoc);
					t.op = 0;
					ft_strdel(&t.l);
				}
			}
			// ft_putnbr(proc->stat_lock);
		}
		//LANCE LA DERNIERE COMMANDE ENTREE
		!t.com[t.j + 1] ? ft_process(t.l, proc, path, heredoc) : t;
		t.j++;
	}
	//FREE
	t.l ? ft_strdel(&t.l) : t;
	ft_free_tab(&t.com);
}
