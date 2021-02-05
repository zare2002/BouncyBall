#pragma once

struct Environment {
	float friction;
	float collision_damp;
	float g;

public:
    Environment(float f, float cd, float gr);
	~Environment();

};
