#include <iostream>
#include "angle_tf.cpp"
#include "complex_num_tf.cpp"
#include "delta2wye_tf.cpp"
#include "wye2delta_tf.cpp"

using namespace std;
int getOption();

int main(){
    char lanjut;
    int pilihan = getOption();
    enum pilihan {PtR = 1, RtP, DtW, WtD, QUIT};

    while (pilihan != QUIT){
        
        switch(pilihan){
            case PtR :
                cout << "\n== Polar to Rectangular ==" << endl;
                double Z, THETA;
                cout << "Z = ";
                cin >> Z;
                cout << "THETA = ";
                cin >> THETA;
                polar2rectangular(Z, THETA);
                break;
            case RtP :
                cout << "\n== Rectangular to Polar ==" << endl;
                double R, X;
                cout << "R = ";
                cin >> R;
                cout << "X = ";
                cin >> X;
                rectangular2polar(R, X);
                break;
            case DtW :
                cout << "\n== Delta to Wye ==" << endl;
                delta2wye();
                break;
            case WtD :
                cout << "\n== Wye to Delta ==" << endl;
                wye2delta();
                break;
            default :
                cout << "Pilihan tidak ditemukan!";
                break;
        }
        _checkpoint_ :
        
        cout << "\nLanjutkan? (Y/N): ";
        cin >> lanjut;
        if (lanjut == 'Y' | lanjut == 'y'){
            pilihan = getOption();
        } else if (lanjut == 'N' | lanjut == 'n'){
            break;
        } else {
            goto _checkpoint_;
        }
    }

    return 0;
}

int getOption(){
    
    int input;
    system("cls");
    
    cout << "[1] Polar to Rectangular" << endl;
    cout << "[2] Rectangular to Polar" << endl;
    cout << "[3] Delta to Wye" << endl;
    cout << "[4] Wye to Delta" << endl;
    cout << "[5] Keluar" << endl;

    cout << "\nMasukkan Pilihan: ";
    cin >> input;

    return input;
}
