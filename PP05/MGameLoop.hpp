#pragma once
#include <chrono>
#include <thread>
#include "MconsolUtil.hpp"

using namespace std;
namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsolRenderer cRenderer;

	public:
		MGameLoop()
		{
			_isGameRunning = false;
		}
		~MGameLoop() {}
		void Run()
		{
			_isGameRunning = true;

			Initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}

			Release();
		}

		void Stop()
		{
			_isGameRunning = false;
		}

	private:

		void Initialize()
		{

		}

		void Release()
		{
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == -0X8001)
			{

			}
			else
			{

			}
		}
		void Update()
		{

		}
		void Render()
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();

			cRenderer.Clear();
			cRenderer.MoveCursor(10, 20);


			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;

			int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);

			string fps = "FPS(milliseconds) : " + to_string(remainingFrameTime);

			if (remainingFrameTime > 0)
				this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));



			cRenderer.DrawString(fps);



		}



	};
}