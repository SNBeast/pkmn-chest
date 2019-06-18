#ifndef CARD_SAVES_H
#define CARD_SAVES_H

#include "saves/auxspi.h"

extern auxspi_extra card_type;
extern sNDSHeader nds;
extern char gamename[13];
extern char gameid[5];

bool updateCardInfo(void);
bool updateCardInfo(sNDSHeader* nds, char* gameid, char* gamename, auxspi_extra* card_type);

void dumpSave(void);

#endif
