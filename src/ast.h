#ifndef AST_H
#define AST_H

#include <stdlib.h>

enum ast_type {
	A_ID,
	A_INT,
	A_FUNCTION,
	A_RETURN,
	A_IF
};

/*
 * AST nodes
 */
typedef struct ast_base
{
	enum ast_type type;
} ast_base;

typedef struct node_id
{
	ast_base base;
	char * value;
} node_id;

typedef struct node_int
{
	ast_base base;
	int value;
} node_int;

typedef struct node_function
{
	ast_base base;
	char * name;
	ast_base * entry_point;
} node_function;

typedef struct node_return
{
	ast_base base;
	ast_base * value;
} node_return;

typedef struct node_if
{
	ast_base base;
	ast_base * expression;
} node_if;

/*
 * Init functions for the AST nodes
 */
void init_node_id(node_id * node, char * value);
void init_node_int(node_int * node, int value);
void init_node_function(node_function * node, char * name, ast_base * entry_point);
void init_node_return(node_return * node, ast_base * value);
void init_node_if(node_if * node, ast_base * expression);

/*
 * Release functions for the AST nodes
 */
void free_node_id(node_id * node);
void free_node_int(node_int * node);
void free_node_function(node_function * node);
void free_node_return(node_return * node);
void free_node_if(node_if * node);
#endif //AST_H
