extern "C" {
#include "./src/lua.h"
#include "./src/lualib.h"
#include "./src/lauxlib.h"
}
#include<iostream>
using namespace std;
int main(){

    lua_State* L = luaL_newstate();
    luaL_dostring(L,"x=42");
    lua_getglobal(L,"x");
    lua_Number x = lua_tonumber(L,1);
    cout<<"number from lua: "<<(int)x<<endl;
    lua_close(L);
        return 0;
}