#include <stdio.h>

#define XMAX 1
#define YMAX 1
#define dprintSTRING(expr) printf(#expr " = %s\n", expr)
#define dprintCHAR(expr) printf(#expr " = %c\n", expr)
#define dprintINT(expr) printf(#expr " = %d\n", expr)
#define dprintDOUBLE(expr) printf(#expr " = %g\n", expr)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int, int);
struct point addpoint(struct point p1, struct point p2);
int printrec(struct point p, struct rect r);
struct rect canonrect(struct rect r);
void print_rect(struct rect *temp);

int main(int argc, char const *argv[])
{
    struct rect screen;
    struct point middle;

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                       (screen.pt1.y + screen.pt2.y) / 2);

    dprintINT(printrec(middle, screen));

    struct point origin, *pp;

    origin = makepoint(0, 0);
    pp = &origin;
    printf("origitn is (%d, %d)\n", pp->x, pp->y);

    struct rect rect1;
    rect1.pt1 = makepoint(10, 10);
    rect1.pt2 = makepoint(5, 5);

    rect1 = canonrect(rect1);
    print_rect(&rect1);

    return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* printrect: return 1 if p in r, 0 if not*/
int printrec(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}

void print_rect(struct rect *temp)
{
    printf("pt1: (%d, %d), pt2: (%d, %d)\n", temp->pt1.x, temp->pt1.y,
           temp->pt2.x, temp->pt2.y);
    printf("(%2d, %2d)\t", temp->pt1.x,temp->pt2.y);
    printf("(%2d, %2d)\n", temp->pt2.x,temp->pt2.y);
    printf("(%2d, %2d)\t", temp->pt1.x,temp->pt1.y);
    printf("(%2d, %2d)\n", temp->pt2.x,temp->pt1.y);

}