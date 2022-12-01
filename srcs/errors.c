/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:33:33 by psegura-          #+#    #+#             */
/*   Updated: 2022/11/28 04:47:47 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_error(int error_code, char *error_message)
{
	ft_printf("Error\n\tError code: %d\n\t%s", error_code, error_message);
	exit(error_code);
}
