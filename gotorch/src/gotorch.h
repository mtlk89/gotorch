#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <torch/torch.h>

using namespace torch;
namespace godot {

class GDExample : public Sprite {
	GODOT_CLASS(GDExample, Sprite)

private:
	float time_passed;
	float time_emit;
	float amplitude;
	float speed;

public:
	static void _register_methods();

	GDExample();
	~GDExample();

	void _init(); // our initializer called by Godot

	float method();
};

}

#endif
