#pragma once
#include<vector>
#include "raylib.h"
#include <random>

using namespace std;

class Dice
{
public:
    bool roll = false;
    int circleRadius = 100;
    int randomNumber = 0;
    int dice_value = 1;
    int t = 0;
    float center_x = 1700;
    float center_y = 350;

    vector<int> circleRadius1;
    vector<float> set_angle;
    vector<float> set_angle_dice = { 0.25f * PI ,0.75f * PI,1.25f * PI,1.75f * PI };

    vector<Vector2> square_points = {};
    vector<Vector2> circle_center = {};


    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> dis;


    Dice();                 //konstruktor


    void Roll();            //metoda odpowiedzialna za rzut kostk¹

    void Draw();            //metoda rysuj¹ca
   

};