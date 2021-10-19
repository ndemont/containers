CLEAR		= \033[2K\c
CC			= clang++
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRCS_DIR	= sources
INC_DIR		= includes

VCT_DIR		= ${SRCS_DIR}/vector
STCK_DIR	= ${SRCS_DIR}/stack

all: 		vector map stack

v_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/size.cpp

s_empty:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/empty.cpp
s_pop:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/pop.cpp
s_push:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/push.cpp
s_rel_op:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/relation_operators.cpp
s_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/size.cpp
s_top:
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/top.cpp
	

vector:	v_size

map:

stack: s_empty s_pop s_push s_rel_op s_size s_top

clean:
			${RM} ${OBJS_DIR}

fclean:
			${RM} ${OBJS_DIR}
			${RM} ${NAME}

re:			fclean all

.SUFFIXES:	.cpp .o .hpp
.PHONY:		all clean fclean re