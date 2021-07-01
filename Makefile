#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:37:03 by ciglesia          #+#    #+#              #
#    Updated: 2021/07/01 14:46:45 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libalgorithm.a

INC			=	./include/

ROOTINC		=	../include/

INCLUDE		=	-I $(INC) -I $(ROOTINC)

#***************** DIR ********************#

DIRSRC		=	./src/
DIRHASH		=	$(DIRSRC)/hash/
DIRTRIE		=	$(DIRSRC)/mapping/trie/

#***************** SRC ********************#

HASH		=	djb2.c k24.c
TRIE		=	delete_trie.c free_trie.c get_trie.c insert_trie.c new_trie.c put_trie.c

SRCS		=	$(HASH) $(TRIE)

#***************** DEPS *******************#

DIROBJ		=	./depo/

OAUX		=	$(SRCS:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.c=.d)
OBJS		=	$(OAUX:.c=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g -fPIC
	endif
else
CFLAGS		=	-Wall -Wextra -Werror -fPIC
endif

CC			=	/usr/bin/gcc
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e
BOLD		=	"\e[1m"
BLINK		=	 "\e[5m"
RED			=	 "\e[38;2;255;0;0m"
GREEN		=	 "\e[92m"
BLUE		=	 "\e[34m"
YELLOW		=	 "\e[33m"
E0M			=	 "\e[0m"

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRHASH)/%.c
				@printf $(GREEN)"Generating libalgorithm objects...  %-33.33s\r" $@
				@$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRTRIE)/%.c
				@printf $(GREEN)"Generating libalgorithm objects...  %-33.33s\r" $@
				@$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		$(OBJS)
				@$(ECHO)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				@$(ECHO) $(BOLD)$(GREEN)'> libalgorithm library compiled'$(E0M)

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(DEPS))
				@$(ECHO) $(BOLD)$(RED)'> libalgorithm directory cleaned'$(E0M)

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@$(ECHO) $(BOLD)$(RED)'> libalgorithm.a         removed'$(E0M)

re		:		fclean all

.PHONY	:		all clean fclean re

-include $(DEPS)
