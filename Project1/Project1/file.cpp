#include "HeaderFile/file.h"

int File::saveFile(vector<Player> player) {
	ofstream file;
	file.open("SAVE.DAT", ios::binary);
	if (!file) return 0;
	int n = player.size();
	file.write((char*)&n,4);
	for (int i = 0; i < n; i++) {
		int hl = player[i].getHigestLevel();
		file.write((char*)&hl, 4);		
		hl = player[i].getName().length();
		file.write((char*)&hl, 4);
		file.write(player[i].getName().c_str(), player[i].getName().length());
	}
	file.close();
	return 1;
}
int File::readFile(vector<Player> &player) {
	ifstream file;
	file.open("SAVE.DAT", ios::binary);
	if (!file) return 0;
	int n;
	int length = 0;
	int highestlevel;
	file.read((char*)&n, 4);
	for (int i = 0; i < n; i++) {
		file.read((char*)&highestlevel, 4);
		file.read((char*)&length, 4);
		string name("",length);
		file.read(&name[0], length);
		player.push_back(Player(name, 20, highestlevel));
	}
	file.close();
	return 1;
}
int File::createDate() {
	ofstream file;
	file.open("GAME.DAT", ios::binary);
	if (!file) return 0;
	int n,m, z, k;
	cout << "The number of level: ";
	cin >> n;
	file.write((char*)&n, 4);
	for (int i = 0; i < n; ++i) {
		cout << "The number of lane";
		cin >> m;
		file.write((char*)&m, 4);
		for (int j = 0; j < m;++j) {
			cout << "Lane direction: 0 right 1 left";
			cin >> z;
			file.write((char*)&z, 4);
			cout << "Lane speed";
			cin >> z;
			file.write((char*)&z, 4);
			cout << "Has Traffic Light: 0 no 1 yes";
			cin >> z;
			file.write((char*)&z, 4);
			cout << "Time";
			if (z) cin >> z;
			file.write((char*)&z, 4);
			cout << "The number of object: ";
			cin >> k;
			file.write((char*)&k, 4);
			for (int l = 0; l < k; ++l) {
				cout << "Object type";
				cin >> z;
				file.write((char*)&z, 4);
				cout << "Object position";
				cin >> z;
				file.write((char*)&z, 4);
			}
		}
	}
	file.close();
}
int File::readData(vector<Level> &levelList, vector<TrafficLight*> &trafficLight) {
	ifstream file;
	file.open("GAME.DAT", ios::binary);
	if (!file) return 0;
	int n, m, k;
	int dir, type, pos, spd, hasT, tt;
	file.read((char*)&n, 4);
	for (int i = 0; i < n; ++i) {
		vector<Lane*> lane;
		file.read((char*)&m, 4);
		for (int j = 0; j < m; ++j) {
			vector<mObject*> obj;
			file.read((char*)&dir, 4);
			file.read((char*)&spd, 4);
			file.read((char*)&hasT, 4);
			if(hasT) file.read((char*)&tt, 4);
			file.read((char*)&k, 4);
			for (int l = 0; l < k; ++l) {
				file.read((char*)&type, 4);
				file.read((char*)&pos, 4);
				switch (type) {
				case 0:{
					obj.push_back(new Car(dir,pos));
					break; 
				}
				case 1: {
					obj.push_back(new Truck(dir, pos));
					break;
				}
				case 2: {
					obj.push_back(new Bird(dir, pos));
					break;
				}
				case 3: {
					obj.push_back(new Dino(dir, pos));
					break;
				}
				}
			}
			if (hasT) {
				trafficLight.push_back(new TrafficLight(false,tt,tt*0.6));
				lane.push_back(new Lane(obj, dir, spd,NULL, trafficLight.back()));
			}
			else
			lane.push_back(new Lane(obj,dir, spd, NULL, NULL));
		}
		levelList.push_back(Level(lane));
	}
	file.close();
}