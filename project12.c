/*
Define a structure to represent a circle in two dimensions. Write a function IntersectCircle(C1, C2) which takes as input two circles as
input, and returns 1 if the circles intersect and 0 otherwise. Two circles are considered to be intersecting if their circumferences
intersect at one or two points. Call the above function from the main program for test inputs.
*/

#include <stdio.h>
#include <math.h>

//defined a structure which is essentially coordinates of a point, here the centre of the circle
typedef struct {
    float x;
    float y;
} centre;

//defined a structure that contains 2 essential parameters to completely define a circle i.e centre, radius
typedef struct {
    centre A;
    float radius;
} circle;

//function that returns 1 if the 2 circles intersects, returns 0 if they do not
int IntersectCircle (circle C1, circle C2)
{
    float distance;
    float var1, var2, radiiSum, radiiDiff;
    
    var1 = pow(((C1.A.x) - (C2.A.x)), 2); //var1 stores (x1 - x2)^2, where x1, x2 are x coords of centres of C1, C2
    var2 = pow(((C1.A.y) - (C2.A.y)), 2); //var2 stores (y1 - y2)^2, where y1, y2 are y coords of centres of C1, C2
    distance = sqrt(var1 + var2);         //distance stores the distance between the centres of C1, C2
    
    radiiSum = C1.radius + C2.radius;
    radiiDiff = fabs (C1.radius - C2.radius);
    
    if (distance > radiiSum) return 0; //when the 2 circles are far apart and do no touch
    if (distance < radiiDiff) return 0; //when the 2 circles are either concentricor one circle completely engulfs the other
    if (distance <= radiiSum) return 1; //when the 2 circles either intersect at 1 or 2 points
}

int main ()
{
    circle C1, C2;
    int result;
        
    //printf, scanf statements to obtain required values of C1, C2
    printf("Type x coordinate of C1: ");
    scanf("%f", &C1.A.x);
    printf("Type y coordinate of C1: ");
    scanf("%f", &C1.A.y);
    printf("Type radius of C1: ");
    scanf("%f", &C1.radius);
        
    printf("Type x coordinate of C2: ");
    scanf("%f", &C2.A.x);
    printf("Type y coordinate of C2: ");
    scanf("%f", &C2.A.y);
    printf("Type radius of C2: ");
    scanf("%f", &C2.radius);
        
    if (C1.A.x == C2.A.x && C1.A.y == C2.A.y && C1.radius == C2.radius) {
        printf("The input for C1 and C2 entered by the user is the same circle.");
    }

    else if (C1.radius <= 0 || C2.radius <= 0) {
        printf("The entered radius values for either C1, C2 or both is negative or zero.");
    }
    
    else {
        result = IntersectCircle (C1, C2); //variable result stores 1 for intersecting circles, 0 otherwise
    
        if (result == 0) printf("The cirlces C1 and C2 DO NOT intersect.");
        if (result == 1) printf("The circles C1 and C2 intersect.");
    }
    return 0;
}