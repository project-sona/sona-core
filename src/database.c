#include "database.h"
#include <stdio.h>

int testlua(lua_State *L){
	printf("This is the testlua function");
	return 0; // number of arguments
}
