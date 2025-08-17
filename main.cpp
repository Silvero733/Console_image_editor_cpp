#include <iostream>
#include <time.h>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <fstream>

void display_board(int x, int y);
void display_colors();
int border_x(int position_x);
int border_y(int position_y);
void get_char(int position_x, int position_y, int previous_position_x, int previous_position_y, char movement);
void gotoxy(short x, short y);
void make_color(int color, int position_x, int position_y);
void save_to_file();


int World[35][60]{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
    };

int color{0};

int main(){
    int position_x = 6;
    int position_y = 24;
    int previous_position_x = 6;
    int previous_position_y = 24;
    char movement = ' ';

    get_char(position_x, position_y, previous_position_x, previous_position_y, movement);
}

void display_board(int x,int y){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i=0; i<=34; ++i){
        for (int j=0; j<=59; ++j){
            switch (World[i][j]){
                case 0:
                    SetConsoleTextAttribute(hConsole, 255);//white 255
                    break;
                case 1:
                    SetConsoleTextAttribute(hConsole, 0);//black 0
                    break;
                case 2:
                    SetConsoleTextAttribute(hConsole, 68);//dark red 65
                    break;
                case 3:
                    SetConsoleTextAttribute(hConsole, 204);//red 204
                    break;
                case 4:
                    SetConsoleTextAttribute(hConsole, 102);//dark yellow 102
                    break;
                case 5:
                    SetConsoleTextAttribute(hConsole, 238);//yellow 238
                    break;
                case 6:
                    SetConsoleTextAttribute(hConsole, 34);//dark green 34
                    break;
                case 7:
                    SetConsoleTextAttribute(hConsole, 170);//light green 170
                    break;
                case 8:
                    SetConsoleTextAttribute(hConsole, 17);//dark blue 17
                    break;
                case 9:
                    SetConsoleTextAttribute(hConsole, 153);//light blue 153
                    break;
                case 10:
                    SetConsoleTextAttribute(hConsole, 85);//dark purple 85
                    break;
                case 11:
                    SetConsoleTextAttribute(hConsole, 221);//light purple 221
                    break;
                case 12:
                    SetConsoleTextAttribute(hConsole, 51);//dark cyan 51
                    break;
                case 13:
                    SetConsoleTextAttribute(hConsole, 187);//cyan 187
                    break;
                case 14:
                    SetConsoleTextAttribute(hConsole, 119);//light grey 119
                    break;
                case 15:
                    SetConsoleTextAttribute(hConsole, 136);//dark grey 136
                    break;
            }
            if(i == y && j == x){
                SetConsoleTextAttribute(hConsole, 176);
                std::cout<<"++";
            }
            else{
            std::cout<<" ";
            std::cout<<" ";
            }
            SetConsoleTextAttribute(hConsole, 15);
        }
        std::cout<<std::endl;
    }
    display_colors();
}

int border_x(int position_x){
    if(position_x>59){
        position_x-=1;
    }
    if(position_x<0){
        position_x+=1;
    }
    return position_x;
}

int border_y(int position_y){
    if(position_y>34){
        position_y-=1;
    }
    if(position_y<0){
        position_y+=1;
    }
    return position_y;
}

void get_char(int position_x, int position_y, int previous_position_x, int previous_position_y, char movement){

        while (true){
        gotoxy(0,0);
        display_board(position_x, position_y);
        previous_position_x = position_x;
        previous_position_y = position_y;
        switch (getch()){
            case 'a':
                --position_x;
                break;
            case 'd':
                ++position_x;
                break;
            case 's':
                ++position_y;
                break;
            case 'w':
                --position_y;
                break;
            case 'x':
                system("cls");
                break;
            case ' ':
                World[position_y][position_x]=color;
                break;
            case '0':
                color = 0;
                break;
            case '1':
                color = 1;
                break;
            case '2':
                color = 2;
                break;
            case '3':
                color = 3;
                break;
            case '4':
                color = 4;
                break;
            case '5':
                color = 5;
                break;
            case '6':
                color = 6;
                break;
            case '7':
                color = 7;
                break;
            case '8':
                color = 8;
                break;
            case '9':
                color = 9;
                break;
            case 'e':
                color = 10;
                break;
            case 'r':
                color = 11;
                break;
            case 't':
                color = 12;
                break;
            case 'y':
                color = 13;
                break;
            case 'u':
                color = 14;
                break;
            case 'i':
                color = 15;
                break;
            case 'f':
                save_to_file();
                break;
        }
        position_x = border_x(position_x);
        position_y = border_y(position_y);
    }
}

void gotoxy(short x, short y) {
    COORD coord;
    coord.X = x; // kolumna
    coord.Y = y; // wiersz
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void display_colors(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout<<"0.";
    std::cout<<"White \t";

    std::cout<<"1.";
    std::cout<<"Black \t";


    std::cout<<"2.";
    SetConsoleTextAttribute(hConsole, 4);
    std::cout<<"Dark red \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"3.";
    SetConsoleTextAttribute(hConsole, 12);
    std::cout<<"Red \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"4.";
    SetConsoleTextAttribute(hConsole, 6);
    std::cout<<"Dark yellow \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"5.";
    SetConsoleTextAttribute(hConsole, 14);
    std::cout<<"light yellow \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"6.";
    SetConsoleTextAttribute(hConsole, 2);
    std::cout<<"Dark green \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"7.";
    SetConsoleTextAttribute(hConsole, 10);
    std::cout<<"Light green \n";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"8.";
    SetConsoleTextAttribute(hConsole, 1);
    std::cout<<"Dark blue \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"9.";
    SetConsoleTextAttribute(hConsole, 9);
    std::cout<<"Light blue \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"e.";
    SetConsoleTextAttribute(hConsole, 5);
    std::cout<<"Dark purple \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"r.";
    SetConsoleTextAttribute(hConsole, 13);
    std::cout<<"Light purple \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"t.";
    SetConsoleTextAttribute(hConsole, 3);
    std::cout<<"Dark cyan \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"y.";
    SetConsoleTextAttribute(hConsole, 11);
    std::cout<<"Cyan \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"u.";
    SetConsoleTextAttribute(hConsole, 7);
    std::cout<<"Light grey \t";
    SetConsoleTextAttribute(hConsole, 15);


    std::cout<<"i.";
    SetConsoleTextAttribute(hConsole, 8);
    std::cout<<"Dark grey \n";
    SetConsoleTextAttribute(hConsole, 15);

}

void make_color(int color, int position_x, int position_y)
{
    World[position_y][position_x]==color;
}

void save_to_file()
{
    std::fstream file;
    file.open("image.txt",std::ios::out);
    for (int i=0; i<=34; ++i){
        for (int j=0; j<=59; ++j){
                file<<World[i][j];
                file<<",";
        }
        file<<"\n";
    }
}

