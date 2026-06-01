#pragma once

class Delay
{
public:

void Init();

float Process(float input);

private:

float buffer[96000];

int write=0;
};