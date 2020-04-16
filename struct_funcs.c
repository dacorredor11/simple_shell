#include "shell.h"

/**
 * add_node - function that adds a node
 * @head: head of the list
 * @str: String of the instance
 * Return: new list
 */

path_t *add_node(path_t **head, char *str)
{
	path_t *new;
	path_t *temporal = *head;

	new = malloc(sizeof(path_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->route = _strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (temporal->next != NULL)
		temporal = temporal->next;

	temporal->next = new;

	return (new);
}
