#pragma once
#ifndef _sound_h_
#define __sound_h_
#include <Windows.h>
#include <string>
#include <thread>
using namespace std;

class Sound {
private:
	string path;
	string name; // don't define the same name for 2 different files !!!
public:
	Sound(string path, string name = "") : path(path), name(name) {}
	void open();
	void play();
	void _play();
	void stop();
};
#endif