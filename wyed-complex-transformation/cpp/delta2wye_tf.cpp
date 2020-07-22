// #ifndef complex_num_tf
//     #include "complex_num_tf.cpp"
// #endif
// #ifndef angle_tf
//     #include "angle_tf.cpp"
// #endif
#ifndef cmath
    #include <cmath>
#endif
#ifndef iostream
    #include <iostream>
#endif
using namespace std;

void dispb_d2w(){
    printf("\n ---------------- Zc -----------------");
    printf("\n \\ \\.                             ./ /");
    printf("\n  \\   \\.                       ./   /");
    printf("\n   \\     Z1                 Z2     /");
    printf("\n    \\       \\.           ./       /");
    printf("\n     \\        \\.      ./         /");
    printf("\n      \\          \\  /           /");
    printf("\n       Zb         |           Za");
    printf("\n        \\         |          /");
    printf("\n         \\        Z3        /");
    printf("\n           \\      |       /");
    printf("\n             \\    |     /");
    printf("\n               \\  |   /");
    printf("\n                 \\| /");
}

void dispa_d2w(double Za, double Zb, double Zc,
               double Z1, double Z2, double Z3,
               double THETAa, double THETAb, double THETAc,
               double THETA1, double THETA2, double THETA3
               ){
    printf("\n\n");
    printf(" ------------ %.2f <%.2f ------------\n", Zc, THETAc);
    printf(" \\ \\.                             ./ /\n");
    printf("  \\   \\.                       ./   /\n");
    printf("   \\  %.2f <%.2f     %.2f <%.2f  /\n", Z1, THETA1, Z2, THETA2);
    printf("    \\       \\.           ./       /\n");
    printf("     \\        \\.      ./         /\n");
    printf("      \\          \\  /           /\n");
    printf("  %.2f <%.2f      |      %.2f <%.2f\n", Zb, THETAb, Za, THETAa);
    printf("        \\         |          /\n");
    printf("         \\    %.2f <%.2f   /\n", Z3, THETA3);
    printf("           \\      |       /\n");
    printf("             \\    |     /\n");
    printf("               \\  |   /\n");
    printf("                 \\| /\n");
}

void delta2wye(){

    // input data
    double Ra, Xa, Za, THETAa,
           Rb, Xb, Zb, THETAb,
           Rc, Xc, Zc, THETAc;
    double R1, X1, Z1, THETA1,
           R2, X2, Z2, THETA2,
           R3, X3, Z3, THETA3;

    dispb_d2w();
    cout << endl;

    // Za
    cout << "Ra = ";
    cin >> Ra;
    cout << "Xa = ";
    cin >> Xa;
    cout << "Za = ";
    cin >> Za;
    cout << "THETAa = ";
    cin >> THETAa;

    cout << endl;
    // Zb
    cout << "Rb = ";
    cin >> Rb;
    cout << "Xb = ";
    cin >> Xb;
    cout << "Zb = ";
    cin >> Zb;
    cout << "THETab = ";
    cin >> THETAb;

    cout << endl;
    // Zc
    cout << "Rc = ";
    cin >> Rc;
    cout << "Xc = ";
    cin >> Xc;
    cout << "Zc = ";
    cin >> Zc;
    cout << "THETAc = ";
    cin >> THETAc;

    // perhitungan
    // inisialisasi
    complex_tf(Ra, Xa, Za, THETAa);
    complex_tf(Rb, Xb, Zb, THETAb);
    complex_tf(Rc, Xc, Zc, THETAc);
    
    cout << endl;
    // eksekusi
    // Z1
    printf("Mencari Z1 :\n\n");
    Z1 = (Zb*Zc)/(sqrt((Ra+Rb+Rc)*(Ra+Rb+Rc) + (Xa+Xb+Xc)*(Xa+Xb+Xc)));
    THETA1 = THETAb + THETAc - rad2deg(atan((Xa+Xb+Xc)/(Ra+Rb+Rc)));
    printf("         Zb * Zc\n");
    printf("Z1 = -----------------\n");
    printf("     Za + Zb + Zc\n");
    printf("\n");
    // printf("         Zb <THETAb * Zc <THETAc\n");
    // printf("Z1 = ---------------------------------\n");
    // printf("     (Ra + Xa) + (Rb + Xb) + (Rc + Xc)\n");
    printf("\n");
    printf("                  %.2f <%.2f * %.2f <%.2f\n", Zb, THETAb, Zc, THETAc);
    printf("Z1 = ----------------------------------------------------\n");
    printf("     (%.2f + j%.2f) + (%.2f + j%.2f) + (%.2f + j%.2f)\n", Ra, Xa, Rb, Xb, Rc, Xc);
    printf("\n");
    printf("      %.2f <%.2f * %.2f <%.2f\n", Zb, THETAb, Zc, THETAc);
    printf("Z1 = ----------------------------\n");
    printf("           (%.2f + j%.2f)\n", Ra+Rb+Rc, Xa+Xb+Xc);
    printf("\n");
    printf("      %.2f <%.2f * %.2f <%.2f\n", Zb, THETAb, Zc, THETAc);
    printf("Z1 = ----------------------------\n");
    printf("           %.2f <%.2f\n", (sqrt((Ra+Rb+Rc)*(Ra+Rb+Rc) + (Xa+Xb+Xc)*(Xa+Xb+Xc))), rad2deg(atan((Xa+Xb+Xc)/(Ra+Rb+Rc))));
    printf("\n");
    printf("Z1 = %.2f <%.2f\n", Z1, THETA1);
    printf("Z1 = %.2f + j%.2f\n", Z1*cos(deg2rad(THETA1)), (Z1*sin(deg2rad(THETA1))));
    
    printf("\n============================================================\n\n");
    
    // Z2
    printf("Mencari Z2 :\n\n");
    Z2 = (Za*Zc)/(sqrt((Ra+Rb+Rc)*(Ra+Rb+Rc) + (Xa+Xb+Xc)*(Xa+Xb+Xc)));
    THETA2 = THETAa + THETAc - rad2deg(atan((Xa+Xb+Xc)/(Ra+Rb+Rc)));
    printf("         Za * Zc\n");
    printf("Z2 = -----------------\n");
    printf("     Za + Zb + Zc\n");
    printf("\n");
    // printf("         Za <THETAa * Zc <THETAc\n");
    // printf("Z2 = ---------------------------------\n");
    // printf("     (Ra + Xa) + (Rb + Xb) + (Rc + Xc)\n");
    printf("\n");
    printf("                  %.2f <%.2f * %.2f <%.2f\n", Za, THETAa, Zc, THETAc);
    printf("Z2 = ----------------------------------------------------\n");
    printf("     (%.2f + j%.2f) + (%.2f + j%.2f) + (%.2f + j%.2f)\n", Ra, Xa, Rb, Xb, Rc, Xc);
    printf("\n");
    printf("      %.2f <%.2f * %.2f <%.2f\n", Za, THETAa, Zc, THETAc);
    printf("Z2 = ----------------------------\n");
    printf("           (%.2f + j%.2f)\n", Ra+Rb+Rc, Xa+Xb+Xc);
    printf("\n");
    printf("      %.2f <%.2f * %.2f <%.2f\n", Za, THETAa, Zc, THETAc);
    printf("Z2 = ----------------------------\n");
    printf("           %.2f <%.2f\n", (sqrt((Ra+Rb+Rc)*(Ra+Rb+Rc) + (Xa+Xb+Xc)*(Xa+Xb+Xc))), rad2deg(atan((Xa+Xb+Xc)/(Ra+Rb+Rc))));
    printf("\n");
    printf("Z2 = %.2f <%.2f\n", Z2, THETA2);
    printf("Z1 = %.2f + j%.2f\n", Z2*cos(deg2rad(THETA2)), (Z2*sin(deg2rad(THETA2))));
    
    printf("\n============================================================\n\n");
    
    // Z3
    printf("Mencari Z3 :\n\n");
    Z3 = (Za*Zb)/(sqrt((Ra+Rb+Rc)*(Ra+Rb+Rc) + (Xa+Xb+Xc)*(Xa+Xb+Xc)));
    THETA3 = THETAb + THETAc - rad2deg(atan((Xa+Xb+Xc)/(Ra+Rb+Rc)));
    printf("         Za * Zb\n");
    printf("Z3 = -----------------\n");
    printf("     Za + Zb + Zc\n");
    printf("\n");
    // printf("         Za <THETAa * Zb <THETAb\n");
    // printf("Z3 = ---------------------------------\n");
    // printf("     (Ra + Xa) + (Rb + Xb) + (Rc + Xc)\n");
    printf("\n");
    printf("                  %.2f <%.2f * %.2f <%.2f\n", Za, THETAa, Zb, THETAb);
    printf("Z3 = ----------------------------------------------------\n");
    printf("     (%.2f + j%.2f) + (%.2f + j%.2f) + (%.2f + j%.2f)\n", Ra, Xa, Rb, Xb, Rc, Xc);
    printf("\n");
    printf("      %.2f <%.2f * %.2f <%.2f\n", Za, THETAa, Zb, THETAb);
    printf("Z3 = ----------------------------\n");
    printf("           (%.2f + j%.2f)\n", Ra+Rb+Rc, Xa+Xb+Xc);
    printf("\n");
    printf("      %.2f <%.2f * %.2f <%.2f\n", Za, THETAa, Zb, THETAb);
    printf("Z3 = ----------------------------\n");
    printf("           %.2f <%.2f\n", (sqrt((Ra+Rb+Rc)*(Ra+Rb+Rc) + (Xa+Xb+Xc)*(Xa+Xb+Xc))), rad2deg(atan((Xa+Xb+Xc)/(Ra+Rb+Rc))));
    printf("\n");
    printf("Z3 = %.2f <%.2f\n", Z3, THETA3);
    printf("Z3 = %.2f + j%.2f\n", Z3*cos(deg2rad(THETA3)), (Z3*sin(deg2rad(THETA3))));
    printf("\n");
        
    dispa_d2w(Za, Zb, Zc, Z1, Z2, Z3, THETAa, THETAb, THETAc, THETA1, THETA2, THETA3);
}
