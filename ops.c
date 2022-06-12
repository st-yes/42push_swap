#include "push_swap.h"

/**
* swap first two elements of the list
*/
void	swap(t_node	**head)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;
	t_node	*last_node;

	first_node = *head;
	second_node = first_node->next;
	third_node = second_node->next;
	last_node = first_node->prev;

	
	first_node->next = third_node;
	first_node->prev = second_node;
	second_node->next = first_node;
	second_node->prev = last_node;
	third_node->prev = first_node;
	last_node->next = second_node;
	*head = second_node;
}
/**
 * first element becomes last 
 */
void	rotate(t_node	**head)
{
	t_node	*second_node;

	second_node = (*head)->next;
	*head = second_node;
}

/*
* last element becomes first
*/
void	rev_rotate(t_node	**head)
{
	t_node	*last_node;

	last_node = (*head)->prev;
	*head = last_node;
}

/*
* push first element of stack1 to the top of stack2
* works good unless we don't have a stack2
*/
t_node	*push(t_node	**stack1, t_node **stack2)
{
	int	data_of_first;

	data_of_first = (*stack1)->data;
	pop(stack1);

	if (*stack2 == NULL)
		*stack2 = create_node(data_of_first, 0);
	else
		add_node_beg(stack2, create_node(data_of_first, 0));
	return (*stack2);
}

void	del_node(t_node	*node)
{
	free(node);
	node = NULL;
}

/*
* delete first element of list
* use free!
*/
void	pop(t_node	**head)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	first_node = *head;
	second_node = first_node->next;
	last_node = first_node->prev;

	if (first_node == last_node)
	{
		del_node(first_node);
		*head = NULL;
		return ;
	}
	second_node->prev = last_node;
	last_node->next = second_node;
	del_node(first_node);
	*head = second_node;
}