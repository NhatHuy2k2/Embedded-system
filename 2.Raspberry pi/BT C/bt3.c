#include <stdio.h>
#include <stdlib.h>   // rand()
#include <unistd.h>   // sleep()

int main(void){
    
    while(1){
        float avg = 0;
        for( int i=0; i<10; i++){
            avg = avg + rand()%101;
        }
        avg = avg/10.0;

        printf("\r value= %.2f",avg);
        fflush(stdout);
        sleep(1);
    }
    return 0;
}