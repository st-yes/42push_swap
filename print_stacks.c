#include "push_swap.h"

/*
* print the data of a circular doubly linked list's nodes 
*/
void	print_list(t_node **head)
{
	t_node	*first_node;

	if (!*head)
	{
		printf("empty list\n");
		return ;
	}
	first_node = *head;
	printf("%d\n", first_node->data);
	first_node = first_node->next;
	while (first_node != *head)
	{
		printf("%d\n", first_node->data);
		first_node = first_node->next;
	}
}

/*
* print the index / data of a circular doubly linked list's nodes 
*/
void	print_list_with_index(t_node **head)
{
	t_node	*first_node;

	if (!*head)
	{
		printf("empty list\n");
		return ;
	}
	first_node = *head;
	printf("[%d] %d\n", first_node->index, first_node->data);
	first_node = first_node->next;
	while (first_node != *head)
	{
		printf("[%d] %d\n", first_node->index, first_node->data);
		first_node = first_node->next;
	}
}

/*
* print what's in both stacks A & B
*/
void	print_stacks(t_node	**stack_a, t_node	**stack_b)
{
	printf("stack a----\n");
	print_list(stack_a);
	printf("stack b----\n");
	print_list(stack_b);
}
/*
* print what's in both stacks A & B + indexes
*/
void	print_stacks_index(t_node	**stack_a, t_node	**stack_b)
{
	printf("stack a----\n");
	print_list_with_index(stack_a);
	printf("stack b----\n");
	print_list_with_index(stack_b);
}