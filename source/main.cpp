#include "lacze_do_gnuplota.hh"
#include <iostream>
#include <chrono>
#include <thread>
#include "Cuboid.h"

void Display_menu()
{
    std::cout << "\n r-rotate cuboid" << std::endl;
    std::cout << " o-repeat prevoius rotation" << std::endl;
    std::cout << " s-show rotation matrix" << std::endl;
    std::cout << " t-translate cuboid" << std::endl;
    std::cout << " d-display cuboid's vertices" << std::endl;
    std::cout << " c-check length of cuboid's sides" << std::endl;
    std::cout << " m-show menu" << std::endl;
    std::cout << " q-quit" << std::endl;
}

int main()
{
    std::cout << "TEST" << std::endl;

    PzG::LaczeDoGNUPlota Lacze;
    Lacze.DodajNazwePliku("../data/vertices.dat")
        .ZmienSposobRys(PzG::SR_Ciagly)
        .ZmienSzerokosc(2)
        .ZmienKolor(8);
    Lacze.DodajNazwePliku("../data/vertices.dat")
        .ZmienSposobRys(PzG::SR_Punktowy)
        .ZmienSzerokosc(1)
        .ZmienKolor(5);
    Lacze.Inicjalizuj();
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.UstawZakresY(-100, 125);
    Lacze.UstawZakresX(-150, 250);
    Lacze.UstawZakresZ(-125, 125);
    Lacze.UstawSkaleXZ(1, 1.5);

    Matrix3x3 r_matrix1;
    Matrix3x3 r_matrix2;
    Matrix3x3 r_matrix3;
    Cuboid c(0, 0, 0, 50, 50, 50);
    int i = 0;
    c.Write_to_file("../data/vertices.dat", Overwrite);

    // Lacze.Rysuj();
    // std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000));

    // c.Side_length();

    set_Rotation_OX(r_matrix1, 1);
    set_Rotation_OY(r_matrix2, 1);

    r_matrix3 = r_matrix2 * r_matrix1;

    while (i < 360)
    {
        c.Rotation(r_matrix1);
        c.Rotation(r_matrix2);
        c.Write_to_file("../data/vertices.dat", Overwrite);
        std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000 / 60));
        Lacze.Rysuj();
        i++;
    }
    c.Side_length();
    char option = ' ';

    Lacze.Rysuj();
    Display_menu();

    do
    {
        std::cout << "Choice (m-menu):\t";
        std::cin >> option;

        if (option != 'r' && option != 'o' && option != 's' && option != 't' && option != 'd' && option != 'm' && option != 'q' && option != 'c')
        {
            std::cerr << "[ERROR] Invalid menu argument" << std::endl;
            option = ' ';
        }

        switch (option)
        {
        case 'm':
            Display_menu();
            break;
        case 'c':
            c.Side_length();
            break;
        default:
            break;
        }
    } while (option != 'q');
}
