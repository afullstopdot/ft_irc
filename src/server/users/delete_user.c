# include <server.h>

/*
** Given a reference to the head of a list
** and a key, delete a node
*/

void			ft_delete_user(t_user **head, int key)
{

	t_user		*temp;
	t_user		*prev;

	/*
	** Store head node
	*/

	temp = *head;

	/*
	** Check if the head node itself holds the key to be deleted
	*/

	if (temp && temp->c_index == key)
	{

		/*
		** Change head
		*/

		*head = temp->next;

		/*
		** Doesnt need to be freed (ot dynamically allocated)
		*/

		return ;

	}

	/*
	** Search for the key to be deleted, keep track of the previous node
	** as we need to change 'prev->next'
	*/

	while (temp && temp->c_index != key)
	{

		/*
		** Update previous node
		*/

		prev = temp;

		/*
		** Increment
		*/

		temp = temp->next;

	}

	/*
	** If the key was not present
	*/

	if (!temp)
		return ;

	/*
	** Unlink the node
	*/

	prev->next = temp->next;

}