#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	
    double p, s;
    int * areas = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        
        double a = tr[i].a;
        double b = tr[i].b;
        double c = tr[i].c;

        double p = (a+b+c)/2;
        double s = sqrt((p * (p-a) * (p-b) * (p-c)));
        areas[i] = s;
    }
    
    // printf("\n");
    // for(int i = 0; i < n; i++){
    //     printf("%d: %d\n", i, areas[i]);
    // }
    
    float arHold = 0;
    triangle trHold;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(areas[j-1] > areas[j]){
                // swap areas
                arHold = areas[j];
                areas[j] = areas[j-1];
                areas[j-1] = arHold;
                // swap triangles
                trHold = tr[j];
                tr[j] = tr[j-1];
                tr[j-1] = trHold;
            }
        }
    }
    // printf("\n");
    // for(int i = 0; i < n; i++){
    //     printf("%d: %d\n", i, areas[i]);
    // }
    
    // printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}


// 2 25 26
// 2 24 24
// 23 12 12
// 3 29 30
// 6 19 21
// 23 10 32
// 21 11 14
// 17 15 13
// 62 6 57
// 6 52 56
// 62 4 63
// 9 35 32
// 48 6 48
// 15 23 33
// 21 18 24
// 11 46 54
// 49 9 49
// 53 19 38
// 10 61 65
// 31 45 22
// 46 54 15
// 36 18 41
// 44 17 54
// 39 35 19
// 49 54 14
// 22 35 49
// 32 69 41
// 57 15 57
// 15 66 61
// 48 28 33
// 30 30 42
// 46 47 20
// 56 19 49
// 21 50 44
// 63 35 35
// 65 49 24
// 31 40 63
// 40 27 51
// 31 59 39
// 30 38 46
// 59 59 20
// 57 46 26
// 64 33 42
// 66 66 19
// 60 38 35
// 35 69 43
// 43 32 62
// 36 36 53
// 58 24 54
// 54 31 42
// 52 26 64
// 54 49 28
// 46 35 41
// 67 28 53
// 39 38 46
// 25 63 57
// 45 41 37
// 46 33 60
// 24 66 64
// 62 45 35
// 44 53 36
// 42 38 57
// 36 51 51
// 68 26 68
// 51 38 50
// 41 45 64
// 35 53 65
// 56 43 44
// 52 37 62
// 63 32 67
// 65 47 43
// 57 38 56
// 55 55 43
// 54 46 53
// 41 62 56
// 43 58 67
// 56 52 59
// 51 59 58
// 69 50 61
// 55 66 68
