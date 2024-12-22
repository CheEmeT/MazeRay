#ifndef MAZERAY_SCENE
#define MAZERAY_SCENE


#include "raylib.h"
#include "Renderer.h"

class Application;

class Scene {
public:
	Scene(Application& app, Renderer* renderer) : m_renderer(renderer), m_app(app) {}
	virtual void draw() = 0;
	virtual void update() = 0;
protected:
	Renderer* m_renderer;
	Application& m_app;
	Color m_backgroundColor = BLACK;
};

#endif // !MAZERAY_SCENE
