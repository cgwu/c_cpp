深入理解计算机原理:
Computer Systems: A Programmer's Perspective, 2/E (CS:APP2e)
Randal E. Bryant and David R. O'Hallaron, Carnegie Mellon University

网址：
http://csapp.cs.cmu.edu/public/code.html
http://csapp.cs.cmu.edu/public/students.html

/usr/include/netinet/in.h
IP地址结构：
struct in_addr {
    unsigned int s_addr;    /* Network byte order (big-endian) */
};
h主机字节序转为n网络字节序:
unsigned long int htonl(unsinged long int hostlong);
n网络字节序转为h主机字节序:
unsigned long int ntohl(unsinged long int hostlong);

IP地址和点分10进制字符串地址的转换：
#include <arpa/inet.h>
int inet_aton(const char *cp, struct in_addr *inp); // 成功返回1，出错返回0.
char *inet_ntoa(struct in_addr in); // 指向点分十进制字符串的指针.

/* Generic socket address structure (for connect, bind, and accept) */
struct sockaddr {
    unsigned short sa_family;   /* Protocol family */
    char sa_data[14];   /* Address data. */
};
/* Internet-style socket address structure */
struct sockaddr_in {
    unsigned short sin_family;  /* Address family(always AF_INET) */
    unsigned short sin_port;    /* Port number in network byte order */
    struct in_addr sin_addr;    /* IP address in network byte order */
    unsigned char  sin_zero[8]; /* Pad to sizeof(struct sockaddr) */
};
_in后缀是互联网internet的缩写.
typedef struct sockaddr SA;

