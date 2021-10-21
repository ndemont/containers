NAME		= checker
CLEAR		= \033[2K\c
CC			= clang++
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRCS_DIR	= sources
INC_DIR		= includes
RSLT_DIR	= results
DIFF_DIR	= differences

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
			$(shell mkdir -p ${DIFF_DIR})
			$(shell mkdir -p ${DIFF_DIR}/${VECTOR})
			$(shell mkdir -p ${DIFF_DIR}/${MAP})
			$(shell mkdir -p ${DIFF_DIR}/${STACK})

${NAME}:	init vector map stack

v_accss_op:	init
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/access_operator.cpp
			@touch ${RSLT_DIR}/${VECTOR}/access_operator_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/access_operator && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/access_operator.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/access_operator_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/access_operator && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/access_operator_diff
			@diff ${RSLT_DIR}/${VECTOR}/access_operator ${RSLT_DIR}/${VECTOR}/access_operator_std > ${DIFF_DIR}/${VECTOR}/access_operator_diff
v_assign:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/assign.cpp
			@touch ${RSLT_DIR}/${VECTOR}/assign_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/assign && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/assign.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/assign_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/assign && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/assign_diff
			@diff ${RSLT_DIR}/${VECTOR}/assign ${RSLT_DIR}/${VECTOR}/assign_std > ${DIFF_DIR}/${VECTOR}/assign_diff
v_at:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/at.cpp
			@touch ${RSLT_DIR}/${VECTOR}/at_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/at && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/at.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/at_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/at && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/at_diff
			@diff ${RSLT_DIR}/${VECTOR}/at ${RSLT_DIR}/${VECTOR}/at_std > ${DIFF_DIR}/${VECTOR}/at_diff
v_back:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/back.cpp
			@touch ${RSLT_DIR}/${VECTOR}/back_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/back && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/back.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/back_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/back && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/back_diff
			@diff ${RSLT_DIR}/${VECTOR}/back ${RSLT_DIR}/${VECTOR}/back_std > ${DIFF_DIR}/${VECTOR}/back_diff
v_begin:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/begin.cpp
			@touch ${RSLT_DIR}/${VECTOR}/begin_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/begin && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/begin.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/begin_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/begin && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/begin_diff
			@diff ${RSLT_DIR}/${VECTOR}/begin ${RSLT_DIR}/${VECTOR}/begin_std > ${DIFF_DIR}/${VECTOR}/begin_diff
v_capacity:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/capacity.cpp
			@touch ${RSLT_DIR}/${VECTOR}/capacity_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/capacity && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/capacity.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/capacity_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/capacity && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/capacity_diff
			@diff ${RSLT_DIR}/${VECTOR}/capacity ${RSLT_DIR}/${VECTOR}/capacity_std > ${DIFF_DIR}/${VECTOR}/capacity_diff
v_clear:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/clear.cpp
			@touch ${RSLT_DIR}/${VECTOR}/clear_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/clear && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/clear.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/clear_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/clear && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/clear_diff
			@diff ${RSLT_DIR}/${VECTOR}/clear ${RSLT_DIR}/${VECTOR}/clear_std > ${DIFF_DIR}/${VECTOR}/clear_diff
v_empty:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/empty.cpp
			@touch ${RSLT_DIR}/${VECTOR}/empty_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/empty && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/empty.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/empty_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/empty && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/empty_diff
			@diff ${RSLT_DIR}/${VECTOR}/empty ${RSLT_DIR}/${VECTOR}/empty_std > ${DIFF_DIR}/${VECTOR}/empty_diff
v_end:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/end.cpp
			@touch ${RSLT_DIR}/${VECTOR}/end_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/end && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/end.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/end_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/end && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/end_diff
			@diff ${RSLT_DIR}/${VECTOR}/end ${RSLT_DIR}/${VECTOR}/end_std > ${DIFF_DIR}/${VECTOR}/end_diff
v_erase:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/erase.cpp
			@touch ${RSLT_DIR}/${VECTOR}/erase_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/erase && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/erase.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/erase_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/erase && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/erase_diff
			@diff ${RSLT_DIR}/${VECTOR}/erase ${RSLT_DIR}/${VECTOR}/erase_std > ${DIFF_DIR}/${VECTOR}/erase_diff
v_front:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/front.cpp
			@touch ${RSLT_DIR}/${VECTOR}/front_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/front && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/front.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/front_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/front && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/front_diff
			@diff ${RSLT_DIR}/${VECTOR}/front ${RSLT_DIR}/${VECTOR}/front_std > ${DIFF_DIR}/${VECTOR}/front_diff
v_get_alloc:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/get_allocator.cpp
			@touch ${RSLT_DIR}/${VECTOR}/get_allocator_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/get_allocator && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/get_allocator.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/get_allocator_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/get_allocator && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/get_allocator_diff
			@diff ${RSLT_DIR}/${VECTOR}/get_allocator ${RSLT_DIR}/${VECTOR}/get_allocator_std > ${DIFF_DIR}/${VECTOR}/get_allocator_diff
v_insert:
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/insert.cpp
			@touch ${RSLT_DIR}/${VECTOR}/insert_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/insert && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/insert.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/insert_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/insert && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/insert_diff
			@diff ${RSLT_DIR}/${VECTOR}/insert ${RSLT_DIR}/${VECTOR}/insert_std > ${DIFF_DIR}/${VECTOR}/insert_diff
v_max_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/max_size.cpp
			@touch ${RSLT_DIR}/${VECTOR}/max_size_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/max_size && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/max_size.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/max_size_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/max_size && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/max_size_diff
			@diff ${RSLT_DIR}/${VECTOR}/max_size ${RSLT_DIR}/${VECTOR}/max_size_std > ${DIFF_DIR}/${VECTOR}/max_size_diff
v_pop_back:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/pop_back.cpp
			@touch ${RSLT_DIR}/${VECTOR}/pop_back_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/pop_back && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/pop_back.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/pop_back_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/pop_back && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/pop_back_diff
			@diff ${RSLT_DIR}/${VECTOR}/pop_back ${RSLT_DIR}/${VECTOR}/pop_back_std > ${DIFF_DIR}/${VECTOR}/pop_back_diff
v_push_back:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/push_back.cpp
			@touch ${RSLT_DIR}/${VECTOR}/push_back_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/push_back && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/push_back.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/push_back_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/push_back && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/push_back_diff
			@diff ${RSLT_DIR}/${VECTOR}/push_back ${RSLT_DIR}/${VECTOR}/push_back_std > ${DIFF_DIR}/${VECTOR}/push_back_diff
v_rbegin:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/rbegin.cpp
			@touch ${RSLT_DIR}/${VECTOR}/rbegin_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/rbegin && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/rbegin.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/rbegin_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/rbegin && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/rbegin_diff
			@diff ${RSLT_DIR}/${VECTOR}/rbegin ${RSLT_DIR}/${VECTOR}/rbegin_std > ${DIFF_DIR}/${VECTOR}/rbegin_diff
v_rel_op:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/relational_operators.cpp
			@touch ${RSLT_DIR}/${VECTOR}/relational_operators_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/relational_operators && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/relational_operators.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/relational_operators_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/relational_operators && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/relational_operators_diff
			@diff ${RSLT_DIR}/${VECTOR}/relational_operators ${RSLT_DIR}/${VECTOR}/relational_operators_std > ${DIFF_DIR}/${VECTOR}/relational_operators_diff
v_rend:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/rend.cpp
			@touch ${RSLT_DIR}/${VECTOR}/rend_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/rend && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/rend.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/rend_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/rend && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/rend_diff
			@diff ${RSLT_DIR}/${VECTOR}/rend ${RSLT_DIR}/${VECTOR}/rend_std > ${DIFF_DIR}/${VECTOR}/rend_diff
v_reserve:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/reserve.cpp
			@touch ${RSLT_DIR}/${VECTOR}/reserve_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/reserve && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/reserve.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/reserve_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/reserve && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/reserve_diff
			@diff ${RSLT_DIR}/${VECTOR}/reserve ${RSLT_DIR}/${VECTOR}/reserve_std > ${DIFF_DIR}/${VECTOR}/reserve_diff
v_resize:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/resize.cpp
			@touch ${RSLT_DIR}/${VECTOR}/resize_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/resize && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/resize.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/resize_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/resize && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/resize_diff
			@diff ${RSLT_DIR}/${VECTOR}/resize ${RSLT_DIR}/${VECTOR}/resize_std > ${DIFF_DIR}/${VECTOR}/resize_diff
v_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/size.cpp
			@touch ${RSLT_DIR}/${VECTOR}/size_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/size && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/size.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/size_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/size && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/size_diff
			@diff ${RSLT_DIR}/${VECTOR}/size ${RSLT_DIR}/${VECTOR}/size_std > ${DIFF_DIR}/${VECTOR}/size_diff
v_swap:
			${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/swap.cpp
			@touch ${RSLT_DIR}/${VECTOR}/swap_ft
			@./a.out > ${RSLT_DIR}/${VECTOR}/swap && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${VCT_DIR}/swap.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${VECTOR}/swap_std
			@./a.out > ${RSLT_DIR}/${VECTOR}/swap && rm a.out
			@touch ${DIFF_DIR}/${VECTOR}/swap_diff
			@diff ${RSLT_DIR}/${VECTOR}/swap ${RSLT_DIR}/${VECTOR}/swap_std > ${DIFF_DIR}/${VECTOR}/swap_diff

m_accss_op:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/access_operator.cpp
			@touch ${RSLT_DIR}/${MAP}/access_operator_ft
			@./a.out > ${RSLT_DIR}/${MAP}/access_operator && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/access_operator.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/access_operator_std
			@./a.out > ${RSLT_DIR}/${MAP}/access_operator && rm a.out
			@touch ${DIFF_DIR}/${MAP}/access_operator_diff
			@diff ${RSLT_DIR}/${MAP}/access_operator ${RSLT_DIR}/${MAP}/access_operator_std > ${DIFF_DIR}/${MAP}/access_operator_diff
m_begin:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/begin.cpp
			@touch ${RSLT_DIR}/${MAP}/begin_ft
			@./a.out > ${RSLT_DIR}/${MAP}/begin && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/begin.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/begin_std
			@./a.out > ${RSLT_DIR}/${MAP}/begin && rm a.out
			@touch ${DIFF_DIR}/${MAP}/begin_diff
			@diff ${RSLT_DIR}/${MAP}/begin ${RSLT_DIR}/${MAP}/begin_std > ${DIFF_DIR}/${MAP}/begin_diff
m_clear:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/clear.cpp
			@touch ${RSLT_DIR}/${MAP}/clear_ft
			@./a.out > ${RSLT_DIR}/${MAP}/clear && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/clear.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/clear_std
			@./a.out > ${RSLT_DIR}/${MAP}/clear && rm a.out
			@touch ${DIFF_DIR}/${MAP}/clear_diff
			@diff ${RSLT_DIR}/${MAP}/clear ${RSLT_DIR}/${MAP}/clear_std > ${DIFF_DIR}/${MAP}/clear_diff
m_count:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/count.cpp
			@touch ${RSLT_DIR}/${MAP}/count_ft
			@./a.out > ${RSLT_DIR}/${MAP}/count && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/count.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/count_std
			@./a.out > ${RSLT_DIR}/${MAP}/count && rm a.out
			@touch ${DIFF_DIR}/${MAP}/count_diff
			@diff ${RSLT_DIR}/${MAP}/count ${RSLT_DIR}/${MAP}/count_std > ${DIFF_DIR}/${MAP}/count_diff
m_empty:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/empty.cpp
			@touch ${RSLT_DIR}/${MAP}/empty_ft
			@./a.out > ${RSLT_DIR}/${MAP}/empty && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/empty.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/empty_std
			@./a.out > ${RSLT_DIR}/${MAP}/empty && rm a.out
			@touch ${DIFF_DIR}/${MAP}/empty_diff
			@diff ${RSLT_DIR}/${MAP}/empty ${RSLT_DIR}/${MAP}/empty_std > ${DIFF_DIR}/${MAP}/empty_diff
m_end:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/end.cpp
			@touch ${RSLT_DIR}/${MAP}/end_ft
			@./a.out > ${RSLT_DIR}/${MAP}/end && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/end.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/end_std
			@./a.out > ${RSLT_DIR}/${MAP}/end && rm a.out
			@touch ${DIFF_DIR}/${MAP}/end_diff
			@diff ${RSLT_DIR}/${MAP}/end ${RSLT_DIR}/${MAP}/end_std > ${DIFF_DIR}/${MAP}/end_diff
m_eql_rng:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/equal_range.cpp
			@touch ${RSLT_DIR}/${MAP}/equal_range_ft
			@./a.out > ${RSLT_DIR}/${MAP}/equal_range && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/equal_range.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/equal_range_std
			@./a.out > ${RSLT_DIR}/${MAP}/equal_range && rm a.out
			@touch ${DIFF_DIR}/${MAP}/equal_range_diff
			@diff ${RSLT_DIR}/${MAP}/equal_range ${RSLT_DIR}/${MAP}/equal_range_std > ${DIFF_DIR}/${MAP}/equal_range_diff
m_erase:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/erase.cpp
			@touch ${RSLT_DIR}/${MAP}/erase_ft
			@./a.out > ${RSLT_DIR}/${MAP}/erase && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/erase.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/erase_std
			@./a.out > ${RSLT_DIR}/${MAP}/erase && rm a.out
			@touch ${DIFF_DIR}/${MAP}/erase_diff
			@diff ${RSLT_DIR}/${MAP}/erase ${RSLT_DIR}/${MAP}/erase_std > ${DIFF_DIR}/${MAP}/erase_diff
m_find:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/find.cpp
			@touch ${RSLT_DIR}/${MAP}/find_ft
			@./a.out > ${RSLT_DIR}/${MAP}/find && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/find.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/find_std
			@./a.out > ${RSLT_DIR}/${MAP}/find && rm a.out
			@touch ${DIFF_DIR}/${MAP}/find_diff
			@diff ${RSLT_DIR}/${MAP}/find ${RSLT_DIR}/${MAP}/find_std > ${DIFF_DIR}/${MAP}/find_diff
m_get_alloc:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/get_allocator.cpp
			@touch ${RSLT_DIR}/${MAP}/get_allocator_ft
			@./a.out > ${RSLT_DIR}/${MAP}/get_allocator && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/get_allocator.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/get_allocator_std
			@./a.out > ${RSLT_DIR}/${MAP}/get_allocator && rm a.out
			@touch ${DIFF_DIR}/${MAP}/get_allocator_diff
			@diff ${RSLT_DIR}/${MAP}/get_allocator ${RSLT_DIR}/${MAP}/get_allocator_std > ${DIFF_DIR}/${MAP}/get_allocator_diff
m_insert:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/insert.cpp
			@touch ${RSLT_DIR}/${MAP}/insert_ft
			@./a.out > ${RSLT_DIR}/${MAP}/insert && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/insert.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/insert_std
			@./a.out > ${RSLT_DIR}/${MAP}/insert && rm a.out
			@touch ${DIFF_DIR}/${MAP}/insert_diff
			@diff ${RSLT_DIR}/${MAP}/insert ${RSLT_DIR}/${MAP}/insert_std > ${DIFF_DIR}/${MAP}/insert_diff
m_key_comp:
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/key_comp.cpp
			@touch ${RSLT_DIR}/${MAP}/key_comp_ft
			@./a.out > ${RSLT_DIR}/${MAP}/key_comp && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/key_comp.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/key_comp_std
			@./a.out > ${RSLT_DIR}/${MAP}/key_comp && rm a.out
			@touch ${DIFF_DIR}/${MAP}/key_comp_diff
			@diff ${RSLT_DIR}/${MAP}/key_comp ${RSLT_DIR}/${MAP}/key_comp_std > ${DIFF_DIR}/${MAP}/key_comp_diff
m_lwr_bnd:
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/lower_bound.cpp
			@touch ${RSLT_DIR}/${MAP}/lower_bound_ft
			@./a.out > ${RSLT_DIR}/${MAP}/lower_bound && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/lower_bound.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/lower_bound_std
			@./a.out > ${RSLT_DIR}/${MAP}/lower_bound && rm a.out
			@touch ${DIFF_DIR}/${MAP}/lower_bound_diff
			@diff ${RSLT_DIR}/${MAP}/lower_bound ${RSLT_DIR}/${MAP}/lower_bound_std > ${DIFF_DIR}/${MAP}/lower_bound_diff
m_max_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/max_size.cpp
			@touch ${RSLT_DIR}/${MAP}/max_size_ft
			@./a.out > ${RSLT_DIR}/${MAP}/max_size && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/max_size.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/max_size_std
			@./a.out > ${RSLT_DIR}/${MAP}/max_size && rm a.out
			@touch ${DIFF_DIR}/${MAP}/max_size_diff
			@diff ${RSLT_DIR}/${MAP}/max_size ${RSLT_DIR}/${MAP}/max_size_std > ${DIFF_DIR}/${MAP}/max_size_diff
m_rbegin:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/rbegin.cpp
			@touch ${RSLT_DIR}/${MAP}/rbegin_ft
			@./a.out > ${RSLT_DIR}/${MAP}/rbegin && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/rbegin.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/rbegin_std
			@./a.out > ${RSLT_DIR}/${MAP}/rbegin && rm a.out
			@touch ${DIFF_DIR}/${MAP}/rbegin_diff
			@diff ${RSLT_DIR}/${MAP}/rbegin ${RSLT_DIR}/${MAP}/rbegin_std > ${DIFF_DIR}/${MAP}/rbegin_diff
m_rend:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/rend.cpp
			@touch ${RSLT_DIR}/${MAP}/rend_ft
			@./a.out > ${RSLT_DIR}/${MAP}/rend && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/rend.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/rend_std
			@./a.out > ${RSLT_DIR}/${MAP}/rend && rm a.out
			@touch ${DIFF_DIR}/${MAP}/rend_diff
			@diff ${RSLT_DIR}/${MAP}/rend ${RSLT_DIR}/${MAP}/rend_std > ${DIFF_DIR}/${MAP}/rend_diff
m_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/size.cpp
			@touch ${RSLT_DIR}/${MAP}/size_ft
			@./a.out > ${RSLT_DIR}/${MAP}/size && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/size.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/size_std
			@./a.out > ${RSLT_DIR}/${MAP}/size && rm a.out
			@touch ${DIFF_DIR}/${MAP}/size_diff
			@diff ${RSLT_DIR}/${MAP}/size ${RSLT_DIR}/${MAP}/size_std > ${DIFF_DIR}/${MAP}/size_diff
m_swap:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/swap.cpp
			@touch ${RSLT_DIR}/${MAP}/swap_ft
			@./a.out > ${RSLT_DIR}/${MAP}/swap && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/swap.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/swap_std
			@./a.out > ${RSLT_DIR}/${MAP}/swap && rm a.out
			@touch ${DIFF_DIR}/${MAP}/swap_diff
			@diff ${RSLT_DIR}/${MAP}/swap ${RSLT_DIR}/${MAP}/swap_std > ${DIFF_DIR}/${MAP}/swap_diff
m_uppr_bnd:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/upper_bound.cpp
			@touch ${RSLT_DIR}/${MAP}/upper_bound_ft
			@./a.out > ${RSLT_DIR}/${MAP}/upper_bound && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/upper_bound.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/upper_bound_std
			@./a.out > ${RSLT_DIR}/${MAP}/upper_bound && rm a.out
			@touch ${DIFF_DIR}/${MAP}/upper_bound_diff
			@diff ${RSLT_DIR}/${MAP}/upper_bound ${RSLT_DIR}/${MAP}/upper_bound_std > ${DIFF_DIR}/${MAP}/upper_bound_diff
m_val_cmp:
			${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/value_comp.cpp
			@touch ${RSLT_DIR}/${MAP}/value_comp_ft
			@./a.out > ${RSLT_DIR}/${MAP}/value_comp && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${MAP_DIR}/value_comp.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${MAP}/value_comp_std
			@./a.out > ${RSLT_DIR}/${MAP}/value_comp && rm a.out
			@touch ${DIFF_DIR}/${MAP}/value_comp_diff
			@diff ${RSLT_DIR}/${MAP}/value_comp ${RSLT_DIR}/${MAP}/value_comp_std > ${DIFF_DIR}/${MAP}/value_comp_diff


s_empty:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/empty.cpp
			@touch ${RSLT_DIR}/${STACK}/empty_ft
			@./a.out > ${RSLT_DIR}/${STACK}/empty && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/empty.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${STACK}/empty_std
			@./a.out > ${RSLT_DIR}/${STACK}/empty && rm a.out
			@touch ${DIFF_DIR}/${STACK}/empty_diff
			@diff ${RSLT_DIR}/${STACK}/empty ${RSLT_DIR}/${STACK}/empty_std > ${DIFF_DIR}/${STACK}/empty_diff
s_pop:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/pop.cpp
			@touch ${RSLT_DIR}/${STACK}/pop_ft
			@./a.out > ${RSLT_DIR}/${STACK}/pop && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/pop.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${STACK}/pop_std
			@./a.out > ${RSLT_DIR}/${STACK}/pop && rm a.out
			@touch ${DIFF_DIR}/${STACK}/pop_diff
			@diff ${RSLT_DIR}/${STACK}/pop ${RSLT_DIR}/${STACK}/pop_std > ${DIFF_DIR}/${STACK}/pop_diff
s_push:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/push.cpp
			@touch ${RSLT_DIR}/${STACK}/push_ft
			@./a.out > ${RSLT_DIR}/${STACK}/push && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/push.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${STACK}/push_std
			@./a.out > ${RSLT_DIR}/${STACK}/push && rm a.out
			@touch ${DIFF_DIR}/${STACK}/push_diff
			@diff ${RSLT_DIR}/${STACK}/push ${RSLT_DIR}/${STACK}/push_std > ${DIFF_DIR}/${STACK}/push_diffp
s_rel_op:	
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/relational_operators.cpp
			@touch ${RSLT_DIR}/${STACK}/relational_operators_ft
			@./a.out > ${RSLT_DIR}/${STACK}/relational_operators && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/relational_operators.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${STACK}/relational_operators_std
			@./a.out > ${RSLT_DIR}/${STACK}/relational_operators && rm a.out
			@touch ${DIFF_DIR}/${STACK}/relational_operators_diff
			@diff ${RSLT_DIR}/${STACK}/relational_operators ${RSLT_DIR}/${STACK}/relational_operators_std > ${DIFF_DIR}/${STACK}/relational_operators_diff
s_size:
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/size.cpp
			@touch ${RSLT_DIR}/${STACK}/size_ft
			@./a.out > ${RSLT_DIR}/${STACK}/size && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/size.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${STACK}/size_std
			@./a.out > ${RSLT_DIR}/${STACK}/size && rm a.out
			@touch ${DIFF_DIR}/${STACK}/size_diff
			@diff ${RSLT_DIR}/${STACK}/size ${RSLT_DIR}/${STACK}/size_std > ${DIFF_DIR}/${STACK}/size_diff
s_top:
			${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/top.cpp
			@touch ${RSLT_DIR}/${STACK}/top_ft
			@./a.out > ${RSLT_DIR}/${STACK}/top && rm a.out
			@${CC} ${CFLAGS} -I${INC_DIR} ${STCK_DIR}/top.cpp -D NAMESPACE=std
			@touch ${RSLT_DIR}/${STACK}/top_std
			@./a.out > ${RSLT_DIR}/${STACK}/top && rm a.out
			@touch ${DIFF_DIR}/${STACK}/top_diff
			@diff ${RSLT_DIR}/${STACK}/top ${RSLT_DIR}/${STACK}/top_std > ${DIFF_DIR}/${STACK}/top_diff

vector:	v_accss_op v_assign v_at v_back v_begin v_capacity v_clear v_empty v_end v_erase v_front v_get_alloc v_insert v_max_size v_pop_back v_push_back v_rbegin v_rel_op v_rend v_reserve v_resize v_size v_swap
map: m_accss_op m_begin m_clear m_count m_empty m_end m_eql_rng m_erase m_find m_get_alloc m_insert m_key_comp m_lwr_bnd m_max_size m_rbegin m_rend m_size m_swap m_uppr_bnd m_val_cmp
stack: s_empty s_pop s_push s_rel_op s_size s_top

clean:
			${RM} ${OBJS_DIR}

fclean:
			${RM} ${OBJS_DIR}
			${RM} ${NAME}

re:			fclean all

.SUFFIXES:	.cpp .o .hpp
.PHONY:		all clean fclean re