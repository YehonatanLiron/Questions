#include <stdio.h>

#define DEBUG_PRINTS    (0)

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int quick_find(int *a, int pivot, int len)
{
    swap(&a[0], &a[pivot]);

    int pivot_val = a[0];

#if DEBUG_PRINTS == 1
    printf("sort around %d\n", pivot_val);

    printf("before sort pass:\n");
    for (int i=0; i < len; i++) printf("%d ", a[i]);
    printf("\n");
#endif

    int i = 0;
    int j = 1;

    /*
    [pivot] [partitioned] [unpartitioned]
    [pivot] [ <p ][ >p  ] [             ]
	   ↑         ↑        ↑
       0         i        j
    */

    for (j = 1; j < len; j++)
    {
        if (a[j] < pivot_val)
        {
            i++;
            swap(&a[j], &a[i]);
        }
    }

    /*
    After sorting pass this is the layout:
    [pivot] [     <p    ] [      >p     ]
       ↑                ↑ 
       0                i

    A swap shall put the pivot right in the i spot between the two groups.
       
       /-----swap-------\
	   ↓                ↓
    [pivot] [     <p    ] [      >p     ]
	                    ↑                
                        i               
    */
    swap(&a[0], &a[i]);



#if DEBUG_PRINTS == 1
    printf("after sort pass:\n");
    for (int i=0; i < len; i++) printf("%d ", a[i]);
    printf("\n");
#endif

    /*
    [     <p    ] [pivot] [      >p     ]
                     ↑    ↑
			         i    i+1       
    */
    if (i > pivot) {

        return quick_find(a, pivot, i);
    }

    if (i < pivot) return quick_find(&a[i + 1], pivot - i - 1, len - i - 1);

    /* if (i == pivot) */
    return pivot_val;
}

int main(void)
{
    int array[] = {10,1,2,7,9,11,18,-9,13,17,82,45,-6,0,22,16};

    int length = sizeof(array) / sizeof(array[0]);

    int N;

    printf("Choose N between 0 to %d\n", length - 1);

    scanf("%d", &N);

    printf("Chose %d\n",N);

    int nth = quick_find(array, N, length);

    printf("Nth is %d\n", nth);

    return 0;
}
