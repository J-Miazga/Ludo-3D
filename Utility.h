#pragma once
#include "raylib.h"
#include "Board_Pawn.h"
#include "Game.h"
void Draw_player_screen(Button button1, Button button2, Button button3);      //funkcja rysuj�ca
void Draw_game_screen(Button button, vector<Button>& vec, Game& game, float quantity);		 //funkcja rysuj�ca
void Draw_win_screen(string text1, int FontSize, Color color);		 //funkcja rysuj�ca
int which_board_number(Game game, vector<Board>& board, vector<Pawn>& pawn, int picked);	//funkcja zwracaj�ca umer pola 
void vector_of_pawns(vector<int>& pawns_in_one, Game game, vector<Board>& board, vector<Pawn>& pawn, int board_number);			//funckja tworz�ca wektor pionk�w w tym samym polu
