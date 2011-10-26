/*
** list.h for lib_list in /home/jonathan/Projets/utils/lib_linked_list
**
** Made by Jonathan Machado
** Login   <jonathan.machado@epitech.net>
**
** Started on  Mon Oct 24 10:06:47 2011 Jonathan Machado
** Last update Wed Oct 26 15:12:03 2011 Jonathan Machado
*/

#ifndef __LIST_H__
# define __LIST_H__
# include "link.h"

typedef	struct List	List;
struct			List
{
  unsigned int	size;
  Link		*head;
  Link		*tail;
};

#define for_each(pos, list) \
  for (pos = list->head, list->tail->next = NULL; pos != NULL || \
(list->head->prev != NULL && !(list->tail = list->head)); pos = pos->next)

List		*new_list(void);
List		*new_list_by_copy(List *list);

Link		*pop_front(List *list);
Link		*pop_end(List *list);
Link		*pop_at(List *list, unsigned int pos);
void		push_front(List *list, Link *new);
void		push_end(List *list, Link *new);
void		push_at(List *list, Link *new, unsigned int pos);
Link		*get_link(List *list, unsigned int pos);

int		is_in_list(List *list, void *ptr);

List		*revert(List *list);
List		*sort(List *list, int (*f)(void *, void *));
List		*iterate(List *list, void (*f)(void *));
List		*circular(List *list);
List		*concat(List *list1, List *list2);
List		*unique(List *list);
List		*split(List *list, List *new, int pos);
List		*merge(List *list1, List *list2, int (*f)(void *, void *));

void		delete_list(List *list, void (*f)(void *));

/*	TO DO
**
** unique:
** insert : isert a list at a given pos
** get_link_pos : return the pos of a link cmp *ptr
** get_same_link : return ptr of a link cmp *ptr
** doc
*/

#endif	/* __LIST_H__ */
