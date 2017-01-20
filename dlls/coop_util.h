#ifndef COOP_UTIL_H
#define COOP_UTIL_H
extern cvar_t cvar_allow_gravgun;
extern cvar_t cvar_allow_ar2;
extern cvar_t cvar_ar2_mp5;
extern cvar_t cvar_ar2_bullets;
extern cvar_t cvar_ar2_balls;
extern cvar_t cvar_wresptime;
extern cvar_t cvar_iresptime;

extern cvar_t cvar_gibtime;
extern cvar_t cvar_hgibcount;
extern cvar_t cvar_agibcount;

extern cvar_t mp_gravgun_players;
extern cvar_t mp_coop;
extern cvar_t mp_coop_changelevel;
extern cvar_t mp_coop_nofriendlyfire;
extern cvar_t mp_coop_disabledmap;
extern cvar_t mp_coop_checkpoints;

extern cvar_t mp_unduck;
extern cvar_t mp_semclip;
extern cvar_t mp_coop_reconnect_hack;
extern cvar_t mp_coop_noangry;
extern cvar_t mp_spectator;

extern cvar_t sentences_txt;
extern cvar_t materials_txt;

extern bool g_fSavedDuck;
extern bool g_fPause;

struct SavedCoords
{
	char ip[32][32];
	Vector origin[32];
	Vector angles[32];
	char landmark[32];
	Vector triggerorigin;
	Vector triggerangles;
	Vector offset;
	int iCount;
	bool valid;
	bool validoffset;
	bool validspawnpoint;
	int changeback;
	bool trainsaved;
	Vector trainoffset;
	char trainglobal[256];
	int trainuser1;
	bool fUsed;
	bool fDuck;
};



void UTIL_CoopValidateOffset( void );
void UTIL_CleanSpawnPoint( Vector origin, float radius );
char *UTIL_CoopPlayerName( CBaseEntity *pPlayer );

bool UTIL_CoopGetSpawnPoint( Vector *point, Vector *angles);

bool UTIL_CoopRestorePlayerCoords(CBaseEntity *player, Vector *origin, Vector *angles );
void UTIL_CoopSaveTrain( CBaseEntity *pPlayer, SavedCoords *coords);
Vector UTIL_FixupSpawnPoint(Vector spawn);
void UTIL_CoopActivateChangeLevel( CBaseEntity *pTrigger );

#ifdef PLAYER_H
void UTIL_CoopKickPlayer(CBaseEntity *pPlayer);
bool UTIL_CoopIsBadPlayer( CBaseEntity *plr );
void UTIL_CoopNewCheckpoint( entvars_t *pevPlayer );
CBaseEntity *UTIL_CoopGetPlayerTrain( CBaseEntity *pPlayer);
void UTIL_CoopMenu( CBasePlayer *pPlayer );
void UTIL_SpawnPlayer( CBasePlayer *pPlayer );
void UTIL_BecomeSpectator( CBasePlayer *pPlayer );
void UTIL_CoopCheckpointMenu( CBasePlayer *pPlayer );
void UTIL_CoopVoteMenu( CBasePlayer *pPlayer );
void UTIL_CoopShowMenu( CBasePlayer *pPlayer, const char *title, int count, const char **slot, signed char time = -1 );
extern int g_iMenu;

// Show to all spawned players: voting, etc..
class GlobalMenu
{
public:

	int m_iConfirm;
	int m_iVoteCount;
	int m_iMaxCount;
	int m_iBanCount;
	float m_flTime;
	const char *maps[5];
	int votes[5];
	CBaseEntity *triggers[5];
	EHANDLE m_pTrigger;
	EHANDLE m_pPlayer;
	void VoteMenu( CBasePlayer *pPlayer );
	void ConfirmMenu( CBasePlayer *pPlayer, CBaseEntity *trigger, const char *mapname );
	void ShowGlobalMenu( const char *title, int count, const char **menu );
	void Process( CBasePlayer *pPlayer, int imenu );
};

extern GlobalMenu g_GlobalMenu;
#endif
extern struct SavedCoords g_SavedCoords, s_SavedCoords;

#endif // COOP_UTIL_H

