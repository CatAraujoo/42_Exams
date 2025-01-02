/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catarina <catarina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:42:23 by catarina          #+#    #+#             */
/*   Updated: 2025/01/02 13:43:22 by catarina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list t_list;

struct s_list
{
	int	data;
	t_list	*next;
};