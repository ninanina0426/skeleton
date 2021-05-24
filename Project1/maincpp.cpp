#include <DxLib.h>
#include <array> //

struct Vector2
{
	float x;
	float y;
};

struct Rect
{
	using Position2 = Vector2;

	Position2 center;//矩形の中心座標
	float w, h;				
	float Left()const 
	{
		return center.x - w;
	}
	float Righet()const 
	{
		return center.x + w;
	}
	float Top()const 
	{
		return center.y - w;
	}
	float Bottom() const 
	{
		return center.y + w;
	}
	float width() const 
	{
		return w * 2.0f;
	}
	
	float Head() const 
	{
		return h * 2.0f;
	}
};

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(true);

	SetWindowText("2016026_新田和奏");
	if (DxLib_Init())
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	Rect rcA = { 100,100,50,50 };
	
	char keyState[256];
	
	
	while (ProcessMessage() == 0)
	{
		ClsDrawScreen();
		GetHitKeyStateAll(keyState);
		constexpr float speed = 4.0f;
		if (keyState[KEY_INPUT_UP])
		{
			//上
			rcA.center.y -= speed;
		}
		if (keyState[KEY_INPUT_DOWN])
		{
			//下
			rcA.center.y += speed;
		}
		if (keyState[KEY_INPUT_LEFT])
		{
			//左
			rcA.center.x -= speed;
		}
		if (keyState[KEY_INPUT_RIGHT])
		{
			//右
			rcA.center.x += speed;
		}
		DrawBox(rcA.Left(), rcA.Top(), rcA.Righet(), rcA.Bottom(), 0xffffff, true);
		ScreenFlip();
	}
	return 0;
}

