/*
** list.c for lib_list in /home/jonathan/Projets/utils/lib_linked_list
**
** Made by Jonathan Machado
** Login   <jonathan.machado@epitech.net>
**
** Started on  Mon Oct 24 14:47:22 2011 Jonathan Machado
** Last update Tue Oct 25 16:10:02 2011 Jonathan Machado
*/

#include <stdlib.h>
#include <string.h>
#include "list.h"

List	*new_list(void)
{
  List	*new = NULL;

  new = malloc(sizeof(*new));
  new = memset(new, 0, sizeof(*new));
  return (new);
}

List	*new_list_by_copy(List *list)
{
  List	*new = NULL;
  Link	*cur = NULL;

  new = malloc(sizeof(*new));
  new = memset(new, 0, sizeof(*new));
  for_each(cur, list) {
    push_end(new, new_link_by_copy(cur));
  }
  return (new);
}

Link	*pop_front(List *list)
{
  Link	*ret = NULL;

  if (list != NULL) {
    if (list->head != NULL) {
      ret = list->head;
      if (ret->next != NULL)
	ret->next->prev = ret->prev;
      if (ret->prev != NULL)
	ret->prev->next = ret->next;
      list->head = ret->next;
      if (ret->next == NULL || ret == ret->next) {
	list->head = NULL;
	list->tail = NULL;
      }
      ret->next = NULL;
      ret->prev = NULL;
      list->size -= 1;
    }
  }
  return (ret);
}

Link	*pop_end(List *list)
{
  Link	*ret = NULL;

  if (list != NULL) {
    if (list->tail != NULL) {
      ret = list->tail;
      if (ret->next != NULL)
	ret->next->prev = ret->prev;
      if (ret->prev != NULL)
	ret->prev->next = ret->next;
      list->tail = ret->prev;
      if (ret->prev == NULL || ret == ret->prev) {
	list->head = NULL;
	list->tail = NULL;
      }
      ret->next = NULL;
      ret->prev = NULL;
      list->size -= 1;
    }
  }
  return (ret);
}

Link	*pop_at(List *list, unsigned int pos)
{
  int	i;
  Link	*ret = NULL;

  if (list != NULL) {
    if (list->size > pos) {
      if (pos == 0) {
	ret = pop_front(list);
      } else if (pos == list->size - 1) {
	ret = pop_end(list);
      } else {
	for (i = 0, ret = list->head; i < pos;
	     i++, ret = ret->next);
	ret->next->prev = ret->prev;
	ret->prev->next = ret->next;
	ret->next = NULL;
	ret->prev = NULL;
	list->size -= 1;
      }
    }
  }
  return (ret);
}

void	push_front(List *list, Link *new)
{
  if (list != NULL) {
    if (new != NULL) {
      new->prev = NULL;
      new->next = list->head;
      if (list->head != NULL) {
	if (list->head->prev != NULL)
	  new->prev = list->head->prev;
	if (list->tail->next != NULL)
	  list->tail->next = new;
	list->head->prev = new;
      }
      if (list->tail == NULL)
	list->tail = new;
      list->head = new;
      list->size += 1;
    }
  }
}

void	push_end(List *list, Link *new)
{
  if (list != NULL) {
    if (new != NULL) {
      new->next = NULL;
      new->prev = list->tail;
      if (list->tail != NULL) {
	if (list->tail->next != NULL)
	  new->next = list->tail->next;
	if (list->head->prev != NULL)
	  list->head->prev = new;
	list->tail->next = new;
      }
      if (list->head == NULL)
	list->head = new;
      list->tail = new;
      list->size += 1;
    }
  }
}

void	push_at(List *list, Link *new, unsigned int pos)
{
  int	i;

  if (list != NULL) {
    if (new != NULL) {
      if (list->size > pos) {
	if (pos == 0) {
	  ret = push_front(list, new);
	} else if (pos == list->size - 1) {
	  ret = push_end(list, new);
	} else {
	  for (i = 0, ret = list->head; i < pos;
	       i++, ret = ret->next);
	  cur->prev->next = new;
	  new->prev = cur->prev;
	  cur->prev = new;
	  new->next = cur;
	  list->size += 1;
	}
      }
    }
  }
}

int	is_in_list(List *list, void *ptr)
{
  Link	*cur = NULL;

  if (list != NULL) {
    for_each(cur, list) {
      if (memcmp(cur->ptr, ptr, sizeof(*ptr)) == 0)
	return (1);
    }
  }
  return (0);
}

void	revert(List *list)
{
  Link	*cur = NULL;
  Link	*tmp = NULL;

  if (list != NULL) {
    for (cur = list->head; cur != NULL || cur != list->tail->next;
	 cur = temp) {
      tmp = cur->next;
      cur->next = cur->prev;
      cur->prev = temp;
    }
    tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
  }
}

void	sort(List *list, int (*f)(void *, void *))
{

}

void	iterate(List *list, void (*f)(void *))
{
  Link	*cur = NULL;

  if (list != NULL) {
  for_each(cur, list) {
      f(cur->ptr);
    }
  }
}

void	circular(List *list)
{
  if (list != NULL) {
    if (list->tail->next && list->head->prev) {
      list->tail->next = list->head;
      list->head->prev = list->tail;
    } else {
      list->tail->next = NULL;
      list->head->prev = NULL;
    }
  }
}

void	concat(List *list1, List *list2)
{

}

void	unique(List *list)
{

}

List	*revert_copy(List *list)
{
  List	*new;

  new = new_list_by_copy(list);
  revert(new);
  return (new);
}

List	*sort_copy(List *list, int (*f)(void *, void *))
{
  List	*new;

  new = new_list_by_copy(list);
  sort(new, f);
  return (new);
}

List	*iterate_copy(List *list, void (*f)(void *))
{
  List	*new;

  new = new_list_by_copy(list);
  iterate(new, f);
  return (new);
}

List	*circular_copy(List *list)
{
  List	*new;

  new = new_list_by_copy(list);
  circular(new);
  return (new);
}

List	*concat_copy(List *list1, List *list2)
{
  List	*new;

  new = new_list_by_copy(list);
  concat(new, list2);
  return (new);
}

List	*unique_copy(List *list)
{
  List	*new;

  new = new_list_by_copy(list);
  unique(new);
  return (new);
}

static void	delete_link_list(Link *link, void (*f)(void *))
{
  if (link->next != NULL)
    delete_link_list(link->next, f);
  delete_link(link, f);
}

void	delete_list(List *list, void (*f)(void *))
{
  delete_link_list(list->head, f);
  free(list);
  list = NULL;
}
