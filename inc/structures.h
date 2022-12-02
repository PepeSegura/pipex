/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:03:14 by psegura-          #+#    #+#             */
/*   Updated: 2022/12/02 14:12:40 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_argument {
	char	***matrix;
	int		cmd_count;
}	t_argument;

typedef struct s_fd {
	int	input;
	int	output;
}	t_fd;

#endif
