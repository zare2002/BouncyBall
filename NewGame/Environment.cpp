#include "environment.h"


Environment::Environment(float f, float cd, float gr) {
	friction = f;
	collision_damp = cd;
	g = gr;
}
Environment::~Environment() {
	
}