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

void dispb_w2d(){
    printf("\n ---------------- Z3 -----------------");
    printf("\n \\ \\.                             ./ /");
    printf("\n  \\   \\.                       ./   /");
    printf("\n   \\     Za                 Zb     /");
    printf("\n    \\       \\.           ./       /");
    printf("\n     \\        \\.      ./         /");
    printf("\n      \\          \\  /           /");
    printf("\n       Z2         |           Z1");
    printf("\n        \\         |          /");
    printf("\n         \\        Zc        /");
    printf("\n           \\      |       /");
    printf("\n             \\    |     /");
    printf("\n               \\  |   /");
    printf("\n                 \\| /");
}

void dispa_w2d(double Za, double Zb, double Zc,
               double Z1, double Z2, double Z3,
               double THETAa, double THETAb, double THETAc,
               double THETA1, double THETA2, double THETA3
               ){
    printf("\n\n");
    printf(" ----------- %.2f <%.2f--------------\n", Z3, THETA3);
    printf(" \\ \\.                             ./ /\n");
    printf("  \\   \\.                       ./   /\n");
    printf("   \\  %.2f <%.2f      %.2f <%.2f  /\n", Za, THETAa, Zb, THETAb);
    printf("    \\       \\.           ./       /\n");
    printf("     \\        \\.      ./         /\n");
    printf("      \\          \\  /           /\n");
    printf("  %.2f <%.2f     |     %.2f <%.2f\n", Z2, THETA2, Z1, THETA1);
    printf("        \\         |          /\n");
    printf("         \\    %.2f <%.2f   /\n", Zc, THETAc);
    printf("           \\      |       /\n");
    printf("             \\    |     /\n");
    printf("               \\  |   /\n");
    printf("                 \\| /\n");
}

void wye2delta(){

    // input data
    double Ra, Xa, Za, THETAa,
           Rb, Xb, Zb, THETAb,
           Rc, Xc, Zc, THETAc;
    double R1, X1, Z1, THETA1,
           R2, X2, Z2, THETA2,
           R3, X3, Z3, THETA3;
    double a, b, c, d, e, f, g, h;

    dispb_w2d();
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
    printf("      (Za*Zb) + (Zb*Zc) + (Zc*Za)\n");
    printf("Z1 = -----------------------------\n");
    printf("                  Za\n");
    printf("\n");
    printf("      (%.2f <%.2f * %.2f <%.2f) + (%.2f <%.2f * %.2f <%.2f) + (%.2f <%.2f * %.2f <%.2f)\n", Za, THETAa, Zb, THETAb, Zb, THETAb, Zc, THETAc, Zc, THETAc, Za, THETAa);
    printf("Z1 = -----------------------------------------------------------------------------------------\n");
    printf("                                             %.2f <%.2f\n", Za, THETAa);
    printf("\n");
    printf("      (%.2f <%.2f) + (%.2f <%.2f) + (%.2f <%.2f)\n", Za*Zb, THETAa+THETAb, Zb*Zc, THETAb+THETAc, Zc*Za, THETAc+THETAa);
    printf("Z1 = ----------------------------------------------------\n");
    printf("                          %.2f <%.2f\n", Za, THETAa);
    printf("\n");
    a = Za*Zb*cos(deg2rad(THETAa+THETAb));
    b = Za*Zb*sin(deg2rad(THETAa+THETAb));
    c = Zb*Zc*cos(deg2rad(THETAb+THETAc));
    d = Zb*Zc*sin(deg2rad(THETAb+THETAc));
    e = Zc*Za*cos(deg2rad(THETAc+THETAa));
    f = Zc*Za*sin(deg2rad(THETAc+THETAa));
    printf("      (%.2f + j%.2f) + (%.2f + j%.2f) + (%.2f + j%.2f)\n", a, b, c, d, e, f);
    printf("Z1 = ------------------------------------------------------------\n");
    printf("                              %.2f <%.2f\n", Za, THETAa);
    printf("\n");
    printf("      %.2f + j%.2f\n", a+c+e, b+d+f);
    printf("Z1 = -----------------\n");
    printf("        %.2f <%.2f\n", Za, THETAa);
    printf("\n");
    g = sqrt((a+c+e)*(a+c+e) + (b+d+f)*(b+d+f));
    h = rad2deg(atan((b+d+f)/(a+c+e)));
    printf("      %.2f <%.2f\n", g, h);
    printf("Z1 = ---------------\n");
    printf("       %.2f <%.2f\n", Za, THETAa);
    printf("\n");
    
    Z1 = g/Za;
    THETA1 = h-THETAa;
    printf("Z1 = %.2f <%.2f\n", Z1, THETA1);
    printf("Z1 = %.2f + j%.2f\n", Z1*cos(deg2rad(THETA1)), (Z1*sin(deg2rad(THETA1))));
    
    printf("\n============================================================\n\n");
    
    // Z2
    printf("Mencari Z2 :\n\n");
    printf("      (Za*Zb) + (Zb*Zc) + (Zc*Za)\n");
    printf("Z2 = -----------------------------\n");
    printf("                  Zb\n");
    printf("\n");
    printf("      (%.2f <%.2f * %.2f <%.2f) + (%.2f <%.2f * %.2f <%.2f) + (%.2f <%.2f * %.2f <%.2f)\n", Za, THETAa, Zb, THETAb, Zb, THETAb, Zc, THETAc, Zc, THETAc, Za, THETAa);
    printf("Z2 = -----------------------------------------------------------------------------------------\n");
    printf("                                             %.2f <%.2f\n", Zb, THETAb);
    printf("\n");
    printf("      (%.2f <%.2f) + (%.2f <%.2f) + (%.2f <%.2f)\n", Za*Zb, THETAa+THETAb, Zb*Zc, THETAb+THETAc, Zc*Za, THETAc+THETAa);
    printf("Z2 = ----------------------------------------------------\n");
    printf("                          %.2f <%.2f\n", Zb, THETAb);
    printf("\n");
    a = Za*Zb*cos(deg2rad(THETAa+THETAb));
    b = Za*Zb*sin(deg2rad(THETAa+THETAb));
    c = Zb*Zc*cos(deg2rad(THETAb+THETAc));
    d = Zb*Zc*sin(deg2rad(THETAb+THETAc));
    e = Zc*Za*cos(deg2rad(THETAc+THETAa));
    f = Zc*Za*sin(deg2rad(THETAc+THETAa));
    printf("      (%.2f + j%.2f) + (%.2f + j%.2f) + (%.2f + j%.2f)\n", a, b, c, d, e, f);
    printf("Z2 = ------------------------------------------------------------\n");
    printf("                              %.2f <%.2f\n", Zb, THETAb);
    printf("\n");
    printf("      %.2f + j%.2f\n", a+c+e, b+d+f);
    printf("Z2 = -----------------\n");
    printf("        %.2f <%.2f\n", Zb, THETAb);
    printf("\n");
    g = sqrt((a+c+e)*(a+c+e) + (b+d+f)*(b+d+f));
    h = rad2deg(atan((b+d+f)/(a+c+e)));
    printf("      %.2f <%.2f\n", g, h);
    printf("Z2 = ---------------\n");
    printf("       %.2f <%.2f\n", Zb, THETAb);
    printf("\n");
    
    Z2 = g/Zb;
    THETA2 = h-THETAb;
    printf("Z2 = %.2f <%.2f\n", Z2, THETA2);
    printf("Z2 = %.2f + j%.2f\n", Z2*cos(deg2rad(THETA2)), (Z2*sin(deg2rad(THETA2))));

    printf("\n============================================================\n\n");
    
    // Z3
    printf("Mencari Z3 :\n\n");
    printf("      (Za*Zb) + (Zb*Zc) + (Zc*Za)\n");
    printf("Z3 = -----------------------------\n");
    printf("                  Zc\n");
    printf("\n");
    printf("      (%.2f <%.2f * %.2f <%.2f) + (%.2f <%.2f * %.2f <%.2f) + (%.2f <%.2f * %.2f <%.2f)\n", Za, THETAa, Zb, THETAb, Zb, THETAb, Zc, THETAc, Zc, THETAc, Za, THETAa);
    printf("Z3 = -----------------------------------------------------------------------------------------\n");
    printf("                                             %.2f <%.2f\n", Zc, THETAc);
    printf("\n");
    printf("      (%.2f <%.2f) + (%.2f <%.2f) + (%.2f <%.2f)\n", Za*Zb, THETAa+THETAb, Zb*Zc, THETAb+THETAc, Zc*Za, THETAc+THETAa);
    printf("Z3 = ----------------------------------------------------\n");
    printf("                          %.2f <%.2f\n", Zc, THETAc);
    printf("\n");
    a = Za*Zb*cos(deg2rad(THETAa+THETAb));
    b = Za*Zb*sin(deg2rad(THETAa+THETAb));
    c = Zb*Zc*cos(deg2rad(THETAb+THETAc));
    d = Zb*Zc*sin(deg2rad(THETAb+THETAc));
    e = Zc*Za*cos(deg2rad(THETAc+THETAa));
    f = Zc*Za*sin(deg2rad(THETAc+THETAa));
    printf("      (%.2f + j%.2f) + (%.2f + j%.2f) + (%.2f + j%.2f)\n", a, b, c, d, e, f);
    printf("Z3 = ------------------------------------------------------------\n");
    printf("                              %.2f <%.2f\n", Zc, THETAc);
    printf("\n");
    printf("      %.2f + j%.2f\n", a+c+e, b+d+f);
    printf("Z3 = -----------------\n");
    printf("        %.2f <%.2f\n", Zc, THETAc);
    printf("\n");
    g = sqrt((a+c+e)*(a+c+e) + (b+d+f)*(b+d+f));
    h = rad2deg(atan((b+d+f)/(a+c+e)));
    printf("      %.2f <%.2f\n", g, h);
    printf("Z3 = ---------------\n");
    printf("       %.2f <%.2f\n", Zc, THETAc);
    printf("\n");
    
    Z3 = g/Zc;
    THETA3 = h-THETAc;
    printf("Z3 = %.2f <%.2f\n", Z3, THETA3);
    printf("Z3 = %.2f + j%.2f\n", Z3*cos(deg2rad(THETA3)), (Z3*sin(deg2rad(THETA3))));

    dispa_w2d(Za, Zb, Zc, Z1, Z2, Z3, THETAa, THETAb, THETAc, THETA1, THETA2, THETA3);
}