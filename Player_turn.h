#pragma once
#include "raylib.h"
#include "Board_Pawn.h"
#include "Game.h"
enum  turn
{
    Blue = 0,
    Green,
    Yellow,
    Red
};
class Player_turn
{
public:
    turn player_turn = Blue;
    Color color;

    bool is_it_my_turn(Color pawn, Game* game);         //metoda odpowiedzialna za sprawdzenie czyja jest tura
    void update_turn(float quantity);                   //metoda odpowiedzialna za uaktualnienie tury
    void Draw(int FontSize, Game* game);                //metoda rysuj¹ca
   
};