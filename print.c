#include <header.h>
#include <push_swap.h>

void    ft_print_b(int num)
{
    int     i;
    char    *str;

    printf("   %d", num);
    str = ft_itoa(num);
    i = 20 + ft_strlen(str);
    free(str);
    while (i++ < 30)
        printf(" ");
}

void    ft_print_nums(t_ab *ab)
{
    int     i;
    t_stack *a;
    t_stack *b;
    char    *str;

    a = ab->a;
    b = ab->b;
    while (a || b)
    {
        printf("│");
        if (a)
        {
            printf("   %d", a->num);
            str = ft_itoa(a->num);
            i = 6 +  ft_strlen(str);
            free(str);
            a = a->next;
        }
        else
            i = 3;
        while (i++ < 16)
            printf(" ");
        printf("│");
        if (b)
        {
            ft_print_b(b->num);
            b = b->next;
        }
        else
            while (i-- > 4)
                printf(" ");
        printf("│");
        printf("\n");
    }
}

void    ft_print_col(t_ab *ab, int st, int col)
{
    int     c;

    c = col;
    ft_print_nums(ab);
    printf("│   ───────   │   ───────   │\n");
    printf("│   stack a   │");
    printf("   stack b   │");
    printf("\n");
}

void    ft_print(t_ab * ab, int st, int col)
{
    int c;

    c = col;
    printf("┌");
    while (--c > 2)
    {
        if (c == 16)
            printf("┬");
        else
            printf("─");
    }
    printf("┐\n");
    ft_print_col(ab, st, col);
    c = col;
    printf("└");
    while (--c > 2)
    {
        if (c == 16)
            printf("┴");
        else
            printf("─");
    }
    printf("┘\n");
}

void    ft_visual(t_ab *ab)
{
    int len;

//    set_display_atrib(B_GREEN);
    set_display_atrib(F_GREEN);
    len = ab->a_len > ab->b_len ? ab->a_len : ab->b_len;
    clrscr();
    home();
    ft_print(ab, ab->a_len, 30);
    usleep(100000);
    //ft_print_nums(10);
}

