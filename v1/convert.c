/**
30<60
60+j50 

14/02/23
 */
 
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>
#include <string.h>

// [commands]
#define QUIT 'q'
#define POLAR 'p'
#define RECTANGLE 'r'
#define CONVERT 'c'

// [operations]
#define ADD '+'
#define SUB '-'
#define MULT '*'
#define DIV '/'
#define RECENT '%'  // recent RESULT


typedef struct po {
    double a;   // amplitude
    double p;   // phase
} Polar;

typedef struct rectangle {
    double x;   // real
    double y;   // imaginary
} Rect;

typedef struct value {
    Polar v_pol;   // polar form
    Rect v_rect; // rectangle form
} Value;


Rect add(rect a, rect b);
Rect sub(rect a, rect b);
Polar mult(polar a, polar b);
Polar div(polar a, polar b);
double toDeg(double rad);
double toRad(double deg);


///////////////////////////////////////////////////////////////////////////////

int main(void) {
    while (1) {
        printf("Enter command: ");
        char command;
        scanf(" %c", &command);

        if (command == QUIT) {break;}

        if (command == CONVERT) {
            char form;
            scanf(" %c", &form);
            double input1, input2;
            scanf(" %lf %lf", &input1, &input2);
            printf("recieved: %.2lf, %.2lf\n", input1, input2);
            Value res;
            if (form == RECTANGLE) {
                res = recToPolar(input1, input2);
            }
            
        }
    }

    while (true) {
        printf("Enter command: ");
        char command;
        scanf("%c", &command);

        val a;
        val b;
        val recent;

        if (command == CONVERT) {
            char form;
            scanf("%c",&form);
            
            if (form == POLAR) {
                scanf(" %lf %lf", &a.v_pol.a, &a.v_pol.p);
                a.v_rect =  polarToRec(a.v_pol.a, a.v_pol.p);

            } else if (form == RECTANGLE) {
                scanf(" %lf %lf", &a.v_rect.r, &a.v_rect.i);
                a.v_pol = rectToPolar(a.v_rect.r, a.v_rect.i);


            } else {
                printf("die \n");
                continue;
            }

            printResult(a);
            continue;
        }



        switch (command) {
            case ADD: add(a, b); break;
            case SUB: sub(a, b); break;
            case MULT: mult(a, b); break;
            case DIV: div(a, b); break;
            default: printf("DIE (not a command)\n"); continue;
        }

        printResult(result);

    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////


Rect polarToRec(double a, double p) {
    rect result;
    result.r = a * cos(toRad(p));
    result.i = a * sin(toRad(p));
    return result;
}

Polar recToPolar(rect value) {
    polar result;
    result.a = sqrt((value.r * value.r) + (value.i * value.i));
    result.p = (r == 0)
        ? -90
        : toDeg(atan(value.i / value.r));
    return result;
}

// rect
Rect add(rect a, rect b) {
    rect result;
    result.r = a.r + b.r;
    result.i = a.i + b.i;
    return result;
}

// rect
Rect sub(rect a, rect b) {
    rect result;
    result.r = a.r - b.r;
    result.i = a.i - b.i;
    return result;
}

// polar
Polar mult(polar a, polar b) {
    polar result;
    result.r = a.a * b.a;
    result.p = a.p + b.p;
    return result;
}

// polar
Polar div(polar a, polar b) {
    polar result;
    result.r = a.a / b.a;
    result.p = a.p - b.p;
    return result;
}

// convert radians to degrees
double toDeg(double rad) {
    return (rad * 180) / M_PI;
}

// convert degrees to radians
double toRad(double deg) {
    return (deg / 180) * M_PI;
}

// print result
void printResult(val result) {
    printf("\n ================= \n");
    printf("Polar: %.2lf < %.2lf\n", result.v_pol.a, result.v_pol.p);

    char sign = result.v_rect.i < 0? '-' : '+';
    double j = result.v_rect.i < 0 ? result.v_rect.i : result.v_rect.i * -1;

    prinf("Rectangular: %.2lf %c j %.2lf\n", result.v_rect.r, sign, j);

    printf("\n ================= \n");

    return;
}
