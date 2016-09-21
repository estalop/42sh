/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:27:56 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/11 17:42:33 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SH_H
# define SH_H
#ifdef unix
static char term_buffer[2048];
#else
#define term_buffer 0
#endif
# define KEY_CTRL_D				4
# define KEY_RIGHT				4414235
# include "stdlib.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <termcap.h>
# include "libft/includes/libft.h"
# include <sys/ioctl.h>


int			ft_tc(void);
int			ft_get_user_input(void);
int			ft_deal_input(char *buffer, t_dlist *list, t_dlist *histo,
			t_dlist *to_paste);
int			ft_deal_input2(char *buffer, t_dlist *list, t_dlist *histo,
			t_dlist *to_paste);

int			ft_detect_right(char *buffer);
int			ft_detect_down(char *buffer);
int			ft_detect_left(char *buffer);
int			ft_detect_up(char *buffer);
int			ft_detect_ctrl_d(char *buffer);
int			ft_detect_end(char *buffer);
int			ft_detect_home(char *buffer);
int			ft_detect_shift_home(char *buffer);
int			ft_detect_shift_end(char *buffer);
int			ft_detect_second_delete(char *buffer);
int			ft_detect_paste(char *buffer);
int			ft_detect_copy(char *buffer);
int			ft_detect_cut(char *buffer);
int			ft_detect_tab(char *buffer);
int			ft_detect_page_up(char *buffer);
int			ft_detect_page_down(char *buffer);
int			ft_detect_dot_coma(char *buffer);

t_dlist		*ft_get_info_from_list(t_dlist *list, t_dlist *histo);

int			ft_check_correct_entry(t_dlist *list);
int			ft_check_dquo(char *str);

int			ft_left(t_dlist *list);
int			ft_right(t_dlist *list);
int			ft_up(t_dlist *list);
int			ft_down(t_dlist *list);
int			ft_move_end(t_dlist *list);
int			ft_move_home(t_dlist *list);
int			ft_move_shift_home(t_dlist *list);
int			ft_move_shift_end(t_dlist *list);
int			ft_move_page_up(t_dlist *list);
int			ft_move_page_down(t_dlist *list);

int			ft_second_delete(t_dlist *list);
int			ft_move_begin(void);

int			ft_copy(t_dlist *list, t_dlist *to_paste);
int			ft_cut(t_dlist *list, t_dlist *to_paste, int index, char *buffer);
int			ft_paste(t_dlist *list, t_dlist *to_paste, int index, char *str);

int			ft_historic_after(t_dlist *list, t_dlist *histo);
int			ft_historic_previous(t_dlist *list, t_dlist *histo);
void		ft_move_and_clean(t_dlist *list);

int			ft_check_pipe(char *arg);
char		*ft_new_arg(char *arg);

int			ft_delete_on_shell(t_dlist *list);
int			ft_clear_n_char(int n);
int			ft_clear_line(void);

int			ft_finish_command(t_dlist *list, t_dlist *histo);
char		**ft_separate_dot_coma(char **tab3, char *line, int total);
int			ft_add_element(t_dlist *list, char *buffer);
void		ft_move_down(t_dlist *list, int index2);

int			ft_process(char *line, t_dlist *env);

t_dlist		*ft_choose(char *arg, t_dlist *list);
void		ft_show_prompt(void);
char		*ft_last_dir(char *path);
int			ft_run_cd(char *arg, t_dlist *line, char *tmp, char *tmp2);
char		*ft_get_path(char *arg);
char		*ft_home(t_dlist *list);
char		*ft_get_ele(t_dlist *liste, int pos);
int			ft_error_home2(char *tmp2);
char		**ft_error_home(void);
t_dlist		*ft_exchange_element2(t_dlist *list, char *oldpwd);
t_dlist		*ft_exchange_element(t_dlist *list, char *test1, char *test4);
void		ft_error(char *arg, int version);
char		*ft_prev(t_dlist *list);
void		ft_run_echo(char *arg, t_dlist *list);
t_dlist		*ft_run_unsetenv(char *arg, t_dlist *list);
void		ft_run_setenv(char *arg, t_dlist *list);
int			ft_check_arg(char *arg, t_dlist *list, int index, char *boucle);
char		*ft_boucle(char *arg);
char		**ft_get_options1(char *arg, char **options);
char		**ft_get_options2(char *arg, char **options, size_t *index, int *x);
char		*ft_get_options3(char *home, char *arg, size_t *index2, char *opto);
char		*ft_get_options4(size_t *index, int compteur, char *opt, char *arg);
int			ft_get_size(char *str);
int			ft_get_total_path(t_dlist *list);
char		*ft_get_auto_path(int x, t_dlist *list, int drop, int index);
char		*ft_give_path(char *arg);
int			ft_run_exe(char *path, char **options, t_dlist *list);
int			ft_check_file(char *path);
int			ft_check_arg3(char *boucle, t_dlist *list, char **options);
char		*ft_generate_path(char *arg, t_dlist *list);
void		ft_get_sigint(int signal);



#endif
