/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 08:31:35 by jbobin            #+#    #+#             */
/*   Updated: 2016/10/06 20:07:30 by tbayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include "libft/includes/libft.h"
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>
# include <crt_externs.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include "autocompletion.h"

typedef struct	s_structenv
{
	char		**argv;
	char		**tmpenv;
	char		*tmp;
	char		*tmp2;
	int			k;
}				t_structenv;

typedef struct	s_structpwd
{
	char		*tmpwd;
	char		*tmpold;
	char		*tmp;
	int			pwd;
	int			old;
	int			home;
	int			i;
}				t_structpwd;

typedef struct	s_idlist
{
	pid_t			id;
	int				no;
	struct s_idlist	*next;
	struct s_idlist	*prev;
}				t_idlist;

typedef struct		s_node
{
	char			*data;
	int				wrote;
	struct s_node	*p_next;
	struct s_node	*p_prev;
}					t_node;

typedef struct		s_dlist
{
	struct s_node	*p_tail;
	int				index2;
	int				pos;
	int				length;
	struct s_node	*p_head;
}					t_dlist;

typedef struct	s_plist
{
	int				no;
	int				pipe[2];
	struct s_plist	*next;
}				t_plist;

typedef struct	s_hered
{
	char			*str;
	struct s_hered	*next;
}				t_hered;

typedef struct	s_prstruct
{
	char		*bin;
	int			stat_lock;
	char		*hist[500];
	t_dlist		*histo2;
	pid_t		father;
	pid_t		id;
	int			i;
	int			s;
	int			npipe;
	t_idlist	*list;
	t_plist		*pipe;
	t_hered		*heredoc;
	int			herepipe;
	char		**env[3];
	t_exec		*exec;
}				t_prstruct;

typedef struct	s_termcaps
{
	t_exec		**bin;
	char		*str;
	char		*stop;
	char		*cmd;
	t_hered		*heredoc;
	t_dlist		*histo2;
	char		buf[2048];
	int			height;
	int			whidth;
	int			auto_wrap;
	int			auto_scroll;
	int			x;
	int			y;
	char		pc;
	char		*im;
	int			mi;
	char		*bl;
	char		*sf;
	char		*sr;
	char		*cr;
	char		*cv;
	char		*dc;
	char		*cl;
	t_exec		*tree;
	char		*hist[500];
	int			prompt;
	char		*prom;
	int			i;
	int			neg;
	int			oldlen;
}				t_termcaps;

void			ft_error_path(int i, char *path);
int				ft_exit(char *buf, int i, t_prstruct *proc);
void			ft_free_exit(char ***argv);
int				ft_cd(char *buf, char **env, int j, char **argv);
int				ft_opt_home(char **argv, char **env, int i);
void			ft_error_cd(char *buf);
int				ft_env(char *buf, char ***env, int i, t_prstruct *proc);
void			ft_print_env(char **env);
char			**ft_get_path(char **environ);
void			ft_exec_env(char **env, char *buf, char *argv, t_prstruct *proc);
void			ft_execute(char *buf, char **env, char *bin, t_prstruct *proc);
int				ft_setenv(char *buf, char ***adenv, char **env, char ***nenv);
char			**ft_subsetenv(t_structenv t, char **env);
int				ft_unsetenv(char *buf, char ***adenv, char **env);
char			**ft_subunsetenv(t_structenv t, char ***env);
char			*ft_home(char **env, char argv);
int				ft_pwd_up(char **env);
char			*ft_cd_buf(char *argv);
void			ft_sync_env(char **env[3], int pwd, int pwd1, int old);
char			**ft_sub_env(char ***env, char **argv, int k, int i);
char			**ft_opt_env(char **argv, char **env);
void			ft_split_env(char ***env, char **argv, int *i, char ***tmp);
char			**ft_create_environ(int i);
t_structpwd		ft_init_struct(char **env);
void			ft_set_home_in_argv(char **argv, char **env);
char			**ft_new_env(t_structenv t, char **env);
void			ft_main_free(char ***env, t_termcaps *cap, char ***path, \
							char ***com);
void			ft_signal_stop(int sig);
void			ft_init_termcap(t_termcaps *cap);
void			ft_reset_term(int signum);
int				ft_read_termcap(t_termcaps *cap);
int				ft_output(int c);
void			ft_reset(t_termcaps *cap, char *str);
void			ft_put_cursor(t_termcaps *cap, char *str);
t_termcaps		*ft_struct_innit(int mode);
char			*ft_arrow_up(t_termcaps *cap, char *tmp);
char			*ft_arrow_down(t_termcaps *cap, char *tmp);
void			ft_signal_fork(int sig);
char			*ft_del_char(t_termcaps *cap, char *str, int i);
char			*ft_multiple_char(t_termcaps *cap, char *str, char buf[4]);
char			*ft_print_char(t_termcaps *cap, char *str, char buf);
void			ft_shift_arrow(t_termcaps *cap, int strlen, char buf[4], \
								char *tmp);
void			ft_thome(t_termcaps *cap, char *str);
void			ft_end(t_termcaps *cap, char *str, int strlen);
void			ft_signal_size(int sig);
int				ft_quote_not_finished(char *str, int i, t_termcaps *cap);
char			*ft_return(char *str);
char			*ft_prompt(int i);
int				ft_calculate_height(char *str, int i, t_termcaps *cap);
int				ft_start_of_str(char *str, t_termcaps *cap);
int				ft_calculate_whidth(char *str, int i, t_termcaps *cap);
void			ft_arrow_side(char *tmp, char buf[4], t_termcaps *cap, \
							int strlen);
void			ft_out(t_termcaps *cap, char buf[4], char *tmp);
void			ft_set_prompt(t_termcaps *cap);
void			ft_set_term(void);
void			ft_sig_stop_ex(int sig);
int				ft_count_pipe(const char *buf);
pid_t			ft_fork(t_idlist **list);
void			ft_free_list(t_idlist **list);
void			ft_kill_process(t_idlist **list, pid_t id);
void			ft_son(t_prstruct *proc, char **buf, char **env[3]);
t_plist			*ft_create_pipe(int num);
void			ft_newputstr(char const *str, t_termcaps *cap);
int				*ft_calculate_length(char *str, int i, t_termcaps *cap, \
									int xy[4]);
void			ft_redirect(t_prstruct *proc, char **buf);
int				ft_findr(t_prstruct *proc, char **buf, int i);
void			ft_close_pipe(t_plist *tmp, t_prstruct *proc);
int				ft_exe_builtin(int i, char *buf, t_prstruct *proc);
int				ft_heredoc(char *str, int i, int j, t_termcaps *cap);
int				ft_heredoc_file(char *str, t_termcaps *cap);
char			*ft_check_bin(char *buf, char **env, char **path, int i);

t_dlist			*dlist_new(t_dlist *p_new);
void			ft_get_history_from_file(t_dlist *histo, int fd, int index,
				int index2);
int				ft_display_list(t_dlist *p_list, int i);
void			ft_init_histo(t_prstruct *proc, t_termcaps *cap);
t_dlist			*ft_add_data(t_dlist *p_list, char *data, int wrote);
t_dlist			*nik_the_norm2(t_dlist *p_list, t_node *p_new, int i);
t_dlist			*nik_the_norm3(t_dlist *p_list, t_node *p_new, int i);
int				ft_run_history(char *arg, char *home, t_prstruct *proc, int exit);
t_dlist			*ft_del_ele_list(t_dlist *list, size_t p, t_node *p_temp,
				size_t i);
int				ft_display_list4(t_dlist *p_list, int limit);
int				ft_write_history_file(t_dlist *histo, int index, int fd, int p);
int				ft_write_history_file2(t_dlist *host, int fd, int p, int exit);
void			ft_get_check_file(t_dlist *histo, int fd, int index, int indx2);
char			*ft_get_element_from_list(t_dlist *liste, int pos);
t_dlist			*ins_avant(t_dlist *list, char *data, t_node *courant, int pos);
int				ft_display_list3(t_dlist *p_list);
int				ft_check_options_history(char *arg, char c, int index);
char			*ft_get_home(char **env);
void			ft_delete_list(t_dlist *p_list);
int				ft_check_wrote_from_list(t_dlist *list, int pos);
int				ft_run_history2(char *arg, t_dlist *histo, int index);
int				ft_run_history3(char *arg, t_dlist *histo, int index);
int				ft_run_history4(char *home, t_dlist *histo);
int				ft_run_history5(char *arg, char *home, t_dlist *histo, int
				index);
char			*ft_check_excla(char *arg, t_prstruct *proc);
char			*ft_replace_excla(char *arg, t_prstruct *proc, int id, int id2);
int				ft_check_tmp(char *arg);

#endif
