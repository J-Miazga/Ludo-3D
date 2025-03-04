#include "Dice.h"



Dice::Dice() :gen(rd()), dis(0, 360) {}


void Dice::Roll() {

    if (t % 3 == 0 && roll)
    {
        randomNumber = (dis(gen));
        dice_value = randomNumber % 6 + 1;
    }
    int angle = randomNumber;

    square_points.resize(4);
    for (int i = 0; i < 4; i++) {
        float pointAngle = angle * DEG2RAD + set_angle_dice[i];
        Vector2 square_coordinates = { center_x + circleRadius * cos(pointAngle),center_y - circleRadius * sin(pointAngle) };
        square_points[i] = square_coordinates;
    }

    set_angle.resize(dice_value);
    circleRadius1.resize(dice_value);

    switch (dice_value) {
    case 1:
        circleRadius1 = { 0 };
        set_angle = { 0.00f * PI };
        break;
    case 2:
        circleRadius1 = { 50, 50 };
        set_angle = { 0.75f * PI, 1.75f * PI };
        break;
    case 3:
        circleRadius1 = { 50, 50, 0 };
        set_angle = { 0.75f * PI, 1.75f * PI, 0.0f * PI };
        break;
    case 4:
        circleRadius1 = { 50, 50, 50, 50 };
        set_angle = { 0.75f * PI, 0.25f * PI, 1.75f * PI, 1.25f * PI };
        break;
    case 5:
        circleRadius1 = { 50, 50, 50, 50, 0 };
        set_angle = { 0.75f * PI, 0.25f * PI, 1.75f * PI, 1.25f * PI, 0.0f * PI };
        break;
    case 6:
        circleRadius1 = { 50, 50, 50, 50, 35, 35 };
        set_angle = { 0.75f * PI, 0.25f * PI, 1.75f * PI, 1.25f * PI, 0.0f * PI, 1.0f * PI };
        break;
    default:
        break;
    }

    circle_center.resize(dice_value);
    for (int i = 0; i < dice_value; i++) {
        float pointAngle = angle * DEG2RAD + set_angle[i];
        Vector2 dots_coordinates = { center_x + circleRadius1[i] * cos(pointAngle),center_y - circleRadius1[i] * sin(pointAngle) };
        circle_center[i] = dots_coordinates;
    }
}

void Dice::Draw()
{
    DrawLineEx({ square_points[0].x,square_points[0].y }, { square_points[1].x,square_points[1].y }, 5, BLACK);
    DrawLineEx({ square_points[1].x,square_points[1].y }, { square_points[2].x,square_points[2].y }, 5, BLACK);
    DrawLineEx({ square_points[2].x,square_points[2].y }, { square_points[3].x,square_points[3].y }, 5, BLACK);
    DrawLineEx({ square_points[3].x,square_points[3].y }, { square_points[0].x,square_points[0].y }, 5, BLACK);
    for (int i = 0; i < dice_value; i++)
        DrawCircleV(circle_center[i], 15, BLACK);
}

