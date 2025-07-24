/*
THIS IS CREATE BY ME KALL, I MADE THIS TO SHARE FOR FREE, NOT TO BUY AND SELL PLEASE DO NOT SELL THIS SCRIPT
THANK YOU FOR USING MY SCRIPT, I HOPE THIS SCRIPT CAN HELP YOU TO MAKE YOUR OWN SERVER BETTER
CREDITS: KALL
*/
#if defined _achievement_inc
    #endinput
#endif
#define _achievement_inc

new PlayerText:acipment[MAX_PLAYERS][5];
new AchievementTimer[MAX_PLAYERS];

stock Achievement_Init(playerid)
{
    acipment[playerid][0] = CreatePlayerTextDraw(playerid, 523.000, 6.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, acipment[playerid][0], 114.000, 43.000);
    PlayerTextDrawAlignment(playerid, acipment[playerid][0], 1);
    PlayerTextDrawColor(playerid, acipment[playerid][0], 1887473919);
    PlayerTextDrawSetShadow(playerid, acipment[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, acipment[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, acipment[playerid][0], 255);
    PlayerTextDrawFont(playerid, acipment[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, acipment[playerid][0], 1);

    acipment[playerid][1] = CreatePlayerTextDraw(playerid, 526.000, 12.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, acipment[playerid][1], 27.000, 32.000);
    PlayerTextDrawAlignment(playerid, acipment[playerid][1], 1);
    PlayerTextDrawColor(playerid, acipment[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, acipment[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, acipment[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, acipment[playerid][1], 255);
    PlayerTextDrawFont(playerid, acipment[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, acipment[playerid][1], 1);

    acipment[playerid][2] = CreatePlayerTextDraw(playerid, 527.000, 14.000, "_");
    PlayerTextDrawTextSize(playerid, acipment[playerid][2], 25.000, 29.000);
    PlayerTextDrawAlignment(playerid, acipment[playerid][2], 1);
    PlayerTextDrawColor(playerid, acipment[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, acipment[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, acipment[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, acipment[playerid][2], 255);
    PlayerTextDrawFont(playerid, acipment[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, acipment[playerid][2], 0);

    PlayerTextDrawSetPreviewRot(playerid, acipment[playerid][2], 0.0, 0.0, 0.0, 1.0);
    PlayerTextDrawSetPreviewVehCol(playerid, acipment[playerid][2], 0, 0);

    acipment[playerid][3] = CreatePlayerTextDraw(playerid, 558.000, 11.000, "Achievment Unlocked!");
    PlayerTextDrawLetterSize(playerid, acipment[playerid][3], 0.180, 0.899);
    PlayerTextDrawAlignment(playerid, acipment[playerid][3], 1);
    PlayerTextDrawColor(playerid, acipment[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, acipment[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, acipment[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, acipment[playerid][3], 150);
    PlayerTextDrawFont(playerid, acipment[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, acipment[playerid][3], 1);

    acipment[playerid][4] = CreatePlayerTextDraw(playerid, 565.000, 23.000, "PEKERJA KERAS!");
    PlayerTextDrawLetterSize(playerid, acipment[playerid][4], 0.220, 1.500);
    PlayerTextDrawAlignment(playerid, acipment[playerid][4], 1);
    PlayerTextDrawColor(playerid, acipment[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, acipment[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, acipment[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, acipment[playerid][4], 150);
    PlayerTextDrawFont(playerid, acipment[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, acipment[playerid][4], 1);
}

stock Achievement(playerid, const name[], skinid)
{
    PlayerTextDrawSetString(playerid, acipment[playerid][4], name);
    PlayerTextDrawSetPreviewModel(playerid, acipment[playerid][2], skinid);

    for (new i = 0; i < 5; i++)
        PlayerTextDrawShow(playerid, acipment[playerid][i]);

    if (AchievementTimer[playerid])
        KillTimer(AchievementTimer[playerid]);

    AchievementTimer[playerid] = SetTimerEx("HideAchievement", 5000, false, "i", playerid);
}

forward HideAchievement(playerid);
public HideAchievement(playerid)
{
    for (new i = 0; i < 5; i++)
        PlayerTextDrawHide(playerid, acipment[playerid][i]);

    AchievementTimer[playerid] = 0;
}
