#include <iostream>

#include<time.h>
#include<fstream>

using namespace std;


time_t now_time;
struct tm Tm;
tm *pTm;

int main(int argc,char **argv)
{
    
	now_time = time(NULL);
	localtime_s(&Tm, &now_time);
	pTm = &Tm;


	if (argc < 2) {
		cout << "CONFIG ERROR...\n";

	
		return 0;
	}

	const char *fcachename = "BuildCountTime.txt";

	
	

	if (argc >1) {
		if (strcmp(argv[1], "start") == 0) {
			cout << "------------------------------START------------------------------" << endl;
		
			char buf[255] = { 0 };
			sprintf_s(buf,255,"%s:\t%04d-%02d-%02d %02d:%02d:%02d\n", argv[1], pTm->tm_year + 1900, pTm->tm_mon + 1, pTm->tm_mday, pTm->tm_hour, pTm->tm_min, pTm->tm_sec);
			
			cout << buf;


			FILE *pFile = NULL;
			fopen_s(&pFile, fcachename, "w+");

			fputs(buf, pFile);

			fclose(pFile);

		}
		else if(strcmp(argv[1], "stop") == 0){
			FILE *pFile = NULL;
			fopen_s(&pFile, fcachename, "r");

			char buf[255] = { 0 };
			
			fgets(buf, 255, pFile);

			cout << buf;

			printf("%s:\t%04d-%02d-%02d %02d:%02d:%02d\n", argv[1],pTm->tm_year + 1900, pTm->tm_mon + 1, pTm->tm_mday, pTm->tm_hour, pTm->tm_min, pTm->tm_sec);
			cout << "------------------------------STOP------------------------------" << endl;
			fclose(pFile);
			remove(fcachename);


		}
		else {
		
			printf("%s:\t%04d-%02d-%02d %02d:%02d:%02d\n", argv[1], pTm->tm_year + 1900, pTm->tm_mon + 1, pTm->tm_mday, pTm->tm_hour, pTm->tm_min, pTm->tm_sec);

		}
	}

	return 0;


}