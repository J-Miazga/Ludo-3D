#include "Player_turn.h"


bool Player_turn::is_it_my_turn(Color pawn, Game* game)
{
    turn temp;
    if (game->areColorsEqual(pawn, BLUE))
        temp = Blue;
    else if (game->areColorsEqual(pawn, GREEN))
        temp = Green;
    else if (game->areColorsEqual(pawn, YELLOW))
        temp = Yellow;
    else //else if(game->areColorsEqual(pawn, RED))
        temp = Red;
    return player_turn == temp;
}

void Player_turn::update_turn(float quantity)
{
    int temp = (int)(quantity * 4);
    int i = player_turn;
    player_turn = static_cast<turn>((i + 1) % temp);
}

void Player_turn::Draw(int FontSize, Game* game)
{
    static const string Blue = "Blue";
    static const string Green = "Green";
    static const string Yellow = "Yellow";
    static const string Red = "Red";
    static string display_turn = Blue;
    if (player_turn == turn::Blue)
    {
        display_turn = Blue;
        color = BLUE;
    }
    else if (player_turn == turn::Green)
    {
        display_turn = Green;
        color = GREEN;
    }
    else if (player_turn == turn::Yellow)
    {
        display_turn = Yellow;
        color = YELLOW;
    }
    else
    {
        display_turn = Red;
        color = RED;
    }


    //DrawRectangle(100, 140, 400, 200, WHITE);
   // DrawRectangleLines(100, 140, 400, 200, BLACK);
   int textWidth = MeasureText(display_turn.data(), FontSize);
   // int textHeight = FontSize;
    int textX = 1500 + (400 - textWidth) / 2;
   // int textY = 140 + (200 - textHeight) / 2;
    DrawText(display_turn.data(), textX, 930, FontSize, color);
}
