#include <stdio.h>
#include <rpc/rpc.h>
#include "remtime.h"
#define SERVER "localhost"
int main(void)
{
CLIENT *client;
datestr *resstring;
/* client handle - required */
/* pointer to a datestr to hold
result */
client = clnt_create(SERVER, REMTIMEPROG, REMTIMEVERS, "tcp");
/* create a client handle to the specified server, program, version
using the specified protocol */
if (client == NULL)
{
printf("Cannot connect to server\n");
clnt_pcreateerror(SERVER);
/* find out why - prints to stdout */
exit(1);
}
resstring = getdatestr_1(NULL, client);
/* as our function receives no arguments our first
argument is a pointer to void, the second a pointer
to the client handle we wish to use We should really
error check the return! */
printf("%s",*resstring);
return(0);
}
