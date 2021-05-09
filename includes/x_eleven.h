/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_eleven.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:14:22 by deulee            #+#    #+#             */
/*   Updated: 2021/05/09 19:04:00 by deulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_ELEVEN_H
# define X_ELEVEN_H

# define KEYPRESSMASK 1
# define STRUCTURENOTIFYMASK 131072

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24

# ifdef LINUX
#  define A_KEY 97
#  define B_KEY 98
#  define C_KEY 99
#  define D_KEY 100
#  define E_KEY 101
#  define F_KEY 102
#  define G_KEY 103
#  define H_KEY 104
#  define I_KEY 105
#  define J_KEY 106
#  define K_KEY 107
#  define L_KEY 108
#  define M_KEY 109
#  define N_KEY 110
#  define O_KEY 111
#  define P_KEY 112
#  define Q_KEY 113
#  define R_KEY 114
#  define S_KEY 115
#  define T_KEY 116
#  define U_KEY 117
#  define V_KEY 118
#  define W_KEY 119
#  define X_KEY 120
#  define Y_KEY 121
#  define Z_KEY 122

#  define K_UP 65362
#  define K_DOWN 65364
#  define K_RIGHT 65363
#  define K_LEFT 65361

#  define K_SP 32
#  define K_ESC 65307

#  define M_CLK_L 1
#  define M_CLK_R 3
#  define M_CLK_M 2
#  define M_SCR_U 4
#  define M_SCR_D 5

# else

#  define A_KEY 0
#  define B_KEY 11
#  define C_KEY 8
#  define D_KEY 2
#  define E_KEY 14
#  define F_KEY 3
#  define G_KEY 5
#  define H_KEY 4
#  define I_KEY 34
#  define J_KEY 38
#  define K_KEY 40
#  define L_KEY 37
#  define M_KEY 46
#  define N_KEY 45
#  define O_KEY 31
#  define P_KEY 35
#  define Q_KEY 12
#  define R_KEY 15
#  define S_KEY 1
#  define T_KEY 17
#  define U_KEY 32
#  define V_KEY 9
#  define W_KEY 13
#  define X_KEY 7
#  define Y_KEY 16
#  define Z_KEY 6

#  define K_UP 126
#  define K_DOWN 125
#  define K_RIGHT 124
#  define K_LEFT 123

#  define K_SP 49
#  define K_ESC 53

#  define M_CLK_L 1
#  define M_CLK_R 3
#  define M_CLK_M 2
#  define M_SCR_U 4
#  define M_SCR_D 5

# endif
#endif
