#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:37:03 by ciglesia          #+#    #+#              #
#    Updated: 2022/11/14 14:14:57 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libalgorithm.a

INC			=	./include/

ROOTINC		=	../include/

INCLUDE		=	-I $(INC) -I $(ROOTINC)

#***************** DIR ********************#

DIRSRC		=	./src/
DIRSRT		=	$(DIRSRC)/sorting/
DIRHASH		=	$(DIRSRC)/hash/
DIRMAP		=	$(DIRSRC)/mapping/
DIRTRIE		=	$(DIRMAP)/trie/

#***************** SRC ********************#

SORT		=	strquick.c binsert.c binsearch.c
HASH		=	djb2.c k24.c
MAPPING		=	map.c
TRIE		=	delete_trie.c free_trie.c get_trie.c insert_trie.c new_trie.c put_trie.c

SRCS		=	$(HASH) $(MAPPING) $(TRIE) $(SORT)

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

CC			=	/usr/bin/clang
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

%.o		:		../$(DIRSRT)/%.c
				@printf $(GREEN)"Generating libalgorithm objects...  %-33.33s\r" $@
				@$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRHASH)/%.c
				@printf $(GREEN)"Generating libalgorithm objects...  %-33.33s\r" $@
				@$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRMAP)/%.c
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
