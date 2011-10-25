/*
** list.h for lib_list in /home/jonathan/Projets/utils/lib_linked_list
**
** Made by Jonathan Machado
** Login   <jonathan.machado@epitech.net>
**
** Started on  Mon Oct 24 10:06:47 2011 Jonathan Machado
** Last update Tue Oct 25 16:09:38 2011 Jonathan Machado
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
  for (pos = list->head; pos != NULL || pos != list->tail->next; \
       pos = pos->next)

List		*new_list(void);
List		*new_list_by_copy(List *list);

Link		*pop_front(List *list);
Link		*pop_end(List *list);
Link		*pop_at(List *list, unsigned int pos);
void		push_front(List *list, Link *new);
void		push_end(List *list, Link *new);
void		push_at(List *list, Link *new, unsigned int pos);

int		is_in_list(List *list, void *ptr);

void		revert(List *list);
void		sort(List *list, int (*f)(void *, void *));
void		iterate(List *list, void (*f)(void *));
void		circular(List *list);
void		concat(List *list, List *list2);
void		unique(List *list);

List   		*revert_copy(List *list);
List	       	*sort_copy(List *list, int (*f)(void *, void *));
List            *iterate_copy(List *list, Link *(*f)(void *));
List   		*circular_copy(List *list);
List	       	*concat_copy(List *list1, List *list2);
List	       	*unique_copy(List *list);

void		delete_list(List *list, void (*f)(void *));

/*	TO DO
**
** insert : isert a list at a given pos
** split : split in two list at a given pos
** merge : concat and sort 2 list
** remove : remove a link at a given pos
** get_link_pos : return the pos of a link cmp *ptr
** get_same_link : return ptr of a link cmp *ptr
** get_pos_link : return the ptr of link at pos
** doc
*/

#endif	/* __LIST_H__ */
