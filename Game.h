#pragma once
#include "raylib.h"
#include<vector>
#include "Button.h"
#include "Board_Pawn.h"
#include "Dice.h"


using namespace std;

class Game
{
public:
    int pawn_number_picked = 0;
    int pawn_number_picked_previous = 0;
    int blue_pawns_number_in_home = 0;
    int green_pawns_number_in_home = 0;
    int yellow_pawns_number_in_home = 0;
    int red_pawns_number_in_home = 0;
    int temp_dice_value = 0;
    bool stay = false;
    bool enter_board = false;

    bool areColorsEqual(const Color& c1, const Color& c2);      //metoda sprawdzaj¹ca zgodnoœæ kolorów
    bool check_position(Vector3& position1, Vector3& position2);    //metoda sprawdzaj¹ca zgodnoœæ pozycji
    void another_pawn(int dice_value, vector<Button>& game_buttons, vector<Pawn>& pawn, vector<Board>& board);      //metoda dodaj¹ca mo¿liowoœæ wejœcia nowym pionkiem
    void button_colors(int dice_value, vector<Button>& game_buttons, vector<Pawn>& pawn, vector<Board>& board);     //metoda odpowiedzialna za kolory guzików
    bool is_pawn_in(int board_number, vector<Board>& board, vector<Pawn>& pawn);                                    //metoda sprawdzaj¹ca czy pionek jest w polu
    void capture_pawn(vector<Board>& board, vector<Pawn>& pawn, int board_number);                                  //metoda odpowiedzialna za zbijanie pionka
    int win(vector<Board>& board, vector<Pawn>& pawn);                                                              //metoda odpowiedzialna za warunek zwyciêstwa
    void Start_Game(int dice_value, vector<Board>& board, vector<Pawn>& pawn, vector<Button>& game_buttons, bool roll);     //metoda odpowiedzialna za logikê gry
   
};