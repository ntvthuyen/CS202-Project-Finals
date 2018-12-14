#include "HeaderFile/sound.h"

void Sound::open() {
	string temp = "open " + path +" type waveaudio alias " + name;
	mciSendString(temp.c_str(), NULL, 0, NULL);
}
void Sound::play() {
	string temp = "play " + name;
	mciSendString(temp.c_str(), NULL, 0, NULL);
}
void Sound::stop() {
	string temp = "close " + name;
	mciSendString(temp.c_str(), NULL, 0, NULL);
}
void Sound::_play() {
	string temp = "play " + path;
	mciSendString(temp.c_str(), NULL, 0, NULL);
}