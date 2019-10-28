#include "lang.hpp"
#include "graphics.hpp"
#include "inifile.hpp"
#include "langStrings.hpp"
#include "manager.hpp"

std::string langs[] = { "de", "en", "es", "fr", "it", "lt", "pt", "ru", "jp", "ko"};

void Lang::loadLangStrings(int lang) {
	abilities.clear();
	games.clear();
	items.clear();
	locations4.clear();
	locations5.clear();
	moves.clear();
	natures.clear();
	species.clear();

	// Declare variables
	char* line = NULL;
	size_t len = 0;

	// Check if the language has game info
	int tempLang = (access(("nitro:/lang/"+langs[lang]+"/abilities.txt").c_str(), F_OK) == 0) ? lang : 1;

	// Fill vectors from files
	FILE* in = fopen(("nitro:/lang/"+langs[tempLang]+"/abilities.txt").c_str(), "r");
	while(__getline(&line, &len, in) != -1) {
		line[strlen(line)-1] = '\0';
		abilities.push_back(line);
	}
	fclose(in);

	in = fopen(("nitro:/lang/"+langs[tempLang]+"/games.txt").c_str(), "r");
	while(__getline(&line, &len, in) != -1) {
		line[strlen(line)-1] = '\0';
		games.push_back(line);
	}
	fclose(in);

	in = fopen(("nitro:/lang/"+langs[tempLang]+"/items.txt").c_str(), "r");
	while(__getline(&line, &len, in) != -1) {
		line[strlen(line)-1] = '\0';
		items.push_back(line);
	}
	fclose(in);

	in = fopen(("nitro:/lang/"+langs[tempLang]+"/locations4.txt").c_str(), "r");
	while(__getline(&line, &len, in) != -1) {
		line[strlen(line)-1] = '\0';
		locations4.push_back(line);
	}
	fclose(in);

	in = fopen(("nitro:/lang/"+langs[tempLang]+"/locations5.txt").c_str(), "r");
	while(__getline(&line, &len, in) != -1) {
		line[strlen(line)-1] = '\0';
		locations5.push_back(line);
	}
	fclose(in);

	in = fopen(("nitro:/lang/"+langs[tempLang]+"/moves.txt").c_str(), "r");
	while(__getline(&line, &len, in) != -1) {
		line[strlen(line)-1] = '\0';
		moves.push_back(line);
	}
	fclose(in);

	in = fopen(("nitro:/lang/"+langs[tempLang]+"/natures.txt").c_str(), "r");
	while(__getline(&line, &len, in) != -1) {
		line[strlen(line)-1] = '\0';
		natures.push_back(line);
	}
	fclose(in);

	in = fopen(("nitro:/lang/"+langs[tempLang]+"/species.txt").c_str(), "r");
	while(__getline(&line, &len, in) != -1) {
		line[strlen(line)-1] = '\0';
		species.push_back(line);
	}
	fclose(in);

	// Load types picture
	types.clear();
	tempLang = (access(("nitro:/lang/"+langs[lang]+"/types.png").c_str(), F_OK) == 0) ? lang : 1;
	typesData = loadPng("nitro:/lang/"+langs[tempLang]+"/types.png", types);

	// Load app strings
	CIniFile ini("nitro:/lang/"+langs[lang]+"/app.ini");

	// [aMenu]
	Lang::aMenuText[0] = ini.GetString("aMenu", "move", Lang::aMenuText[0]);
	Lang::aMenuText[1] = ini.GetString("aMenu", "edit", Lang::aMenuText[1]);
	Lang::aMenuText[2] = ini.GetString("aMenu", "copy", Lang::aMenuText[2]);
	Lang::aMenuText[3] = ini.GetString("aMenu", "release", Lang::aMenuText[3]);
	Lang::aMenuText[4] = ini.GetString("aMenu", "dump", Lang::aMenuText[4]);
	Lang::aMenuText[5] = ini.GetString("aMenu", "back", Lang::aMenuText[5]);
	Lang::aMenuEmptySlotText[0] = ini.GetString("aMenu", "inject", Lang::aMenuEmptySlotText[0]);
	Lang::aMenuEmptySlotText[1] = ini.GetString("aMenu", "create", Lang::aMenuEmptySlotText[1]);
	Lang::aMenuEmptySlotText[2] = ini.GetString("aMenu", "back", Lang::aMenuEmptySlotText[2]);
	Lang::aMenuTopBarText[0] = ini.GetString("aMenu", "jump", Lang::aMenuTopBarText[0]);
	Lang::aMenuTopBarText[1] = ini.GetString("options", "rename", Lang::aMenuTopBarText[1]);
	Lang::aMenuTopBarText[2] = ini.GetString("aMenu", "swap", Lang::aMenuTopBarText[2]);
	Lang::aMenuTopBarText[3] = ini.GetString("aMenu", "wallpaper", Lang::aMenuTopBarText[3]);
	Lang::aMenuTopBarText[4] = ini.GetString("aMenu", "dumpBox", Lang::aMenuTopBarText[4]);
	Lang::aMenuTopBarText[5] = ini.GetString("aMenu", "back", Lang::aMenuTopBarText[5]);

	// [filter]
	Lang::filterLabels[0] = ini.GetString("summary", "dexNo", Lang::filterLabels[0]);
	Lang::filterLabels[1] = ini.GetString("summary", "nature", Lang::filterLabels[1]);
	Lang::filterLabels[2] = ini.GetString("summary", "ability", Lang::filterLabels[2]);
	Lang::filterLabels[3] = ini.GetString("filter",  "gender", Lang::filterLabels[3]);
	Lang::filterLabels[4] = ini.GetString("summary", "item", Lang::filterLabels[4]);
	Lang::filterLabels[5] = ini.GetString("filter",  "ball", Lang::filterLabels[5]);
	Lang::filterLabels[6] = ini.GetString("filter",  "form", Lang::filterLabels[6]);
	Lang::filterLabels[7] = ini.GetString("summary", "level", Lang::filterLabels[7]);
	Lang::filterLabels[8] = ini.GetString("summary", "moves", Lang::filterLabels[8]);
	Lang::filterLabels[9] = ini.GetString("summary", "shiny", Lang::filterLabels[9]);

	// [gender]
	Lang::genders[0] = ini.GetString("gender", "male", Lang::genders[0]);
	Lang::genders[1] = ini.GetString("gender", "female", Lang::genders[1]);
	Lang::genders[2] = ini.GetString("gender", "unknown", Lang::genders[2]);

	// [main]
	Lang::cancel = ini.GetString("main", "cancel", Lang::cancel);
	Lang::chest = ini.GetString("main", "chest", Lang::chest);
	Lang::dexNo = ini.GetString("main", "dexNo", Lang::dexNo);
	Lang::discard = ini.GetString("main", "discard", Lang::discard);
	Lang::female = ini.GetString("gender", "female", Lang::female);
	Lang::filter = ini.GetString("main", "filter", Lang::filter);
	Lang::hpType = ini.GetString("main", "hpType", Lang::hpType);
	Lang::invalidSave = ini.GetString("main", "invalidSave", Lang::invalidSave);
	Lang::level = ini.GetString("main", "level", Lang::level);
	Lang::loading = ini.GetString("main", "loading", Lang::loading);
	Lang::male = ini.GetString("gender", "male", Lang::male);
	Lang::no = ini.GetString("main", "no", Lang::no);
	Lang::origin = ini.GetString("main", "origin", Lang::origin);
	Lang::release = ini.GetString("aMenu", "release", Lang::release);
	Lang::remove = ini.GetString("main", "remove", Lang::remove);
	Lang::save = ini.GetString("main", "save", Lang::save);
	Lang::sort = ini.GetString("main", "sort", Lang::sort);
	Lang::yes = ini.GetString("main", "yes", Lang::yes);

	// [options]
	Lang::optionsTextLabels[0] = ini.GetString("options", "chestFile", Lang::optionsTextLabels[0]);
	Lang::optionsTextLabels[1] = ini.GetString("options", "chestSize", Lang::optionsTextLabels[1]);
	Lang::optionsTextLabels[2] = ini.GetString("options", "language", Lang::optionsTextLabels[2]);
	Lang::optionsTextLabels[3] = ini.GetString("options", "backupAmount", Lang::optionsTextLabels[3]);
	Lang::optionsTextLabels[4] = ini.GetString("options", "music", Lang::optionsTextLabels[4]);
	Lang::optionsTextLabels[5] = ini.GetString("options", "soundFX", Lang::optionsTextLabels[5]);
	Lang::optionsTextLabels[6] = ini.GetString("options", "dPadDirections", Lang::optionsTextLabels[6]);
	Lang::optionsTextLabels[7] = ini.GetString("options", "dPadGroups", Lang::optionsTextLabels[7]);
	Lang::chestFileMenuText[0] = ini.GetString("options", "new", Lang::chestFileMenuText[0]);
	Lang::chestFileMenuText[1] = ini.GetString("options", "rename", Lang::chestFileMenuText[1]);
	Lang::chestFileMenuText[2] = ini.GetString("options", "delete", Lang::chestFileMenuText[2]);
	Lang::chestFileMenuText[3] = ini.GetString("options", "change", Lang::chestFileMenuText[3]);
	Lang::unlimited = ini.GetString("options", "unlimited", Lang::unlimited);

	// [origin]
	Lang::originLabels[0] = ini.GetString("origin", "metLevel", Lang::originLabels[0]);
	Lang::originLabels[1] = ini.GetString("origin", "metYear", Lang::originLabels[1]);
	Lang::originLabels[2] = ini.GetString("origin", "metMonth", Lang::originLabels[2]);
	Lang::originLabels[3] = ini.GetString("origin", "metDay", Lang::originLabels[3]);
	Lang::originLabels[4] = ini.GetString("origin", "metLocation", Lang::originLabels[4]);
	Lang::originLabels[5] = ini.GetString("origin", "originGame", Lang::originLabels[5]);

	Lang::pouch[0] = ini.GetString("pouch", "items", Lang::pouch[0]);
	Lang::pouch[1] = ini.GetString("pouch", "keyItems", Lang::pouch[1]);
	Lang::pouch[2] = ini.GetString("pouch", "tmHm", Lang::pouch[2]);
	Lang::pouch[3] = ini.GetString("pouch", "mail", Lang::pouch[3]);
	Lang::pouch[4] = ini.GetString("pouch", "medicine", Lang::pouch[4]);
	Lang::pouch[5] = ini.GetString("pouch", "berries", Lang::pouch[5]);
	Lang::pouch[6] = ini.GetString("pouch", "balls", Lang::pouch[6]);
	Lang::pouch[7] = ini.GetString("pouch", "battleItems", Lang::pouch[7]);

	// [songs]
	Lang::songs[0] = ini.GetString("songs", "off", Lang::songs[0]);
	Lang::songs[1] = ini.GetString("songs", "center1", Lang::songs[1]);
	Lang::songs[2] = ini.GetString("songs", "center4", Lang::songs[2]);
	Lang::songs[3] = ini.GetString("songs", "center5", Lang::songs[3]);
	Lang::songs[4] = ini.GetString("songs", "twinleafTown", Lang::songs[4]);
	Lang::songs[5] = ini.GetString("songs", "elmLab", Lang::songs[5]);
	Lang::songs[6] = ini.GetString("songs", "oakLab", Lang::songs[6]);
	Lang::songs[7] = ini.GetString("songs", "gameCorner", Lang::songs[7]);

// "Nature", "Level", "TID", "Hidden Power type", "Friendship", "Nickname", "Orig. Trainer", "Shiny"},
	// [sortText]
	Lang::sortText[0]  = ini.GetString("sort", "none", Lang::sortText[0]);
	Lang::sortText[1]  = ini.GetString("main", "dexNo", Lang::sortText[1]);
	Lang::sortText[2]  = ini.GetString("summary", "dexNo", Lang::sortText[2]);
	Lang::sortText[3]  = ini.GetString("filter", "form", Lang::sortText[3]);
	Lang::sortText[4]  = ini.GetString("sort", "type1", Lang::sortText[4]);
	Lang::sortText[5]  = ini.GetString("sort", "type2", Lang::sortText[5]);
	Lang::sortText[6]  = ini.GetString("stats", "hp", Lang::sortText[6]);
	Lang::sortText[7]  = ini.GetString("stats", "attack", Lang::sortText[7]);
	Lang::sortText[8]  = ini.GetString("stats", "defense", Lang::sortText[8]);
	Lang::sortText[9]  = ini.GetString("stats", "spAtk", Lang::sortText[9]);
	Lang::sortText[10] = ini.GetString("stats", "spDef", Lang::sortText[10]);
	Lang::sortText[11] = ini.GetString("stats", "speed", Lang::sortText[11]);
	Lang::sortText[12] = ini.GetString("stats", "hp", Lang::sortText[6]) + " " + ini.GetString("stats", "iv", Lang::statsLabels[7]);
	Lang::sortText[13] = ini.GetString("stats", "attack", Lang::sortText[7]) + " " + ini.GetString("stats", "iv", Lang::statsLabels[7]);
	Lang::sortText[14] = ini.GetString("stats", "defense", Lang::sortText[8]) + " " + ini.GetString("stats", "iv", Lang::statsLabels[7]);
	Lang::sortText[15] = ini.GetString("stats", "spAtk", Lang::sortText[9]) + " " + ini.GetString("stats", "iv", Lang::statsLabels[7]);
	Lang::sortText[16] = ini.GetString("stats", "spDef", Lang::sortText[10]) + " " + ini.GetString("stats", "iv", Lang::statsLabels[7]);
	Lang::sortText[17] = ini.GetString("stats", "speed", Lang::sortText[11]) + " " + ini.GetString("stats", "iv", Lang::statsLabels[7]);
	Lang::sortText[18] = ini.GetString("summary", "nature", Lang::sortText[18]);
	Lang::sortText[19] = ini.GetString("summary", "level", Lang::sortText[19]);
	Lang::sortText[20] = ini.GetString("summary", "trainerID", Lang::sortText[20]);
	Lang::sortText[21] = ini.GetString("main", "hpType", Lang::sortText[21]);
	Lang::sortText[22] = ini.GetString("summary", "friendship", Lang::sortText[22]);
	Lang::sortText[23] = ini.GetString("summary", "name", Lang::sortText[23]);
	Lang::sortText[24] = ini.GetString("summary", "origTrainer", Lang::sortText[24]);
	Lang::sortText[25] = ini.GetString("summary", "shiny", Lang::sortText[25]);

	// [stats]
	Lang::statsLabels[0] = ini.GetString("stats", "hp", Lang::statsLabels[0]);
	Lang::statsLabels[1] = ini.GetString("stats", "attack", Lang::statsLabels[1]);
	Lang::statsLabels[2] = ini.GetString("stats", "defense", Lang::statsLabels[2]);
	Lang::statsLabels[3] = ini.GetString("stats", "spAtk", Lang::statsLabels[3]);
	Lang::statsLabels[4] = ini.GetString("stats", "spDef", Lang::statsLabels[4]);
	Lang::statsLabels[5] = ini.GetString("stats", "speed", Lang::statsLabels[5]);
	Lang::statsLabels[6] = ini.GetString("stats", "base", Lang::statsLabels[6]);
	Lang::statsLabels[7] = ini.GetString("stats", "iv", Lang::statsLabels[7]);
	Lang::statsLabels[8] = ini.GetString("stats", "ev", Lang::statsLabels[8]);
	Lang::statsLabels[9] = ini.GetString("stats", "total", Lang::statsLabels[9]);

	// [summary]
	Lang::summaryLabels[0]  = ini.GetString("summary", "dexNo", Lang::summaryLabels[0]);
	Lang::summaryLabels[1]  = ini.GetString("summary", "name", Lang::summaryLabels[1]);
	Lang::summaryLabels[2]  = ini.GetString("summary", "level", Lang::summaryLabels[2]);
	Lang::summaryLabels[3]  = ini.GetString("summary", "ability", Lang::summaryLabels[3]);
	Lang::summaryLabels[4]  = ini.GetString("summary", "nature", Lang::summaryLabels[4]);
	Lang::summaryLabels[5]  = ini.GetString("summary", "item", Lang::summaryLabels[5]);
	Lang::summaryLabels[6]  = ini.GetString("summary", "shiny", Lang::summaryLabels[6]);
	Lang::summaryLabels[7]  = ini.GetString("summary", "pokerus", Lang::summaryLabels[7]);
	Lang::summaryLabels[8]  = ini.GetString("summary", "origTrainer", Lang::summaryLabels[8]);
	Lang::summaryLabels[9]  = ini.GetString("summary", "trainerID", Lang::summaryLabels[9]);
	Lang::summaryLabels[10] = ini.GetString("summary", "secretID", Lang::summaryLabels[10]);
	Lang::summaryLabels[11] = ini.GetString("summary", "friendship", Lang::summaryLabels[11]);

	Lang::movesString = ini.GetString("summary", "moves", Lang::movesString);
	Lang::stats = ini.GetString("summary", "stats", Lang::stats);

	// [saveMsg]
	Lang::saveMsgCard = ini.GetString("saveMsg", "saveMsgCard", Lang::saveMsgCard);
	Lang::saveMsgChest = ini.GetString("saveMsg", "saveMsgChest", Lang::saveMsgChest);
	Lang::saveMsgSave = ini.GetString("saveMsg", "saveMsgSave", Lang::saveMsgSave);
	
	// [trainer]
	Lang::trainerText[0] = ini.GetString("summary", "name", Lang::trainerText[0]);
	Lang::trainerText[1] = ini.GetString("summary", "trainerID", Lang::trainerText[1]);
	Lang::trainerText[2] = ini.GetString("summary", "secretID", Lang::trainerText[2]);
	Lang::trainerText[3] = ini.GetString("trainer", "money", Lang::trainerText[3]);
	Lang::trainerText[4] = ini.GetString("trainer", "bp", Lang::trainerText[4]);
	Lang::trainerText[5] = ini.GetString("trainer", "badges", Lang::trainerText[5]);
	Lang::trainerText[6] = ini.GetString("trainer", "playTime", Lang::trainerText[6]);

	// [xMenu]
	Lang::xMenuText[0] = ini.GetString("xMenu", "party", Lang::xMenuText[0]);
	Lang::xMenuText[1] = ini.GetString("xMenu", "options", Lang::xMenuText[1]);
	Lang::xMenuText[2] = ini.GetString("xMenu", "bag", Lang::xMenuText[2]);
	Lang::xMenuText[4] = ini.GetString("main", "save", Lang::xMenuText[4]);
	Lang::xMenuText[5] = ini.GetString("xMenu", "exit", Lang::xMenuText[5]);
}