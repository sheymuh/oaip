#include <stdio.h>

// ÇÀÄÀ×À 1
//void main()
//{
//    int n;
//    int i;
//    printf("n = ");
//    scanf_s("%d", &n);
//
//    i = 0;
//    do {
//        printf("%d ", i);
//        i++;
//    } while (i <= n);
//}

//ÇÀÄÀ×À 2
//void main()
//{
//    int i;
//    int stpn;
//
//    stpn = 1;
//    i = 0;
//    do {
//        printf("2^%d = %d\n", i, stpn);
//        i++;
//        stpn *= 2;
//        
//    } while (i != 6);
//}

//ÇÀÄÀ×À 4
//void main()
//{
//    int n;
//    int x;
//    printf("n = ");
//    scanf_s("%d", &n);
//
//    x = 2;
//    do {
//        printf("%d ", x);
//        x += 2;
//        n -= 1;
//    } while (n != 0);
//}

//ÇÀÄÀ×À 5
void main()
{
    int n;
    int a;
    int i;

    printf("n = ");
    scanf_s("%d", &n);
    printf("a = ");
    scanf_s("%d", &a);
    i = a;

    do {
        printf("%d ", i);
        i += a;
        n -= 1;
    } while (n != 0);
}