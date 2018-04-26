#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "termcolor.hpp"

using namespace std;

void output(){

}

int main(int arg, char** argv){

    cout << "Art width: ";
    double  w;
    cin >> w;
    //cout << endl;

    cout << "Art height: ";
    double h;
    cin >> h;
    //cout << endl;

    vector< vector<double> > sheetSizes = { {23.0, 17.5}, {25.0, 19.0}, {29.0, 23.0} };


    for ( auto sheet : sheetSizes ){
        double bleed = 0.25;
        double smBleed = .125;
        double gripper = .375;
        double sheetW = sheet[0];
        double sheetH = sheet[1];
        int xP =  sheetW  / ( w + bleed );
        int yP = ( sheetH - gripper )/ ( h + bleed );
        int xL = sheetW  / (h + bleed);
        int yL = (sheetH - gripper ) / ( w + bleed );
        int xPsm = sheetW  / (w + smBleed);
        int yPsm = ( sheetH - gripper ) / (h + smBleed);
        int xLsm =  sheetW  / (h + smBleed);
        int yLsm = ( sheetH - gripper ) / (w + smBleed);
        int xPBust = sheetW / (w);
        int yPBust = (sheetH - gripper) / (h);
        int xLBust = sheetW / (h);
        int yLBust = (sheetH - gripper) / (w);

        cout << endl;
        cout << termcolor::yellow << sheetW << "x" << sheetH << termcolor::white << endl;
        cout   << "Portrait \t"<< "X: " << xP << " \t Y: " << yP << " \t NUP " << xP * yP << endl;
        cout   << "Landscape  \t" << "X: "<< xL << "\t Y: " << yL << " \t NUP " << xL * yL << endl;
        cout << "Portrait \t" << "X: " << xPsm << " \t Y: " << yPsm << " \t NUP " << xPsm * yPsm << termcolor::red << " SM Bleed" << termcolor::white << endl;
        cout << "Landscape  \t" << "X: " << xLsm << "\t Y: " << yLsm << " \t NUP " << xLsm * yLsm << termcolor::red << " SM Bleed" << termcolor::white << endl;
        cout << "Portrait \t"
             << "X: " << xPBust << " \t Y: " << yPBust << " \t NUP " << xPBust * yPBust << termcolor::red << " Bust Cut" << termcolor::white << endl;
        cout << "Landscape  \t"
             << "X: " << xLBust << "\t Y: " << yLBust << " \t NUP " << xLBust * yLBust << termcolor::red << " Bust Cut" << termcolor::white;
        cout  << endl << endl << termcolor::reset;
    }


    return cin.get();
}
