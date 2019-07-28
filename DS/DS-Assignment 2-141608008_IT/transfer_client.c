
#include "transfer.h"
#include <time.h>


void
transfer_1(char *host, char *filetotransf)
{
	CLIENT *clnt;
	int  *result_1;
	file  transf_1_arg;
	FILE *ofile;
	long long int total = 0;

	clnt = clnt_create (host, TRANSFER, TRANSFER_1, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	ofile = fopen(filetotransf, "rb");

	if(ofile == NULL) {
		printf("File not found.\n");
		exit(1);
	}

	printf("Sending file %s.\n", filetotransf);

	strcpy(transf_1_arg.name, filetotransf);

	clock_t begin = clock();

	while(1) {
		transf_1_arg.nbytes = fread(transf_1_arg.data, 1, MAXLEN, ofile);
		total += transf_1_arg.nbytes;

		//printf("\r%lld bytes of %s sent to server.", total, transf_1_arg.name);

		result_1 = transf_1(&transf_1_arg, clnt);

		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}

		if(transf_1_arg.nbytes < MAXLEN) {
			printf("\nUpload finished.\n");
			break;
		}
	}

	clock_t end = clock();
	double upload_time = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Upload time: %lf\n", upload_time);

	clnt_destroy (clnt);
	fclose(ofile);

}


int
main (int argc, char *argv[])
{
	char *host;
	char *filetotransf;

	if (argc < 3) {
		printf ("usage: %s <server_host> <file>\n", argv[0]);
		exit (1);
	}

	host = argv[1];
	filetotransf = argv[2];

	transfer_1 (host, filetotransf);
exit (0);
}
