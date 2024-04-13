/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:13:45 by msloot            #+#    #+#             */
/*   Updated: 2024/04/13 20:02:51 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_H
# define ANSI_H

# define Y_RESET	"\033[0m"

# define Y_BOLD		"\033[1m"
# define Y_ITALIC	"\033[3m"

# define Y_RED		"\033[31m"
# define Y_GRN		"\033[32m"
# define Y_YLW		"\033[33m"
# define Y_MAG		"\033[35m"

# define Y_B_RED	"\033[1;31m"
# define Y_BI_RED	"\033[1;3;31m"

# define Y_B_GRN	"\033[1;32m"
# define Y_BI_GRN	"\033[1;3;32m"

# define Y_B_YLW	"\033[1;33m"
# define Y_BI_YLW	"\033[1;3;33m"

# define Y_B_MAG	"\033[1;35m"
# define Y_BI_MAG	"\033[1;3;35m"

#endif
