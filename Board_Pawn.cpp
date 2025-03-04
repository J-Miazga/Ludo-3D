#include "Board_Pawn.h"


Board::Board(Vector3 position1, Color color1) {
    position = position1;
    default_color = color1;
    color = default_color;
}

void Board::Draw()
{
    DrawCube(position, size_x, size_y, size_z, color);
    DrawCubeWires(position, size_x, size_y, size_z, BLACK);
    DrawCubeWires(position, size_x + 0.01f, size_y, size_z + 0.01f, BLACK);
    DrawCubeWires(position, size_x + 0.02f, size_y, size_z + 0.02f, BLACK);
    DrawCubeWires(position, size_x + 0.03f, size_y, size_z + 0.03f, BLACK);
}


Pawn::Pawn(Vector3 position_1, Color color_1, int number_1)
{
    position = position_1;
    default_color = color_1;
    color = default_color;
    number = number_1;
}

void Pawn::Draw()
{
    DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
    DrawCylinderWires(position, radiusTop, radiusBottom, height, 5, BLACK);
}



