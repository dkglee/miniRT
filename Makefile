# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deulee <deulee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 13:51:29 by deulee            #+#    #+#              #
#    Updated: 2021/05/16 14:34:52 by deulee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

HEADER = includes

SRCDIR = srcs/

BMPDIR = bmp/

ERRDIR = error/

MATDIR = math/

PSEDIR = parse/

RAYDIR = ray/

RENDIR = render/

TRADIR = trace/

VALDIR = validation/

LIB = lib/

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -I $(HEADER) -D NUM_THREADS=$(NUM_THREADS) -g -fsanitize=address

FLAGS = -L $(LIB)libft -lft

MACOS_MAC = -D MACOS

LINUX_MAC = -D LINUX

MACOS_FLAGS = -L $(LIB)minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

LINUX_FLAGS = -L $(LIB)minilibx-linux -lmlx -lm -lX11 -lXext -lpthread

OSNAME := $(shell uname)

ifeq ($(OSNAME), Linux)
	NUM_THREADS = $(shell nproc --all)
	CFLAGS += $(LINUX_MAC)
	FLAGS += $(LINUX_FLAGS)
endif
ifeq ($(OSNAME), Darwin)
	NUM_THREADS = $(shell sysctl -n hw.ncpu)
	CFLAGS += $(MACOS_MAC)
	FLAGS += $(MACOS_FLAGS)
endif

FILES = minirt.c \
		$(BMPDIR)bmp.c \
		$(BMPDIR)bmp_utils.c \
		$(ERRDIR)error.c \
		$(MATDIR)color.c \
		$(MATDIR)rotation.c \
		$(MATDIR)vec_utils.c \
		$(MATDIR)vec.c \
		$(PSEDIR)parse.c \
		$(PSEDIR)parse_utils.c \
		$(PSEDIR)parse_utils_more.c \
		$(PSEDIR)parse_utils_more_2.c \
		$(PSEDIR)parse_bonus.c \
		$(PSEDIR)parse_environment.c \
		$(PSEDIR)parse_objects.c \
		$(PSEDIR)parse_vector_utils.c \
		$(PSEDIR)parse_color.c \
		$(RAYDIR)ray.c \
		$(RENDIR)multithread.c \
		$(RENDIR)render.c \
		$(RENDIR)render_utils.c \
		$(RENDIR)simple_sample.c \
		$(RENDIR)ssaa.c \
		$(TRADIR)bonus_intersection.c \
		$(TRADIR)cylinder_intersection.c \
		$(TRADIR)light.c \
		$(TRADIR)light_utils.c \
		$(TRADIR)plane_intersection.c \
		$(TRADIR)sphere_intersection.c \
		$(TRADIR)square_intersection.c \
		$(TRADIR)texture.c \
		$(TRADIR)trace.c \
		$(TRADIR)triangle_intersection.c \
		$(VALDIR)validation.c \
		$(VALDIR)validation_object.c \
		$(VALDIR)validation_world.c \
		$(VALDIR)validation_bonus.c \
		$(VALDIR)validation_extraction.c \
		$(VALDIR)validation_extraction_object.c \
		$(VALDIR)validation_extraction_bonus.c \
		$(VALDIR)validation_utils.c

SRCS = $(addprefix $(SRCDIR), $(FILES))

OBJS = ${SRCS:.c=.o}

${NAME}:	${OBJS}
			make -C $(LIB)libft
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}

all:		${NAME}

clean:
			make clean -C $(LIB)libft
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(LIB)libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
