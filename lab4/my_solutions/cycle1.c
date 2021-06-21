#include "cycle.h"

Boolean testCyclic(struct linkedlist* Ls) {
	// case of empty list
	if (Ls == NULL || Ls->count == 0)
		return FALSE;
	
	// case of size 1 list
	else if (Ls->count == 1)
		return ((Ls->head)->next == Ls->head) ? TRUE : FALSE;

	// case of size 2 list
	else if (Ls->count == 2) {
		struct node *first = Ls->head;
		struct node *second = first->next;
		return (second->next == first || second->next == second) ? TRUE : FALSE;
	}

	else {
		struct node *tort = Ls->head, *hare = Ls->head;
		while (hare != NULL || hare != tort) {
			if (hare->next == NULL || (hare->next)->next == NULL || tort->next == NULL)
				return FALSE;
			tort = tort->next;
			hare = (hare->next)->next;
			if (hare == tort && hare != NULL)
				return TRUE;
		}
		return FALSE;
	}
}
