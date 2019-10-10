/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_alg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 23:28:23 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/10/07 20:27:32 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_check_a_sort(t_ab *ab)
{
	t_stack *tmp;

	tmp = ab->a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_sort_a(t_ab *ab)
{
	ft_max_min(ab);
    if (ab->a_len < 3)
        if (ab->a->num > ab->a->next->num)
            ft_rotate_a(ab, 1);
//	printf("max = %d, min = %d\n", ab->a_max, ab->a_min);
	while (!ft_check_a_sort(ab))
	{
		if (ab->a->num == ab->a_max)
			ft_rotate_a(ab, 1);
		if (ab->a->next->num == ab->a_max || ab->a->next->num == ab->a_min)
			ft_swap_a(ab, 1);
	}
}

void	ft_minmax_spot(t_ab *ab)
{
	if (ab->b->num > ab->a_max)
	{
		while (ab->a->num != ab->a_max)
			ft_rotate_a(ab, 1);
		ft_rotate_a(ab, 1);
	}
	else if (ab->b->num < ab->a_min)
	{
		while (ab->a->num != ab->a_min)
			ft_rotate_a(ab, 1);
	//	ft_rev_rotate_a(ab, 1);
	}
	ft_push_a(ab, 1);
}

int     ft_last_num(t_ab *ab)
{
	t_stack *tmp;
	int     i;

	i = 0;
	tmp = ab->a;
	while (i++ < ab->a_len - 1)
		tmp = tmp->next;
	return (tmp->num);
}

int     ft_my_spot(t_stack *a, int num, int fl)
{
    int     count;
    int     len;

    count = 0;
    //ft_write(ab);
    while (a->next)
    {
        count++;
        if (num > a->num && num < a->next->num)
            break ;
        a = a->next;
    }
    len = count;
    while (a->next)
    {
        a = a->next;
        len++;
    }
    //printf("len = %d, count = %d n = %d\n", len, count);
    printf("\nc = %d, num = %d, lne = %d\n\n", count, num, len);
    if (fl && count > len / 2)
        count = len - count;
    //printf("len = %d, count = %d, num = %d\n", len, count, num);
    return (count);
}

void    ft_find_spot(t_ab *ab, int flag)
{
	int     fst;
	int     last;
	//t_stack *tmp;

	flag = 0;
	flag += 1;
	//tmp = ab->a;
	while (1)
	{
		fst = ab->a->num;
		last = ft_last_num(ab);
		if (ab->b->num > ab->a_max || ab->b->num < ab->a_min)
		{
			ft_minmax_spot(ab);
			return ;
		}
		if (ab->b->num > last && ab->b->num < fst)
			break ;
        if (ft_my_spot(ab->a, ab->b->num, 0) < ab->a_len / 2)
            ft_rotate_a(ab, 1);
        else
            ft_rev_rotate_a(ab, 1);
	}
	ft_push_a(ab, 1);
}

void    ft_sort_b(t_ab *ab)
{
    t_stack *b;
    t_stack *a;

    //ft_write(ab);
    b = ab->b;
    a = ab->a;
    while (b->next)
        b = b->next;
    while (a->next)
        a = a->next;
    if (ab->b->num > ab->a_max && a->num == ab->a_max)
        ft_push_a(ab, 1);
    /*if (ab->b_len > 1)
        if (ab->b->num > ab->b->next->num)
            ft_swap_b(ab, 1);
    if (b->num < ab->b->num)
    {
        if (b->num > a->num)
            ft_rev_rotate_ab(ab, 1);
        else
            ft_rev_rotate_b(ab, 1);
    }
    if (ab->b_len <= 2)
    {
        if (ft_my_spot(ab->a, ab->b->num, 1) + 1 > ft_my_spot(ab->a, b->num, 1))
            ft_swap_b(ab, 1);
        return ;
    }
    ft_write(ab);
    printf("1 = %d, 2 = %d, 3 = %d\n", ft_my_spot(ab->a, ab->b->num, 1) + 1, ft_my_spot(ab->a, ab->b->next->num, 1), ft_my_spot(ab->a, b->num, 1));
    if (ft_my_spot(ab->a, ab->b->num, 1) + 1 < ft_my_spot(ab->a, ab->b->next->num, 1))
        if (ft_my_spot(ab->a, ab->b->num, 1) + 1 > ft_my_spot(ab->a, b->num, 1))
            ft_rev_rotate_b(ab, 1);
        else
            return ;
    else if (ft_my_spot(ab->a, ab->b->next->num, 1) > ft_my_spot(ab->a, b->num, 1))
        ft_rev_rotate_b(ab, 1);
    else
        ft_swap_b(ab, 1);
    */
   // ft_write(ab);
}

int     ft_b_spot(t_ab *ab, int num)
{
    t_stack *b;
    int     count;

    count = 0;
    b = ab->b;
    while (b->num != num)
    {
        count++;
        b = b->next;
    }
    return (count);
}

int     ft_a_spot(t_ab *ab, int num)
{
    t_stack *a;
    int     count;

    count = 0;
    a = ab->a;
    if (num < ab->a_min && a->num == ab->a_min)
        return (0);
    if (num < ab->a_min)
    {
        while (a->num != ab->a_min)
        {
            a = a->next;
            count++;
        }
        return (count);
    }
    if (num > ab->a_max)
    {
        while (a->num != ab->a_max)
        {
            a = a->next;
            count++;
        }
        return (count + 1);
    }
    while (a->next)
    {
        if (num > a->num && num < a->next->num)
            break ;
        count++;
        a = a->next;
    }
    return (count + 1);
}

void    ft_put_it(int arr[4], t_ab *ab)
{
    if (ft_b_spot(ab, arr[0]) + 1 == 2)
    {
        if (arr[2] > ab->a_len / 2)
        {
            arr[2] = ab->a_len - arr[2];
            while (arr[2]-- > 0)
                ft_rev_rotate_a(ab, 1);
        }
        else
            while (arr[2]-- > 0)
                ft_rotate_a(ab, 1);
        ft_swap_b(ab, 1);
    }
    else if (arr[2] > ab->a_len / 2 && arr[3] > ab->b_len / 2)
    {
        arr[2] = ab->a_len - arr[2];
        arr[3] = ab->b_len - arr[3];
        while (arr[2] > 0 && arr[3] > 0)
        {
            ft_rev_rotate_ab(ab, 1);
            arr[2]--;
            arr[3]--;
        }
        while (arr[3]-- > 0)
            ft_rev_rotate_b(ab, 1);
        while (arr[2]-- > 0)
            ft_rev_rotate_a(ab, 1);
    }
    else if (arr[2] > ab->a_len / 2)
    {
        arr[2] = ab->a_len - arr[2];
        while (arr[2]-- > 0)
            ft_rev_rotate_a(ab, 1);
        while (arr[3]-- > 0)
            ft_rotate_b(ab, 1);
    }
    else if (arr[3] > ab->b_len / 2)
    {
        arr[3] = ab->b_len - arr[3];
        while (arr[2]-- > 0)
            ft_rotate_a(ab, 1);
        while (arr[3]-- > 0)
            ft_rev_rotate_b(ab, 1);
    }
    else
    {
        if (arr[2] > 0 && arr[3] > 0)
            while (arr[2] > 0 && arr[3] > 0)
            {
                ft_rotate_ab(ab, 1);
                arr[2]--;
                arr[3]--;
            }
        while (arr[2]-- > 0)
            ft_rotate_a(ab, 1);
        while (arr[3]-- > 0)
            ft_rotate_b(ab, 1);
    }
    ft_push_a(ab, 1);
}

void    ft_find(t_ab *ab)
{
    t_stack *b;
    int     path_a;
    int     path_b;
    int     arr[4];
    int     sum;

    b = ab->b;
    arr[1] = 2147483647;
    while (b)
    {
        sum = 0;
        path_a = ft_a_spot(ab, b->num);
        path_b = ft_b_spot(ab, b->num);
        if (path_a > ab->a_len / 2)
            sum += ab->a_len - path_a;
        else
            sum += path_a;
        if (path_b > ab->b_len / 2)
            sum += ab->b_len - path_b;
        else
            sum += path_b;
        if (arr[1] > sum)
        {
            arr[1] = sum;
            arr[2] = path_a;
            arr[3] = path_b;
            arr[0] = b->num;
      //  printf("OLOLO    RESULT = %d, A = %d, B = %d, SUMM = %d\n", arr[0], arr[2], arr[3], arr[1]);
        }
//        ft_write(ab);
//        printf("p_a = %d, p_b = %d, num = %d\n", path_a, path_b, b->num);
        b = b->next;
    }
       // printf("RESULT = %d, A = %d, B = %d, SUMM = %d\n", arr[0], arr[2], arr[3], arr[1]);
    ft_put_it(arr, ab);
}

int     ft_find_min_a(t_ab *ab)
{
    t_stack *a;
    int     count;

    count = 0;
    a = ab->a;
    while (a->next)
    {
        if (a->num == ab->a_min)
            break ;
        count++;
        a = a->next;
    }
    return (count);
}

void	ft_alg(t_ab *ab)
{
	if (ft_check_alg(ab))
		return ;
	while (ab->a_len > 3)
		ft_push_b(ab, 1);
	ft_sort_a(ab);
//	ft_write(ab);
	while (ab->b_len > 0)
	{
		ft_max_min(ab);
        ft_find(ab);
//	    ft_write(ab);

    //  ft_sort_b(ab);
	//	ft_find_spot(ab, ab->b_len > ab->a_len);
	}
//	ft_write(ab);
//	return ;
	{
        if (ft_find_min_a(ab) > ab->a_len / 2)
	        while (ft_check_alg(ab) == 0)
                ft_rev_rotate_a(ab, 1);
        else
	        while (ft_check_alg(ab) == 0)
	            ft_rotate_a(ab, 1);
//				ft_write(ab);
	}
//	ft_write(ab);
}
