#include "global.h"
#include "event_data.h"
#include "link.h"
#include "pokemon.h"
#include "string_util.h"
#include "trade.h"

void SetTradeSceneStrings(void)
{
    /*Sets the variable strings printed on the
     *actual trading screen. For use in strings
     *like "[Pokemon] will be sent to [Trainer]."
     */
    u8 mpId;
    u8 name[20];
    const struct InGameTrade *ingameTrade;

    if (gUnknown_02031DAC->isLinkTrade)
    {
        mpId = GetMultiplayerId();
        StringCopy(gStringVar1, gLinkPlayers[mpId ^ 1].name);
        GetMonData(&gEnemyParty[gUnknown_02031DA4[1] % PARTY_SIZE], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar3, name);
        GetMonData(&gPlayerParty[gUnknown_02031DA4[0]], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
    else
    {
        ingameTrade = &gIngameTrades[gSpecialVar_0x8004];
        StringCopy(gStringVar1, ingameTrade->otName);
        StringCopy10(gStringVar3, ingameTrade->name);
        GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
}
