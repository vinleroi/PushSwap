/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:14:51 by aahadji           #+#    #+#             */
/*   Updated: 2025/06/07 18:53:52 by aahadji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_lstmax(t_list *tab);
int					ft_lstmin(t_list *tab);
size_t				ft_strlen(char *tab);
int					ft_atoi(const char *str);
int					ft_isdigit(char *c);
int					ft_check_dupe(t_list *a, int content);
char				*ft_itoa(int n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(char *tab);
int					is_quote(char c, int *in_quote);
void				*ft_calloc(size_t count, size_t size);
int					ft_abs(int n);
#endif
