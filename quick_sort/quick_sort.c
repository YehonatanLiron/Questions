#include <stdio.h>

#define DEBUG_PRINTS    (0)

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void quick_sort(int *a, int len)
{
    if ((len == 1) || (len == 0)) return;

    int pivot = len / 2;

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

    quick_sort(a, i);
    quick_sort(&a[i + 1], len - i - 1);

    return;
}

void print_array(int *a, int length)
{
    for (int i = 0; i < length; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
    int array[] = {10,1,2,7,9,11,18,-9,13,17,82,45,-6,0,22,16};

    int length = sizeof(array) / sizeof(array[0]);

    print_array(array, length);

    quick_sort(array, length);

    print_array(array, length);

    return 0;
}