#include "global.h"
#include "event_data.h"
#include "link.h"
#include "pokemon.h"
#include "string_util.h"
#include "trade.h"

void TradeBufferOTnameAndNicknames(void)
{
    /*Sets the variable strings printed on the
     *actual trading screen. For use in strings
     *like "[Pokemon] will be sent to [Trainer]."
     */
    u8 mpId;
    u8 name[20];

    if (sTradeAnim->isLinkTrade)
    {
        mpId = GetMultiplayerId();
        StringCopy(gStringVar1, gLinkPlayers[mpId ^ 1].name);
        GetMonData(&gEnemyParty[gSelectedTradeMonPositions[1] % PARTY_SIZE], MON_DATA_NICKNAME, name);
        StringCopy_Nickname(gStringVar3, name);
        GetMonData(&gPlayerParty[gSelectedTradeMonPositions[0]], MON_DATA_NICKNAME, name);
        StringCopy_Nickname(gStringVar2, name);
    }
    else
    {
        if (gSpecialVar_0x8004 != CUSTOM_TRADER_NAME)
            GetMonData(&gEnemyParty[0], MON_DATA_OT_NAME, gStringVar1);

        GetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, name);
        StringCopy_Nickname(gStringVar3, name);
        GetMonData(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, name);
        StringCopy_Nickname(gStringVar2, name);
    }
}
