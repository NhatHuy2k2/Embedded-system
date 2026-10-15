#include <stdio.h>
#include <unistd.h>
#include <time.h>  // time_t, struct tm, time, localtime 

int main(void){

    while(1){
        FILE *tempfile;
        float temp;
        tempfile = fopen("/sys/class/thermal/thermal_zone0/temp","r");
        fscanf(tempfile, "%f",&temp);
        temp = temp / 1000;
        fclose(tempfile);

        time_t rawtime;
        struct tm *ct;

        time (&rawtime);
        ct = localtime (&rawtime);
        // dd/mm/yyyy hh:mm:ss temp
        printf ("\r %02d/%02d/%04d %02d:%02d:%02d %.2f", ct->tm_mday,ct->tm_mon+1,ct->tm_year+1900,ct->tm_hour,ct->tm_min,ct->tm_sec, temp);
        fflush(stdout);
        sleep(1);
    }

    return 0;
}