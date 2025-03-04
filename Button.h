#pragma once
#include<vector>
#include "raylib.h"
#include <random>
#include <string>
using namespace std;

class Button
{
public:
    Vector2 mousePoint = { 0,0 };
    Rectangle rect;
    string text1;
    Color buttonColor;
    int FontSize;
    string buttonType;

    Button(float x, float y, float width, float height, const string text, int Font, Color color);  //konstruktor

    bool IsClicked();                       //metoda sprawdzaj�ca klikni�cie

    void Draw();                            //metoda rysuj�ca
        
    bool IsHover();                         //metoda sprawdzaj�ca najechanie
};