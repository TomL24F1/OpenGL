#include "GameEngine.h"
#include <iostream>

namespace GE {
	GameEngine::GameEngine() {

	}

	GameEngine::~GameEngine() {

	}

	bool GameEngine::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::cerr << "Unable to initialise SDL! SDL error: " << SDL_GetError() << std::endl;

			return false;
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow("SDL OpenGL", 50, 50, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			std::cerr << "Unable to create window! SDL error: " << SDL_GetError() << std::endl;

			return false;
		}

		glContext = SDL_GL_CreateContext(window);
		if (glContext == nullptr) {
			std::cerr << "SDL could not create GL context! SDL error: " <<SDL_GetError() << std::endl;

			return false;
		}

		GLenum status = glewInit();
		if (status != GLEW_OK) {
			std::cerr << "Error initialising GLEW! Error: " << glewGetErrorString(status) << std::endl;

			return false;
		}
		
		if (SDL_GL_SetSwapInterval(1) != 0) {
			std::cerr << "Warning: unable to set VSync! Error: " << SDL_GetError() << std::endl;

			return false;
		}

		return true;
	}

	bool GameEngine::keep_running() {
		SDL_PumpEvents();
		SDL_Event evt;

		if (SDL_PeepEvents(&evt, 1, SDL_GETEVENT, SDL_QUIT, SDL_QUIT)) {
			return false;
		}
		return true;
	}

	void GameEngine::update() {

	}

	void GameEngine::draw() {
		glClearColor(0.392f, 0.584f, 0.929f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-1.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(1.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, 1.0f);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-1.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.0f, -1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(1.0f, 0.0f);

		glEnd();

		SDL_GL_SwapWindow(window);
	}

	void GameEngine::shutdown() {
		SDL_DestroyWindow(window);
		window = nullptr;
		SDL_Quit();
	}

	void GameEngine::setwindowtitle(const char* new_title) {
		SDL_SetWindowTitle(window, new_title);
	}

	void display_info_message(const char* msg) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Basic Game Engine", msg, nullptr);
	}
}