#include "gotorch.h"

using namespace godot;

void GDExample::_register_methods() {
	register_method("method", &GDExample::method);
}

GDExample::GDExample() {
}

GDExample::~GDExample() {
	// add your cleanup here
}

void GDExample::_init() {
	// initialize any variables here
	time_passed = 0.0;
	amplitude = 10.0;
	speed = 1.0;
}

float GDExample::method () {
	Godot::print("hello");
	return torch::randn({ 3,2 })[1][1].item<float>();
}
