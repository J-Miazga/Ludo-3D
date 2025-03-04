#pragma once
#include "raylib.h"

class Board
{
public:
    Vector3 position = { 0.0f,0.0f, 0.0f };
    float size_x= 1.0f;
    float size_y = 0.0f;
    float size_z = 1.0f;
    Color default_color;
    Color hover_color = PINK;
    Color color;


    Board(Vector3 position1, Color color1);        //konstruktor
    void Draw();                                   //metoda rysuj¹ca
    

};
class Pawn
{
public:
    Vector3 position;
    float radiusTop = 0.0f;
    float radiusBottom = 0.5f;
    float height = 1.5f;
    int slices = 20;
    Color default_color;
    Color hover_color = PINK;
    Color color;
    int number;

    Pawn(Vector3 position_1, Color color_1, int number_1);  //konstruktor


    void Draw();                                                 //metoda rysuj¹ca


};