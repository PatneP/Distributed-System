/* remtime.x
rpc protocol spec for remote time worksheet */
const MAXSTRLEN = 80;
typedef string datestr<MAXSTRLEN>;
/* max length of string */
/* typedef for our ret. val.*/
program REMTIMEPROG
{
version REMTIMEVERS
{
datestr GETDATESTR() = 1;
} = 1;
} = 0x20650609;
