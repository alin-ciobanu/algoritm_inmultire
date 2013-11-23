#include <stdio.h>
#include <stdlib.h>

int inmultire (int x, int y) {

    int dim = 10;
    int *xr = (int *) malloc (dim* sizeof(int));
    int *yr = (int *) malloc (dim* sizeof(int));
    int sum = 0;
    int i = 0;

    xr[0] = x;
    yr[0] = y;

    while (xr[i] != 1) {
        i++;
        if (dim == i) {
            dim *= 2;
            xr = realloc (xr, dim* sizeof(int));
            yr = realloc (yr, dim* sizeof(int));
        }
        xr[i] = xr[i-1] >> 1;
        yr[i] = yr[i-1] << 1;
    }

    int k = 0;
    for (k = 0; k <= i; k++) {
        if (xr[k] % 2 == 1) {
            sum += yr[k];
        }
    }

    return sum;

}

int main () {

    int i;
    int rez;
    int x = 13139, y = 9154;

    rez = inmultire(x, y);

    printf("%d\n", rez);


    return 0;
}
