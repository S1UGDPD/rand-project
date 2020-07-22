// #include "angle_tf.cpp"
#ifndef cmath
    #include <cmath>
#endif
#ifndef iostream
    #include <iostream>
#endif

using namespace std;

void display(double R, double X, double Z, double THETA){

    printf("\n          ______");
    printf("\n  -------|______|-------");
    printf("\npolar       : %.2f <%.2f", Z, THETA);
    if (X < 0){
        printf("\nrectangular : %.2f - j%.2f\n", R, -X);
    } else {
        printf("\nrectangular : %.2f + j%.2f\n", R, X);
    }
    cout << endl;
}

void polar2rectangular(double Z, double THETA){

    double R = Z*cos(deg2rad(THETA));
    double X = Z*sin(deg2rad(THETA));

    cout << endl;

    cout << "Polar to Rectangular\n";
    if (X < 0){
        printf("%.2f <%.2f = %.2f - j%.2f", Z, THETA, R, -X);
    } else {
        printf("%.2f <%.2f = %.2f + j%.2f", Z, THETA, R, X);
    }
    display(R, X, Z, THETA);

    char show;
    cout << "Tampilkan perhitungan? (Y/N): ";
    cin >> show;
    if (show == 'Y' | show == 'y'){
        printf("R = Z*cos(THETA)\n");
        printf("R = %.2f*cos(%.2f)\n", Z, THETA);
        printf("R = %.2f\n", R);

        cout << endl;

        printf("X = Z*sin(THETA)\n");
        printf("X = %.2f*sin(%.2f)\n", Z, THETA);
        printf("X = %.2f\n", X);
    } else if (show == 'N' | show == 'n'){
        
    }

}

void rectangular2polar(double R, double X){

    double Z = sqrt((R*R) + (X*X));
    double THETA = rad2deg(atan(X/R));
    
    cout << endl;

    cout << "Rectangular to Polar\n";
    if (X < 0){
        printf("%.2f - j%.2f = %.2f <%.2f", R, -X, Z, THETA);
    } else {
        printf("%.2f + j%.2f = %.2f <%.2f", R, X, Z, THETA);
    }
    
    display(R, X, Z, THETA);

    char show;
    cout << "Tampilkan perhitungan? (Y/N): ";
    cin >> show;
    if (show == 'Y' | show == 'y'){
        printf("Z = [(R)^2 + (X)^2]\n");
        printf("Z = [(%.2f)^2 + (%.2f)^2]\n", R, X);
        printf("Z = %.2f\n", Z);
        
        cout << endl;

        printf("THETA = arc.tan(X / R)\n");
        printf("THETA = arc.tan(%.2f / %.2f)\n", X, R);
        printf("THETA = %.2f\n", THETA);
    } else if (show == 'N' | show == 'n'){
        
    }
}

void complex_tf(double R, double X, double Z, double THETA){
    // double R, X, Z, THETA;
    // cout << "R = ";
    // cin >> R;
    // cout << "X = ";
    // cin >> X;
    // cout << "Z = ";
    // cin >> Z;
    // cout << "THETA = ";
    // cin >> THETA;

    if (Z == 0 && THETA == 0){
        rectangular2polar(R, X);
    } else if (R == 0 && X == 0){
        polar2rectangular(Z, THETA);
    }
}