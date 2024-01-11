#include "Factory.h"
#include <vector>
#include <random>
#include <windows.h>

Factory::Factory(Character* c) {
	character = c;
}

// factory to create a Minion
Minion* Factory::CreateEnemy(EnemyType type) {
	switch (type) {
		case(TXT):
			return new Minion("txt", 0, "Text File", "Write");
		case(PDF):
			return new Minion("pdf", 1, "PDF File", "Edit");
		case(MS):
			return new Minion("ms", 2, "MS Office", "Cut/Paste");
		case(PNG):
			return new Minion("png", 3, "PNG File", "Remove");
		case(JPG):
			return new Minion("jpg", 4, "JPG File", "Compress");
		case(GIF):
			return new Minion("gif", 5, "GIF File", "Loop");
		case(OGG):
			return new Minion("ogg", 6, "OGG File", "Multiplex");
		case(WAV):
			return new Minion("wav", 7, "WAV File", "Stereo");
		case(MP3):
			return new Minion("mp3", 8, "MP3 File", "Transform type: FF");
		case(AVI):
			return new Minion("avi", 9, "AVI File", "Stream");
		case(MOV):
			return new Minion("mov", 10, "MOV File", "QuickTime");
		case(MP4):
			return new Minion("mp4", 11, "MP4 File", "Multitrack");
	}
}

// factory to create a EnemyRoom
EnemyRoom* Factory::CreateEnemyRoom(EnemyType type) {
	switch (type) {
		case(TXT):
			return new EnemyRoom("Text File", "A stream of characters eminate out from this file... yet somehow the simplicity demonstrates complex structures...", character, CreateEnemy(type));
		case(PDF):
			return new EnemyRoom("PDF File", "So much media all coming together in seemingly uneditable harmony... careful...", character, CreateEnemy(type));
		case(MS):
			return new EnemyRoom("MS Office", "Its like a hydra... so many programs.. one body... so much power...", character, CreateEnemy(type));
		case(PNG):
			return new EnemyRoom("PNG File", "Is there something here? Its presence is tangible... is it... transparent?", character, CreateEnemy(type));
		case(JPG):
			return new EnemyRoom("JPG File", "The walls seem to be closing in... a certain... compression...", character, CreateEnemy(type));
		case(GIF):
			return new EnemyRoom("GIF File", "It won't stop It won't stop It won't stop It won't stop It won't stop It won't stop stop stop stop stop stop", character, CreateEnemy(type));
		case(OGG):
			return new EnemyRoom("OGG File", "Streams of data rush past you into the file before you...", character, CreateEnemy(type));
		case(WAV):
			return new EnemyRoom("WAV File", "It's on the left.... wait... right... no... it's coming from everywhere", character, CreateEnemy(type));
		case(MP3):
			return new EnemyRoom("MP3 File", "What... is ... that... melody...", character, CreateEnemy(type));
		case(AVI):
			return new EnemyRoom("AVI File", "It's moving... it's speaking... it's going... it's coming...", character, CreateEnemy(type));
		case(MOV):
			return new EnemyRoom("MOV File", "It has a copy... it's just as strong... and just as complex...", character, CreateEnemy(type));
		case(MP4):
			return new EnemyRoom("MP4 File", "It's everything you've faced... all at the same time... in one file... how?", character, CreateEnemy(type));
	}
}

// factory to create a Room
Room* Factory::GenerateRoom() {
	int i = rand();
	switch (i % 3) {
	case(0):
		return new HealthRoom("Spare MB", "Theres empty storage deep within the system... perhaps you could use it", character);
		break;
	case(1):
		return new BufferRoom("Spare RAM", "Its empty here... unused and random...", character);
		break;
	case(2):
		return new SpecRoom("System Code", "A vulnerable system file has its code exposed...", character);
		break;
	}
}

// factory to create a Folder
Folder* Factory::CreateFolder(int i) {
	vector<Room*> files;
	FileDLL* folder = new FileDLL();

	switch(i) {
		case(1):
			files.push_back(CreateEnemyRoom(TXT));
			files.push_back(CreateEnemyRoom(PDF));
			files.push_back(CreateEnemyRoom(MS));

			for (int j = 0; j < 4; j++) {
				files.push_back(GenerateRoom());
			}

			random_shuffle(files.begin(), files.end());

			for(Room* file : files) {
				folder->append(file);
			}

			return new Folder(folder, "My Documents", character, CreateMiniBossRoom(i));

		case(2):
			files.push_back(CreateEnemyRoom(PNG));
			files.push_back(CreateEnemyRoom(JPG));
			files.push_back(CreateEnemyRoom(GIF));

			for (int j = 0; j < 4; j++) {
				files.push_back(GenerateRoom());
			}

			random_shuffle(files.begin(), files.end());

			for (Room* file : files) {
				folder->append(file);
			}

			return new Folder(folder, "My Images", character, CreateMiniBossRoom(i));

		case(3):
			files.push_back(CreateEnemyRoom(OGG));
			files.push_back(CreateEnemyRoom(WAV));
			files.push_back(CreateEnemyRoom(MP3));

			for (int j = 0; j < 4; j++) {
				files.push_back(GenerateRoom());
			}

			random_shuffle(files.begin(), files.end());

			for (Room* file : files) {
				folder->append(file);
			}

			return new Folder(folder, "My Music", character, CreateMiniBossRoom(i));

		case(4):
			files.push_back(CreateEnemyRoom(AVI));
			files.push_back(CreateEnemyRoom(MOV));
			files.push_back(CreateEnemyRoom(MP4));

			for (int j = 0; j < 4; j++) {
				files.push_back(GenerateRoom());
			}

			random_shuffle(files.begin(), files.end());

			for (Room* file : files) {
				folder->append(file);
			}

			return new Folder(folder, "My Videos", character, CreateMiniBossRoom(i));
	}
}

// factory to create a MiniBoss
MiniBoss* Factory::CreateMiniBoss(int i) {
	switch (i) {
		case(1):
			return new MiniBoss("doc", 0, "My Documents", "Backspace", "Cut", "Encrypt");
		case(2):
			return new MiniBoss("img", 1, "My Images", "Crop", "Noise", "Watermark");
		case(3):
			return new MiniBoss("mus", 2, "My Music", "Volume UP", "Playback", "Pause");
		case(4):
			return new MiniBoss("vid", 3, "My Videos", "Clip", "Re-sequence", "Encode");
	}
}

// factory to create a MiniBossRoom
MiniBossRoom* Factory::CreateMiniBossRoom(int i) {
	switch (i) {
	case(1):
		return new MiniBossRoom("My Documents", "Chracters of all typefaces and encoding swirl around you... an army ready to hold you back", character, CreateMiniBoss(i));
	case(2):
		return new MiniBossRoom("My Images", "Flashes of colours... variety of shapes... a whole new dimension... all to turn against you", character, CreateMiniBoss(i));
	case(3):
		return new MiniBossRoom("My Music", "A sweet symphony echoes through the folder... a build up getting more and more tense until it finally crashes on you", character, CreateMiniBoss(i));
	case(4):
		return new MiniBossRoom("My Videos", "The final folder... all three mediums coming together as a final blockade to prevent you from getting you to your goal", character, CreateMiniBoss(i));
	}
}

Factory::~Factory() {

}