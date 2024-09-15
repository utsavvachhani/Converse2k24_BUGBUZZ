#include<stdio.h>

int main() {
    double angle, radians, sin_val, cos_val, tan_val;
    int repeat;

    printf("How many times would you like to calculate trigonometric values? ");
    scanf("%d", repeat);  // Error 1: Missing & before `repeat`

    for(int i = 0; i <= repeat; i++) {  // Error 2: Off-by-one error in loop (should be i < repeat)
        printf("Enter an angle in degrees: ");
        scanf("%lf", angle);  // Error 3: Missing & before `angle`

        // Convert angle from degrees to radians
        radians = (angle * 3.14159) / 180.0;

        // Calculate trigonometric functions without including math.h
        sin_val = sin(radians);  // Error 4: Requires <math.h>
        cos_val = cos(radians);  // Error 5: Requires <math.h>
        tan_val = tan(radians);  // Error 6: Requires <math.h>

        printf("Sine of %.2f degrees is: %.2f\n", angle, sin_val);
        printf("Cosine of %.2f degrees is: %.2f\n", angle, cos_val);
        printf("Tangent of %.2f degrees is: %.2f\n", angle, tan_val);

        // Error 7: No check for infinite tangent (tan_val could be undefined for some angles).
        if(tan_val > 1000 || tan_val < -1000) {
            printf("Warning: Tangent value is extremely large.\n");
        }
    }

    if(repeat <= 0) {  // Error 8: No validation on `repeat` input, should not allow 0 or negative values
        printf("Error: Invalid number of repetitions.\n");
    }
    
    printf("End of trigonometric calculations.");
    
    return 0;
}
