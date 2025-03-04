#include "Button.h"

Button::Button(float x, float y, float width, float height, const string text, int Font, Color color) {
    rect = { x, y, width, height };
    this->text1 = text;
    buttonColor = color;
    FontSize = Font;

}

bool  Button::IsClicked() {
    Vector2 mousePoint = GetMousePosition();
    bool mouseOver = (mousePoint.x >= rect.x) && (mousePoint.x <= rect.x + rect.width) &&
        (mousePoint.y >= rect.y) && (mousePoint.y <= rect.y + rect.height);

    return mouseOver && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
}

void  Button::Draw() {

    DrawRectangleRec(rect, buttonColor);
    DrawRectangleLines(rect.x, rect.y, rect.width, rect.height, BLACK);
    int textWidth = MeasureText(text1.data(), FontSize);
    int textHeight = FontSize;
    int textX = rect.x + (rect.width - textWidth) / 2;
    int textY = rect.y + (rect.height - textHeight) / 2;
    DrawText(text1.data(), textX, textY, FontSize, BLACK);
}

bool  Button::IsHover()
{
    Vector2 mousePoint = GetMousePosition();
    bool mouseOver = (mousePoint.x >= rect.x) && (mousePoint.x <= rect.x + rect.width) &&
        (mousePoint.y >= rect.y) && (mousePoint.y <= rect.y + rect.height);
    return mouseOver;
}
