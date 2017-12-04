#include <cstdlib>
#include "gameserver/game.h"
#include "common/syspath.h"
#include "network/networkmain.h"
#include "inetworkmodule.h"
#include "servermodule.h"

int main(int argc, char *argv[])
{
	Game game;

	// ×¢²á¶¯Ì¬¿â
	NetworkDLL::Register(&game, NETWORK_MODULE);

	// Register Modules
	game.RegisterModule(SERVER_MODULE, new ServerModule());

	// Run
	GameConfig config;
	config.loop_interval = 8;
	config.work_path = argv[0];
	SysPath::Up(&config.work_path);
	game.Run(config);

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}
