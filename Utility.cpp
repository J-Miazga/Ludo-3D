#include "Utility.h"
void Draw_player_screen(Button button1, Button button2, Button button3)
{
    DrawRectangle(1500, 10, 400, 500, WHITE);
    DrawRectangleLines(1500, 10, 400, 500, BLACK);
    DrawText("Liczba graczy", 1530, 60, 50, BLACK);
    button1.Draw();
    button2.Draw();
    button3.Draw();
}
void Draw_game_screen(Button button, vector<Button>& vec, Game& game, float quantity)
{
    DrawRectangle(1500, 10, 400, 1060, WHITE);
    DrawRectangleLines(1500, 10, 400, 1060, BLACK);
    DrawText("Liczba pionkow na mecie", 1530, 40, 30, BLACK);
    DrawText(to_string(game.blue_pawns_number_in_home).c_str(), 1600, 90, 50, BLUE);
    DrawText(to_string(game.red_pawns_number_in_home).c_str(), 1800, 90, 50, RED);
    DrawText(to_string(game.yellow_pawns_number_in_home).c_str(), 1600, 150, 50, YELLOW);
    DrawText(to_string(game.green_pawns_number_in_home).c_str(), 1800, 150, 50, GREEN);
    button.Draw();
    for (int i = 0; i < vec.size() * quantity; i++)
    {
        vec[i].Draw();
    }
}
void Draw_win_screen(string text1, int FontSize, Color color)
{
    DrawRectangle(660, 340, 400, 200, WHITE);
    DrawRectangleLines(660, 340, 400, 200, BLACK);
    int textWidth = MeasureText(text1.data(), FontSize);
    int textHeight = FontSize;
    int textX = 660 + (400 - textWidth) / 2;
    int textY = 340 + (200 - textHeight) / 2;
    DrawText(text1.data(), textX, textY, FontSize, color);
}
int which_board_number(Game game, vector<Board>& board, vector<Pawn>& pawn, int picked)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (game.check_position(board[i].position, pawn[picked].position))
            return i;
    }

}
void vector_of_pawns(vector<int>& pawns_in_one, Game game, vector<Board>& board, vector<Pawn>& pawn, int board_number)
{
    pawns_in_one.resize(0);
    for (int i = 0; i < pawn.size(); i++)
    {
        if (game.check_position(pawn[i].position, board[board_number].position))
            pawns_in_one.push_back(i);
    }
}