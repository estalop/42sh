/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:38:32 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/07 17:28:14 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 9

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
# include <errno.h>
# include <grp.h>

typedef struct		s_node
{
	char			*data;
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

char				*ft_itoa(int n);
void				ft_putnbr(int nbr);
char				*ft_strjoin(char const *str1, char const *str2);
char				*ft_strjoin_special(char const *str1, char const *str2);
size_t				ft_strlen(const char *str);
size_t				l(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
int					ft_strcmp(const char *s1, const char *s2);
int					s(const char *s1);
int					e(const char *s1);
void				ft_putnbr_fd (int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strdup(const char *s1);
int					get_next_line(int const fd, char **line, int check);
void				*ft_memmove(void *dest, const void *source, size_t len);
char				*ft_strchr(const char *haystack, int needle);
char				*ft_delete_tab(char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_bzero(void *s1, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dst, const char *src);
t_dlist				*dlist_new(t_dlist *p_new);
char				**ft_tab_from_list(t_dlist *list);
char				*ft_strupcase(char *str);
char				*ft_strcut(char *str, int index);
char				ft_strcmp2(char *s1, char *s2);
char				**ft_set_zero(int index, char **options);
int					ft_search_list(t_dlist *list, char *data);
int					ft_list_size(t_node *head);
t_dlist				*ins_avant(t_dlist *liste, char *data, t_node *courant,
					int pos);
void				ft_free_tab(char **tab2);
void				ft_display_tab(char **arg);
int					ft_display_list(t_dlist *p_list);
char				*ft_delete_tab(char *arg);
void				ft_delete_list(t_dlist **p_list);
void				ft_delete_list2(t_dlist **p_list);
t_dlist				*ft_del_ele_list(t_dlist *list, size_t p, t_node *p_temp,
					size_t i);
t_dlist				*ft_cpy_env(t_dlist *list);
t_dlist				*dlist_prepend(t_dlist *p_list, char *data);
t_dlist				*dlist_append(t_dlist *p_list, char *data);
t_dlist				*ft_add_data(t_dlist *p_list, char *data);
t_dlist				*ft_add_data2(t_dlist *p_list, char *data);
t_dlist				*ft_add_data3(t_dlist *p_list, char *data);
t_dlist				*nik_the_norm2(t_dlist *p_list, t_node *p_new, int i);
t_dlist				*nik_the_norm3(t_dlist *p_list, t_node *p_new, int i);
char				*ft_strcup(char *arg);
t_dlist				*ft_cpy_env(t_dlist *list);
t_dlist				*ft_cpy_env2(t_dlist *list);
t_dlist				*ft_cpy_env3(t_dlist *list);
char				*ft_delete_space(char *arg);
int					ft_putchar2(int c);
char				*ft_get_element_from_list(t_dlist *list, int pos);
char				*ft_get_str_from_list(t_dlist *list);
void				ft_display_list2(t_dlist *list);
int					ft_get_size_from_list(t_dlist *list);


#endif
