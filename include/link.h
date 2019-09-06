#pragma once

struct packed LinkPlayer
{
    u8 unk_0[8];
    u8 name[11];
    u8 unk_13[9];
};

extern struct LinkPlayer gLinkPlayers[];

u8 GetMultiplayerId(void);
