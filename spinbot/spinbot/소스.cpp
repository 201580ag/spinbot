#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    int x = 100;
    int y = 0;

    cout << x << endl;

    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;

    while (true)
    {
        if (GetAsyncKeyState(VK_XBUTTON1) & 0x8000)
        {
            POINT p;
            GetCursorPos(&p);

            input.mi.dx = x;
            input.mi.dy = y;
            SendInput(1, &input, sizeof(input));
        }
    }

    if (GetAsyncKeyState(VK_END) & 0x8000)
    {
        system("pause");
    }

    return 0;
}