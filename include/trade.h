#pragma once

struct PACKED Struct2031DAC
{
    u8 unk_0[238];
    bool8 isLinkTrade;
    u8 unk_EF[33];
};

extern struct Struct2031DAC *sTradeAnim;
extern u8 gSelectedTradeMonPositions[2];
