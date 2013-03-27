/*
** main.c for main in /home/sinet_l//rtv1
**
** Made by luc sinet
** Login   <sinet_l@epitech.net>
**
** Started on  Mon Feb 25 10:36:59 2013 luc sinet
** Last update Mon Mar 25 22:18:53 2013 luc sinet
*/

#include "main.h"
#include "pars.h"
#include "mlx.h"

float msqrt( float number ){
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;  // evil floating point bit level hacking
  i  = 0x5f3759df - ( i >> 1 ); // what the fuck?
  y  = * ( float * ) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) ); // 1st iteration
  // y  = y * ( threehalfs - ( x2 * y * y ) ); // 2nd iteration, this can be removed
  return y;
}

int	key_event(int key, t_rt *rpt)
{
  if (key == K_ESC)
    exit (0);
  return (0);
}

int	print_i(t_par *ppt)
{
  mlx_put_image_to_window(ppt->mlx_ptr, ppt->win_ptr, ppt->img_ptr, 0 , 0);
  return (0);
}

int	creat_win(t_rt *rpt, t_par *ppt)
{
  if ((ppt->mlx_ptr = mlx_init()) == NULL)
    return (merror("Couldn't init mlx\n", -1));
  ppt->win_ptr =  mlx_new_window(ppt->mlx_ptr, WINX, WINY, " rtv1 ");
  ppt->img_ptr = mlx_new_image(ppt->mlx_ptr, WINX, WINY);
  ppt->data = mlx_get_data_addr(ppt->img_ptr,
				&ppt->bpp, &ppt->sizeline, &ppt->endian);
  return (0);
}

int		main(int ac, char **av)
{
  t_rt		rpt;
  t_par		ppt;
  t_vec		vpt;
  t_cam		cpt;
  /* int		i; */
  /* int		x; */

  rpt.vpt = &vpt;
  rpt.cpt = &cpt;
  if (ac == 1)
    return (merror("You need to specifie a config file in argument\n", -1));
  if (pars(&rpt, av[1]) < 0 || creat_win(&rpt, &ppt) == -1)
    return (-1);
  init_cos(rpt.obj);
  /* for(i=0;rpt.obj[i].type != -1;i++) */
  /*   { */
  /*     for(x=0;x<3;x++) */
  /* 	printf("pos: %f\n", rpt.obj[i].pos[x]); */
  /*   } */
  calc_pixel(&rpt, &cpt, &vpt, &ppt);
  /* exit(0); */
  mlx_key_hook(ppt.win_ptr, key_event, &rpt);
  mlx_expose_hook(ppt.win_ptr, print_i, &ppt);
  mlx_key_hook(ppt.win_ptr, key_event, &rpt);
  mlx_loop(ppt.mlx_ptr);
  return (0);
}