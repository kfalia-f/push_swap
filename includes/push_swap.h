/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:21:28 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/03 23:47:15 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFF_SIZE 1000

# include <stdio.h>
# include <unistd.h>
# include <libft.h>

typedef struct		s_stack
{
	struct s_stack	*next;
	int				num;
}					t_stack;

typedef struct		s_ab
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				a_len;
	int				b_len;
}					t_ab;

//general
int					ft_test();
int					ft_valid(int ac, char **av);
int					ft_valid_nums(t_ab *ab);
int					ft_int_cast(int ac, char **av, t_ab *ab);
void				ft_new_ab(t_ab *head);
t_stack				*ft_new_node();
void				ft_free_ab(t_ab *ab);
int					ft_lstlen(t_stack *head);
void				ft_swap(char bf[BUFF_SIZE], t_ab *ab);
void				ft_swap_a(t_ab *ab);
void				ft_swap_b(t_ab *ab);
void				ft_push(char bf[BUFF_SIZE], t_ab *ab);
void				ft_push_a(t_ab *ab);
void				ft_push_b(t_ab *ab);
void				ft_rotate(char bf[BUFF_SIZE], t_ab *ab);
void				ft_rotate_a(t_ab *ab);
void				ft_rotate_b(t_ab *ab);
void				ft_rotate_ab(t_ab *ab);
void				ft_reverse_rotate(char bf[BUFF_SIZE], t_ab *ab);
void				ft_rev_rotate_a(t_ab *ab);
void				ft_rev_rotate_b(t_ab *ab);
void				ft_rev_rotate_ab(t_ab *ab);

//checker
void				ft_read_commands(t_ab *ab);
int					ft_check_stack(t_ab *ab, int flag);
int					ft_check_stack_a(t_ab *ab);

//push_swap
int					ft_check_alg(t_ab *ab);
void				ft_alg(t_ab *ab);



void				ft_write(t_ab *ab);
#endif
