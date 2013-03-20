/*
** normal.c for normal in /home/welanor/Projet/Igraph/RT_V1/Test
**
** Made by Adrien dellamaggiora
** Login   <dellam_a@epitech.eu>
**
** Started on  Tue Feb 19 12:51:45 2013 Adrien dellamaggiora
** Last update Thu Mar 14 16:32:53 2013 Adrien
*/

#include "include.h"

t_coord	norsphere(t_coord pos, t_coord *pt, t_obj *obj)
{
    pos.x = pt->x - obj->pos.x;
    pos.y = pt->y - obj->pos.y;
    pos.z = pt->z - obj->pos.z;
    return (pos);
}

t_coord	norplan(t_coord pos, t_coord *pt, t_obj *obj)
{
    pos.x = 0;
    pos.y = 0;
    pos.z = 100;
    rotate_x(obj->rot.x, &pos);
    rotate_y(obj->rot.y, &pos);
    rotate_z(obj->rot.z, &pos);
    pos.x = pos.x - obj->pos.x;
    pos.y = pos.y - obj->pos.y;
    pos.z = pos.z - obj->pos.z;
    return (pos);
}

t_coord	norcylindre(t_coord pos, t_coord *pt, t_obj *obj)
{
    pos.x = pt->x;
    pos.y = pt->y;
    pos.z = 0;
    rotate_x(obj->rot.x, &pos);
    rotate_y(obj->rot.y, &pos);
    rotate_z(obj->rot.z, &pos);
    pos.x = pos.x - obj->pos.x;
    pos.y = pos.y - obj->pos.y;
    pos.z = pos.z - obj->pos.z;
    return (pos);
}

t_coord	norcone(t_coord pos, t_coord *pt, t_obj *obj)
{
    pos.x = pt->x;
    pos.y = pt->y;
    pos.z = (- 0.5)  * pt->z;
    rotate_x(obj->rot.x, &pos);
    rotate_y(obj->rot.y, &pos);
    rotate_z(obj->rot.z, &pos);
    pos.x = pos.x - obj->pos.x;
    pos.y = pos.y - obj->pos.y;
    pos.z = pos.z - obj->pos.z;
    return (pos);
}
