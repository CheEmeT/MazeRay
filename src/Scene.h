#ifndef MAZERAY_SCENE
#define MAZERAY_SCENE


#include "raylib.h"
#include "Renderer.h"

class Application;

class Scene {
public:
	Scene( Renderer* renderer ) : m_renderer(renderer) {}
	virtual void draw() = 0;
	virtual void update() = 0;
protected:
	Renderer* m_renderer;
	Color m_backgroundColor = BLACK;
};

#endif // !MAZERAY_SCENE
