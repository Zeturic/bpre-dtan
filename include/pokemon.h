#pragma once

#define MON_DATA_NICKNAME           2

struct PACKED Pokemon
{
    u8 unk_0[100];
};

extern struct Pokemon gPlayerParty[];
extern struct Pokemon gEnemyParty[];

u32 GetMonData(struct Pokemon *mon, s32 field, u8 *data);
