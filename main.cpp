#include<iostream>
#include "raylib.h"
#include<vector>
#include <random>
#include <string>
#include "Board_Pawn.h"
#include "Dice.h"
#include "Button.h"
#include "Game.h"
#include "Player_turn.h"
#include "Utility.h"

using namespace std;

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Chinczyk 3D");

    Camera3D camera = { 0 };
    camera.position = Vector3{ 0.0f, 15.0f, 20.0f }; // pozycja kamery
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // punkt na który patrzy kamera
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // filed-of-view(FOV) kamery
    camera.projection = CAMERA_PERSPECTIVE;             // typ wyœwietlania kamery

    bool player_screen = true;                        // flagi do kontroli eventów
    bool game_screen = false;
    bool twoplayers_flag = false;
    bool threeplayers_flag = false;
    bool fourplayers_flag = false;
    bool display = false;
    bool is_win = false;
    bool blue_win = false;
    bool green_win = false;
    bool red_win = false;
    bool yellow_win = false;
    bool end = false;
    
 
    float z = 0;
    float x = 5;
    float y = 0;
    int T = 0;
    int time = 0;
    int timer = 0;
    float quantity = 0;
    
    Player_turn player_turn;  
    vector<Board> square;             //wektor pól planszy
    vector<Pawn> pawns;               // wektor pionków
    vector<Button> game_buttons;        // wektor guzików do kontroli wyboru pionka
    vector<int> pawns_in_one;           //wektor iloœci pionków na jednym polu
    Dice dice;
    Button twoplayers(1625, 200, 150, 60,"2",50,DARKGRAY);
    Button threeplayers(1625, 300, 150, 60,"3",50, DARKGRAY);
    Button fourplayers(1625, 400, 150, 60,"4",50, DARKGRAY);
    Button rollButton(1575, 480, 250, 60,"Roll",50, DARKGRAY);
    
    const Color colory1[4] = { BLUE,GREEN,YELLOW,RED };
    const Color colory2[4] = { BLACK,BLACK,BLACK,BLACK };
    Color colory_buffer[4] = {};                                            // tworzenie obiektów klas do 157 linijki kodu
    for (int i = 0; i < 4; i++)                                             
    {
       for (int j = 0; j < 4; j++)
       {
           if (j == 0)
               colory_buffer[i] = colory1[i];
           else
               colory_buffer[i] = colory2[i];
           if (i ==0)
               game_buttons.push_back(Button(1550 + 90 * (j % 4), 580, 50, 50, to_string(j+1).c_str(), 30, colory_buffer[i]));
           else if (i ==1)
               game_buttons.push_back(Button(1550 + 90 * (j % 4), 650, 50, 50, to_string(j + 1).c_str(), 30, colory_buffer[i]));
           else if (i == 2)
               game_buttons.push_back(Button(1550 + 90 * (j % 4), 720, 50, 50, to_string(j + 1).c_str(), 30, colory_buffer[i]));
           else if (i == 3)
               game_buttons.push_back(Button(1550 + 90 * (j % 4), 790, 50, 50, to_string(j + 1).c_str(), 30, colory_buffer[i]));
       }
    }
    for (int i = 0; i < 58; i++) {
        if (i < 4 || (i > 7 && i < 10) || (i > 13 && i < 18) || (i > 38 && i < 44))
        {
            if (i == 0 || (i > 39 && i < 44))
                square.push_back(Board({ x,y,z }, BLUE));
            else
                square.push_back(Board({ x,y,z }, WHITE));
            x = x - 1;
        }
        else if ((i > 19 && i < 24) || (i > 27 && i < 30) || (i > 33 && i < 38) || (i > 47 && i < 52))
        {
            if (i == 48)
                x = x - 4;
            if (i == 20 || (i > 47 && i < 52))
                square.push_back(Board({ x,y,z }, YELLOW));
            else
                square.push_back(Board({ x,y,z }, WHITE));
            x = x + 1;
        }
        else if ((i > 9 && i < 14) || (i > 17 && i < 20) || (i > 23 && i < 28) || (i > 43 && i < 48))
        {
            if (i == 44)
                z = z + 4;
            if (i == 10 || (i > 43 && i < 48))
                square.push_back(Board({ x,y,z }, GREEN));
            else
                square.push_back(Board({ x,y,z }, WHITE));
            z = z - 1;
        }
        else if (i == 57)
        {
            z = z - 1;
            square.push_back(Board({ x,y,z }, BLACK));
        }
        else
        {
            if (i == 52)
                z = z - 4;
            if (i == 30 || (i > 51 && i < 57))
                square.push_back(Board({ x,y,z }, RED));
            else
                square.push_back(Board({ x,y,z }, WHITE));
            z = z + 1;
        }
    }
    square.push_back(Board({ 4,0,3 }, BLUE));
    square.push_back(Board({ 4,0,4 }, BLUE));
    square.push_back(Board({ 5,0,3 }, BLUE));
    square.push_back(Board({ 5,0,4 }, BLUE));
    square.push_back(Board({ -4,0,3 }, GREEN));
    square.push_back(Board({ -4,0,4 }, GREEN));
    square.push_back(Board({ -5,0,3 }, GREEN));
    square.push_back(Board({ -5,0,4 }, GREEN));
    square.push_back(Board({ -4,0,-5 }, YELLOW));
    square.push_back(Board({ -4,0,-6 }, YELLOW));
    square.push_back(Board({ -5,0,-5 }, YELLOW));
    square.push_back(Board({ -5,0,-6 }, YELLOW));
    square.push_back(Board({ 4,0,-5 }, RED));
    square.push_back(Board({ 4,0,-6 }, RED));
    square.push_back(Board({ 5,0,-5 }, RED));
    square.push_back(Board({ 5,0,-6 }, RED));
    
    for (int i = 0; i < 16; i++)
    {
        if (i < 4)
            pawns.push_back(Pawn({ square[58 + i].position, BLUE ,i + 1 }));
        else if (i > 3 && i < 8)
                pawns.push_back(Pawn({ square[58 + i].position, GREEN ,i + 1 }));
        else if (i > 7 && i < 12)
                pawns.push_back(Pawn({ square[58 + i].position, YELLOW ,i + 1 }));       
        else if (i > 11 && i < 16)
                pawns.push_back(Pawn({ square[58 + i].position, RED ,i + 1 }));       
    }

    Game game;
    
    SetTargetFPS(60);                                                           // ustawienie wartoœci FPS
    InitAudioDevice();                                                          // inicjalizacja muzyki w tle
    Music backgroundMusic = LoadMusicStream("music.mp3");
    PlayMusicStream(backgroundMusic);
    
    while (!WindowShouldClose())                                                    //glówna pêtla programu
    {
        UpdateMusicStream(backgroundMusic);                                        //odtwarzanie muzyki w pêtli

        if (IsKeyDown(KEY_W)) camera.position.z -= 0.2f;                            //kontrola kamery
        if (IsKeyDown(KEY_S)) camera.position.z += 0.2f;
        if (IsKeyDown(KEY_A)) camera.position.x -= 0.2f;
        if (IsKeyDown(KEY_D)) camera.position.x += 0.2f;
 
        if (rollButton.IsClicked() )                                                //sprawdzanie eventów zwiazanych z klikniêciem guzika
            dice.roll = true;
        if ((twoplayers.IsClicked() || threeplayers.IsClicked() || fourplayers.IsClicked()) && player_screen )
        {
            if (twoplayers.IsClicked())
                quantity = 0.5;
            else if (threeplayers.IsClicked())
                quantity = 0.75;
            else if (fourplayers.IsClicked())
                quantity = 1;
            player_screen = false;
            game_screen = true;
        }
        for (int i = 0; i < game_buttons.size()*quantity; i++)
        {            
            if (game_buttons[i].IsHover()&&!player_screen)                                          //sprawdzanie eventu najechania na guzik
            {
                vector_of_pawns(pawns_in_one, game, square, pawns, which_board_number(game, square, pawns, i));
                pawns[pawns_in_one[pawns_in_one.size() - 1]].color = pawns[pawns_in_one[pawns_in_one.size() - 1]].hover_color;
                if (i != pawns_in_one[pawns_in_one.size() - 1])
                    display = true;           
            }
            else 
            {
                if (display)
                {
                    display = false;
                    break;
                }
                else                
                    pawns[i].color = pawns[i].default_color;

            }

            if (game_buttons[i].IsClicked()&& !game.areColorsEqual(game_buttons[i].buttonColor,BLACK))
            {              
                game.pawn_number_picked = pawns[i].number;              
            }
        }
        if(game.pawn_number_picked !=0 &&!player_turn.is_it_my_turn(pawns[game.pawn_number_picked-1].default_color,&game))
            dice.roll = false;
        dice.Roll();                                                                                                                //rzucenie kostk¹
        if (game.pawn_number_picked != 0 && player_turn.is_it_my_turn(pawns[game.pawn_number_picked - 1].default_color, &game)) {   //rozpoczêcie metody ruchu pionka
            for (int i = 0; i < square.size(); i++) {
                if (game.check_position(square[i].position, pawns[game.pawn_number_picked - 1].position))
                    if (i > 57)
                    {
                        game.Start_Game(0, square, pawns, game_buttons, dice.roll);   
                        player_turn.update_turn(quantity);                        
                        break;
                    }
                    else if (dice.roll && T == 60)
                    {
                        game.Start_Game(dice.dice_value, square, pawns, game_buttons, dice.roll);  
                        if (dice.dice_value != 6)
                        player_turn.update_turn(quantity);
                        break;
                    }
            }
        }
       
            if(!is_win)                                                     //sprawdzanie warunku zwyciêstwa
                switch(game.win(square, pawns))
            { 
            case 1:
                blue_win = true;
                is_win = true;
                break;
            case 2:
                green_win = true;
                is_win = true;
                break;
            case 3:
                yellow_win = true;
                is_win = true;
                break;
            case 4:
                red_win = true;
                is_win = true;
                break; 
            default:
                break;
            }
        
        BeginDrawing();                                                     //rozpoczêcie rysowania

        ClearBackground(RAYWHITE);  

        BeginMode3D(camera);                                                //rozpoczêcie trybu 3D
        for (int i = 0; i < square.size(); i++)
        {
            square[i].Draw();   
            if (i < 16 * quantity)
            {
                    pawns[i].Draw();
            }
        }
        EndMode3D();
        
        if (player_screen)
            Draw_player_screen(twoplayers, threeplayers, fourplayers);
        
        else if (game_screen)
        {
            Draw_game_screen(rollButton,game_buttons,game,quantity);
            dice.Draw();
        }
        
        if(game_screen)
            player_turn.Draw(50,&game);
        if(blue_win && time<300)
            Draw_win_screen("Blue Wins", 50, BLUE);
        else if(green_win && time < 300)
            Draw_win_screen("Green Wins", 50, GREEN);
        else if(yellow_win && time < 300)
            Draw_win_screen("Yellow Wins", 50, YELLOW);
        else if(red_win && time<300)
            Draw_win_screen("Red Wins", 50, RED);
        EndDrawing();   

        if (dice.roll && T == 60)                                                       //zlicznanie timerów
        {
            dice.roll = false;
            T = 0;
        }
        else if (dice.roll)
        {
            T++;
            dice.t++;
        }
        if (time > 300)
            end = true;
        if (is_win && !end)
            time++;
     
    }
    UnloadMusicStream(backgroundMusic); // Unload music stream                              //deinicjalizacja muzyki
    CloseAudioDevice(); // Close audio device
    CloseWindow();      
    return 0;
}