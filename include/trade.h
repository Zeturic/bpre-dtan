#pragma once

struct PACKED Struct2031DAC
{
    u8 unk_0[238];
    bool8 isLinkTrade;
    u8 unk_EF[33];
};

struct PACKED InGameTrade
{
    u8 name[11];
    u8 unk_B[32];
    u8 otName[11];
    u8 unk_36[6];
};

extern struct Struct2031DAC *gUnknown_02031DAC;
extern const struct InGameTrade gIngameTrades[];
extern u8 gUnknown_02031DA4[2];
