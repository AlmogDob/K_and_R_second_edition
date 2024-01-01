#include <stdio.h>
#include <math.h>

#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define dprintDOUBLE(expr) printf(#expr " = %g\n", expr)

double dist(struct Vector2 point1, struct Vector2 point2);

struct Vector2
{
    int x;
    int y;
};

int main(int argc, char const *argv[])
{
    struct Vector2 origin = {0, 0};
    struct Vector2 point1 = {4, 3};
    struct Vector2 point2 = {5, 4};

    double size_point1 = dist(point1, origin);

    dprintINT(point1.x);
    dprintINT(point1.y);
    dprintDOUBLE(size_point1);

    struct rect
    {
        struct Vector2 pt1;
        struct Vector2 pt2;
    };

    struct rect screen;
    screen.pt1 = point1;
    screen.pt2 = point2;

    double size_screen = dist(screen.pt1, screen.pt2);
    dprintDOUBLE(size_screen);
    dprintDOUBLE(sqrt(2));
    return 0;
}

double dist(struct Vector2 point1, struct Vector2 point2)
{
    return sqrt((point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y));
}