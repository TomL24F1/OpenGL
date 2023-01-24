#pragma once
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>

namespace GE {
	class GameEngine {
	public:
		GameEngine();

		virtual ~GameEngine();

		bool init();
		bool keep_running();
		void update();
		void draw();
		void shutdown();

		void setwindowtitle(const char*);

	private:
		SDL_Window* window;
		SDL_GLContext glContext;
	};

	void display_info_message(const char*);
}
