#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to head of list
 * @index: the index of the node, starting from 0
 *
 * Return: returns the nth node of or NULL if node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;
	dlistint_t *temp = head;

	while (temp != NULL)
	{
		if (count == index)
			return (temp);
		temp = temp->next;
		count++;
	}

	return (NULL);
}


/**
 * sum_dlistint - returns the sum of all the data (n) of list
 * @head: pointer to head of list
 *
 * Return: returns the sum of all the data or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}



/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to head of list
 * @idx: index of the list where the new node should be added
 * @n: value to insert
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new, *temp;

	new = malloc(sizeof(dlistint_t));
	if (!new || !h)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;
	for (i = 0; temp != NULL && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));

			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		temp = temp->next;
	}

	return (NULL);
}



/**
 * delete_dnodeint_at_index -  deletes the node at index index of a list
 * @head: pointer to pointer to head of list
 * @index: index of the node that should be deleted
 *
 * Return: Returns: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;

	if (head == NULL)
		return (-1);
	current = *head;

	if (index == 0)
	{
		if (current == NULL)
			return (-1);
		*head = current->next;
		if (*head)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	for (; current; current = current->next, index--)
	{
		if (index - 1 == 0)
		{
			temp = current->next;
			if (!temp)
				break;
			current->next = temp->next;
			if (temp->next)
				temp->next->prev = current;
			free(temp);
			return (1);
		}
	}

	return (-1);
}
