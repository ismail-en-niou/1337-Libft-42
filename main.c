#include <stdio.h>
#include <stdlib.h>
#include "libft.h"  // For ft_atoi and ft_lstnew, ft_lstadd_front

void print_list(t_list *test)
{
    while (test)
    {
        printf("%s\n", (char *)test->content);
        test = test->next;
    }
}

void apply_negate(void *content)
{
    int nb = ft_atoi(content) * -1;
    content = ft_itoa(nb);
}



int main()
{
    int count = 5;
    int nb = 1; 
    t_list *test = NULL;

    while (nb <= count)
    {
        t_list *new = ft_lstnew(ft_itoa(nb));
        ft_lstadd_back(&test, new);
        nb++;
    }

    printf("Original list:\n");
    print_list(test);
    ft_lstiter(test, apply_negate);

    printf("Negated list:\n");
    print_list(test);

    while (test)
    {
        t_list *tmp = test;
        free(test->content);
        test = test->next;
        free(tmp);
    }

    return 0;
}
