#include <stdio.h>
#include <math.h>
int N;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3){
    return (x1*y2+ x2*y3 + x3* y1) - (y1*x2 + y2*x3 + y3*x1);
}

double gerAreaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3){
    return 0.5 * ccw(x1,y1,x2,y2,x3,y3);
}
int main() {
    int N;
    scanf("%d",&N);
    int x[3];
    int y[3];
    
    scanf("%d %d",&x[2], &y[2]);
    int k=0;
    double sum=0;
    scanf("%d %d",&x[k],&y[k]);
    k=(k+1)%2;
    for(int i=2;i<N;i++){
        scanf("%d %d",&x[k],&y[k]);
        sum += gerAreaOfTriangle(x[2],y[2],x[k],y[k],x[(k+1)%2],y[(k+1)%2]);
        k = (k+1)%2;
    }
    
    printf("%.1lf",abs(sum));
    return 0;
}
