NAME		= checker
CLEAR		= \033[2K\c
CC			= clang++
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRCS_DIR	= sources
INC_DIR		= includes
RSLT_DIR	= results

VECTOR		= vector
MAP 		= map
STACK 		= stack

VCT_DIR		= ${SRCS_DIR}/${VECTOR}
MAP_DIR		= ${SRCS_DIR}/${MAP}
STCK_DIR	= ${SRCS_DIR}/${STACK}


all:		init ${NAME}

init:		
			$(shell mkdir -p ${RSLT_DIR})
			$(shell mkdir -p ${RSLT_DIR}/${VECTOR})
			$(shell mkdir -p ${RSLT_DIR}/${MAP})
			$(shell mkdir -p ${RSLT_DIR}/${STACK})

${NAME}:	init vector map stack

v_accss_op:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/access_operator.cpp
			touch ${RSLT_DIR}/${VECTOR}/access_operator
			./a.out > ${RSLT_DIR}/${VECTOR}/access_operator && rm a.out
v_assign:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/assign.cpp
v_at:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/at.cpp
v_back:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/back.cpp
v_begin:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/begin.cpp
v_capacity:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/capacity.cpp
v_clear:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/clear.cpp
v_empty:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/empty.cpp
v_end:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/end.cpp
v_erase:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/erase.cpp
v_front:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/front.cpp
v_get_alloc:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/get_allocator.cpp
v_insert:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/insert.cpp
v_max_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/max_size.cpp
v_pop_back:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/pop_back.cpp
v_push_back:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/push_back.cpp
v_rbegin:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/rbegin.cpp
v_rel_op:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/relational_operators.cpp
v_rend:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/rend.cpp
v_reserve:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/reserve.cpp
v_resize:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/resize.cpp
v_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/size.cpp
v_swap:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/swap.cpp


m_accss_op:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/access_operator.cpp
m_begin:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/begin.cpp
m_clean:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/clear.cpp
m_count:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/count.cpp
m_empty:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/empty.cpp
m_end:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/end.cpp
m_eql_rng:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/equal_range.cpp
m_erase:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/erase.cpp
m_find:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/find.cpp
m_get_alloc:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/get_allocator.cpp
m_insert:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/insert.cpp
m_key_comp:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/key_comp.cpp
m_lwr_bnd:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/lower_bound.cpp
m_max_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/max_size.cpp
m_rbegin:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/rbegin.cpp
m_rend:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/rend.cpp
m_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/size.cpp
m_swap:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/swap.cpp
m_uppr_bnd:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/upper_bound.cpp
m_val_cmp:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/value_comp.cpp


s_empty:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/empty.cpp
s_pop:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/pop.cpp
s_push:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/push.cpp
s_rel_op:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/relational_operators.cpp
s_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/size.cpp
s_top:
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/top.cpp

vector:	v_accss_op v_assign v_at v_back v_begin v_capacity v_clear v_empty v_end v_erase v_front v_get_alloc v_insert v_max_size v_pop_back v_push_back v_rbegin v_rel_op v_rend v_reserve v_resize v_size v_swap
map: m_accss_op m_begin m_clean m_count m_empty m_end m_eql_rng m_erase m_find m_get_alloc m_insert m_key_comp m_lwr_bnd m_max_size m_rbegin m_rend m_size m_swap m_uppr_bnd m_val_cmp
stack: s_empty s_pop s_push s_rel_op s_size s_top

clean:
			${RM} ${OBJS_DIR}

fclean:
			${RM} ${OBJS_DIR}
			${RM} ${NAME}

re:			fclean all

.SUFFIXES:	.cpp .o .hpp
.PHONY:		all clean fclean re