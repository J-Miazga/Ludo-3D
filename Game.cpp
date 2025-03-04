#include "Game.h"


    bool Game::areColorsEqual(const Color& c1, const Color& c2)
    {
        return (c1.r == c1.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
    }
    bool  Game::check_position(Vector3& position1, Vector3& position2)
    {
        return (position1.x == position2.x && position1.y == position2.y && position1.z == position2.z);
    }

    void  Game::another_pawn(int dice_value, vector<Button>& game_buttons, vector<Pawn>& pawn, vector<Board>& board)
    {
        

        if (areColorsEqual(BLUE, pawn[pawn_number_picked - 1].default_color))
        {
            for (int i = 0; i < 4; i++)
            {
                if (areColorsEqual(BLACK, game_buttons[i].buttonColor))
                {
                    game_buttons[i].buttonColor = BLUE;
                    return;
                }
            }
        }
        else if(areColorsEqual(GREEN, pawn[pawn_number_picked - 1].default_color)){
            for (int i = 4; i < 8; i++)
            {
                if (areColorsEqual(BLACK, game_buttons[i].buttonColor))
                {
                    game_buttons[i].buttonColor = GREEN;
                    return;
                }
            }
        }
        else if (areColorsEqual(YELLOW, pawn[pawn_number_picked - 1].default_color)) {
            for (int i = 8; i < 12; i++)
            {
                if (areColorsEqual(BLACK, game_buttons[i].buttonColor))
                {
                    game_buttons[i].buttonColor = YELLOW;
                    return;
                }
            }
        }
        else if (areColorsEqual(RED, pawn[pawn_number_picked - 1].default_color)) {
            for (int i = 12; i < 16; i++)
            {
                if (areColorsEqual(BLACK, game_buttons[i].buttonColor))
                {
                    game_buttons[i].buttonColor = RED;
                    return;
                }
            }
        }
    }
    void  Game::button_colors(int dice_value, vector<Button>& game_buttons, vector<Pawn>& pawn, vector<Board>& board)
    {
        
        int how_much_blue = 0;
        int how_much_green= 0;
        int how_much_yellow = 0;
        int how_much_red = 0;
        for (int i = 0; i < 57; i++)
        {
            for (int j = 0; j < pawn.size() - 1; j++)
            {
                if (check_position(board[i].position, pawn[j].position) && areColorsEqual(pawn[j].default_color, BLUE))
                    how_much_blue++;
                else if (check_position(board[i].position, pawn[j].position) && areColorsEqual(pawn[j].default_color, GREEN))
                    how_much_green++;
                else if (check_position(board[i].position, pawn[j].position) && areColorsEqual(pawn[j].default_color, YELLOW))
                    how_much_yellow++;
                else if (check_position(board[i].position, pawn[j].position) && areColorsEqual(pawn[j].default_color, RED))
                    how_much_red++;
            }
        }
        

        for (int i = 0; i < game_buttons.size(); i++)
            game_buttons[i].buttonColor= BLACK;
        if (how_much_blue == 0)
            game_buttons[0].buttonColor = BLUE;
        if (how_much_green == 0)
            game_buttons[4].buttonColor = GREEN;
        if (how_much_yellow == 0)
            game_buttons[8].buttonColor = YELLOW;
        if (how_much_red == 0)
            game_buttons[12].buttonColor = RED;
        for (int i = 0; i < 57; i++)
        {
            for (int j = 0; j < pawn.size() - 1; j++)
            {
                if (check_position(board[i].position, pawn[j].position))
                    game_buttons[j].buttonColor = pawn[j].default_color;
            }
        }
    }
    bool  Game::is_pawn_in(int board_number, vector<Board>& board, vector<Pawn>& pawn)
    {
        for (int i = 0; i < pawn.size(); i++)
        {
            if (check_position(board[board_number].position, pawn[i].position))
                return true;
        }
        return false;
    }
    void  Game::capture_pawn(vector<Board>& board, vector<Pawn>& pawn, int board_number)
    {

        for (int i = 0; i < pawn.size(); i++)
        {
            if (check_position(board[board_number].position, pawn[i].position))
            {

                if (areColorsEqual(pawn[i].default_color, pawn[pawn_number_picked - 1].default_color))
                {
                    stay = true;
                    return;
                }
                if (areColorsEqual(pawn[i].default_color, board[board_number].default_color))
                {
                    return;
                }
                else
                {
                    for (int j = 57; j < board.size(); j++)
                    {
                        if (areColorsEqual(pawn[i].default_color, board[j].color) && !is_pawn_in(j, board, pawn))
                        {
                            pawn[i].position = board[j].position;
                            return;
                        }
                    }
                }

            }
        }
    }
    int  Game::win(vector<Board>& board, vector<Pawn>& pawn)
    {
        blue_pawns_number_in_home = 0;
        green_pawns_number_in_home = 0;
        yellow_pawns_number_in_home = 0;
        red_pawns_number_in_home = 0;
        for (int i = 40; i < 57; i++)
        {
            if (is_pawn_in(i, board, pawn) && areColorsEqual(board[i].default_color, BLUE))
                blue_pawns_number_in_home++;
            else if (is_pawn_in(i, board, pawn) && areColorsEqual(board[i].default_color, GREEN))
                green_pawns_number_in_home++;
            else if (is_pawn_in(i, board, pawn) && areColorsEqual(board[i].default_color, YELLOW))
                yellow_pawns_number_in_home++;
            else if (is_pawn_in(i, board, pawn) && areColorsEqual(board[i].default_color, RED))
                red_pawns_number_in_home++;
        }
        if (blue_pawns_number_in_home == 4)
            return 1;
        else if (green_pawns_number_in_home == 4)
            return 2;
        else if (yellow_pawns_number_in_home == 4)
            return 3;
        else if (red_pawns_number_in_home == 4)
            return 4;

        return 0;
    }
    void  Game::Start_Game(int dice_value, vector<Board>& board, vector<Pawn>& pawn, vector<Button>& game_buttons, bool roll)
    {
        if (roll)
        {
            pawn_number_picked_previous = pawn_number_picked;
        }
        button_colors(dice_value, game_buttons, pawn, board);
        if (pawn_number_picked != 0 && dice_value == 6)
            another_pawn(dice_value, game_buttons, pawn, board);
        if (pawn_number_picked != 0 && dice_value == 6)
        {
            temp_dice_value += dice_value;
            return;
        }
        if (pawn_number_picked_previous == pawn_number_picked)
        {
            dice_value += temp_dice_value;
            temp_dice_value = 0;

        }
        else
            temp_dice_value = 0;
        for (int j = 0; j < board.size(); j++)
        {
            if (pawn_number_picked != 0 && check_position(board[j].position, pawn[pawn_number_picked - 1].position))
            {
                if (pawn[pawn_number_picked - 1].number < 5 && j>56)
                    j = 0;
                else if (pawn[pawn_number_picked - 1].number < 5 && j + dice_value > 39)
                {
                    if (j + dice_value > 43)
                        return;
                    else
                        j = j + dice_value;

                }
                else if (pawn[pawn_number_picked - 1].number > 4 && pawn[pawn_number_picked - 1].number < 9 && j>56)
                    j = 10;
                else if (pawn[pawn_number_picked - 1].number > 4 && pawn[pawn_number_picked - 1].number < 9 && j + dice_value > 9 && j < 10)
                {
                    if (j + dice_value + 34 > 47)
                        return;
                    else
                        j = j + dice_value + 34;

                }
                else if (pawn[pawn_number_picked - 1].number > 4 && pawn[pawn_number_picked - 1].number < 9 && j + dice_value > 9 && j > 43)
                {
                    if (j + dice_value > 47)
                        return;
                    else
                        j = j + dice_value;
                }
                else if (pawn[pawn_number_picked - 1].number > 8 && pawn[pawn_number_picked - 1].number < 13 && j>56)
                    j = 20;
                else if (pawn[pawn_number_picked - 1].number > 8 && pawn[pawn_number_picked - 1].number < 13 && j + dice_value > 19 && j < 20)
                {
                    if (j + dice_value + 28 > 51)
                        return;
                    else
                        j = j + dice_value + 28;

                }
                else if (pawn[pawn_number_picked - 1].number > 8 && pawn[pawn_number_picked - 1].number < 13 && j + dice_value > 19 && j > 47)
                {
                    if (j + dice_value > 51)
                        return;
                    else
                        j = j + dice_value;
                }
                else if (pawn[pawn_number_picked - 1].number > 12 && pawn[pawn_number_picked - 1].number < 17 && j>56)
                    j = 30;
                else if (pawn[pawn_number_picked - 1].number > 12 && pawn[pawn_number_picked - 1].number < 17 && j + dice_value > 29 && j < 30)
                {
                    if (j + dice_value + 22 > 55)
                        return;
                    else
                        j = j + dice_value + 22;

                }
                else if (pawn[pawn_number_picked - 1].number > 12 && pawn[pawn_number_picked - 1].number < 17 && j + dice_value > 29 && j > 51)
                {
                    if (j + dice_value > 55)
                        return;
                    else
                        j = j + dice_value;
                }
                else if (j + dice_value > 39)
                    j = j + dice_value - 40;
                else
                    j = j + dice_value;
                capture_pawn(board, pawn, j);

                if (stay)
                {
                    stay = false;
                    return;
                }
                pawn[pawn_number_picked - 1].position = board[j].position;

                if (dice_value != 6)
                {
                    button_colors(dice_value, game_buttons, pawn, board);
                }
                return;
            }

        }
    }


