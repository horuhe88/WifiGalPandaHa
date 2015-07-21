#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <ctype.h>

#define ARDUINO_ETH "eth0"
#define TMP_PATH	"/tmp/tmp.tmp"


int main(int argc, char const* argv[])
{
    printf("Hello, World!\n");

    FILE *fp = NULL;
	char cmd[128];
	uint8_t ipb[4];
	printf("getLocalIP");
	sprintf(cmd, "ifconfig %s | egrep \"inet\" | cut -d: -f2- > %s",
			ARDUINO_ETH, TMP_PATH);
	system(cmd);
	if (NULL == (fp = fopen(TMP_PATH, "r"))) {
		printf("can't open handle to %s", TMP_PATH);
		return 1;
	}
	fscanf(fp, "%s", cmd); /* inet */
	fclose(fp);
	printf("my IP=%s", cmd);
	if(isdigit(cmd[0])) {
		sscanf(cmd, "%hhd.%hhd.%hhd.%hhd", &ipb[0], &ipb[1],
				&ipb[2], &ipb[3]);
	} 

    return 0;
}
