/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:39:07 by mohel-kh          #+#    #+#             */
/*   Updated: 2025/06/10 13:38:22 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int g_es = 0;


int main(int ac,char **av,char **envp)
{

    (void)ac;
    (void)av;
    char *line;
    signal_setup();
    t_env *env;

    env = NULL;
    while (1)
    {
        test = NULL;
        t_node *head = NULL;
        line = readline("\033[32mDash@Ameed$ \033[0m");
        if (!line)
            return 0;
        add_history(line);
        if (!env)
            env = envp_dup(envp);
        ft_all(&head ,line ,NULL ,env);
        if(head)
           pipe_hundel(head, env);

        ft_malloc(0,'f');
        // t_node *test_test = head;
        // while (test_test)
        // {
        //     t_redi *lol = test_test->file;
        //     int i = 0;
        //     while (test_test->cmd[i])
        //     {
        //         printf("cmd[ %s ]   ", test_test->cmd[i]);
        //         i++;
        //     }
        //     printf("\n");
        //     while (lol)
        //     {
        //         printf("file_num[ %s ] --> ", lol->file_num);
        //         if (lol->type == 0)
        //             printf("type_file [ FILE_IN ]\n");
        //         else if (lol->type == 1)
        //             printf("type_file [ FILE_OUT \n]");
        //         else if (lol->type == 2)
        //             printf("type_file [ FILE_APPEND ]\n");
        //         else
        //             printf("type_file [ FILE_HEREDOC ]\n");
        //         lol = lol->next;
        //     }
        //     printf("-------------------------------------------\n");
        //     test_test = test_test->next;
        // }
    }
    clear_history();
}
