#include <stdbool.h>
#include <stdlib.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "database.h"

void registerfuncs(lua_State *L);
void runplugins(lua_State *L);

void fancydie(lua_State *L, char* msg){
	fprintf(stderr, "FATAL ERROR:\n\t%s: %s\n", msg, lua_tostring(L, -1));
	exit(1);
}

int main(int argc, char *argv[]){
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	registerfuncs(L);
	runplugins(L);

	lua_close(L);

	return 0;
}

void registerfuncs(lua_State *L){
	/* Register C functions to the Lua API */
	lua_register(L, "testlua", testlua);
}

void runplugins(lua_State *L){
	/* Run all local plugins */
	// Currently runs only test.lua
	if (luaL_loadfile(L, "test.lua")){
		fancydie(L, "Could not load plugin");
	}
	if (lua_pcall(L, 0, 0, 0)){
		fancydie(L, "Could not execute plugin");
	}
}
