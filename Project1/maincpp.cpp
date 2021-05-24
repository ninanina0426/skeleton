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

	Position2 center;//��`�̒��S���W
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

	SetWindowText("2016026_�V�c�a�t");
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
			//��
			rcA.center.y -= speed;
		}
		if (keyState[KEY_INPUT_DOWN])
		{
			//��
			rcA.center.y += speed;
		}
		if (keyState[KEY_INPUT_LEFT])
		{
			//��
			rcA.center.x -= speed;
		}
		if (keyState[KEY_INPUT_RIGHT])
		{
			//�E
			rcA.center.x += speed;
		}
		DrawBox(rcA.Left(), rcA.Top(), rcA.Righet(), rcA.Bottom(), 0xffffff, true);
		ScreenFlip();
	}
	return 0;
}

