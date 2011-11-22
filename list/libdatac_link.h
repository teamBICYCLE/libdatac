/*
** link.h for lib_list in /home/jonathan/Projets/utils/lib_linked_list
**
** Made by Jonathan Machado
** Login   <jonathan.machado@epitech.net>
**
** Started on  Mon Oct 24 10:10:53 2011 Jonathan Machado
** Last update Thu Nov 17 14:10:37 2011 Jonathan Machado
*/

#ifndef __LINK_H__
# define __LIST_H__

typedef struct Link	Link;
struct			Link
{
  void	*ptr;
  Link	*next;
  Link	*prev;
};

Link	*new_link(void);
Link	*new_link_by_copy(Link *link);
Link	*new_link_by_param(void *ptr);
void   	delete_link(Link *link, void (*f)(void*));

#endif /* __LIST_H__ */
