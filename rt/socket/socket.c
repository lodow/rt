/*
** socket.c for rt in /home/maxime/Bureau/projet/actu/rt/rt/socket
**
** Made by maxime lavandier
** Login   <lavand_m@epitech.net>
**
** Started on  Wed May  8 18:02:08 2013 maxime lavandier
** Last update Wed May  8 18:09:05 2013 maxime lavandier
*/

#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int			sock_server(int port)
{
  struct protoent	*protocol;
  struct sockaddr_in	sockaddr;
  struct sockaddr_in	sock;
  int			fd;
  int			len;

  if ((protocol = getprotobyname("TCP")) == NULL)
    my_perror("error getprotobyname\n");
  if ((fd = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) == -1)
    my_perror("error socket\n");
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(port);
  sockaddr.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (const struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1)
    my_perror("error bind\n");
  if (listen(fd, 1) == -1)
    my_perror("error listen\n");
  len = sizeof(sock);
  if ((fd = accept(fd, (struct sockaddr *)&sock, &len)) == -1)
    my_perror("error accept\n");
  return (fd);
}

int			sock_client(char *ip, int port)
{
  struct protoent	*protocol;
  struct sockaddr_in	sockaddr;
  char			**grille;
  int			fd;

  if ((protocol = getprotobyname("TCP")) == NULL)
    my_perror("error getprotobyname\n");
  if ((fd = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) == -1)
    my_perror("error socket\n");
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(port);
  sockaddr.sin_addr.s_addr = inet_addr(ip);
  if (connect(fd, (const struct sockaddr *)&sockaddr,
	      sizeof(sockaddr)) == -1)
    my_perror("error connect\n");
  return (fd);
}
