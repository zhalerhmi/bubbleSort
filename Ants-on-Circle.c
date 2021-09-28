#include <stdio.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubbleSort(int arr[], int n)
{

    int i, j;

    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int normalPosition(int position, int n)
{

    if (position > n)
    {
        position = 1;
    }
    if (position < 1)
    {

        position = n;
    }
    return position;
}

int main(void)
{

    int n, m, T;

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &T);

    int *x, *y;
    int steps = 1;
    x = malloc(m * sizeof(int));
    y = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {

        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }

    //add up the T steps
    // int position;

    while (steps <= T)
    {
        steps++;
        //take one step for all m ants
        for (int i = 0; i < m; i++)
        {
            
                x[i] = x[i] + y[i];
                x[i] = normalPosition(x[i],  n);
            
        }

        //compare position and change direction if they are at the same place
        int reverse = -1;
        for (int i = 0; i < m; i++)
        {

            for (int j = i + 1; j < m; j++)
            {
                if (x[i] == x[j])
                {
                    y[i] = y[i] * reverse;
                    y[j] = y[j] * reverse;
                }
            }
        }
    }

    bubbleSort(x, m);
    for (int i = 0; i < m; i++)
    {
        printf("%d ", x[i]);
    }

    return 0;
}
