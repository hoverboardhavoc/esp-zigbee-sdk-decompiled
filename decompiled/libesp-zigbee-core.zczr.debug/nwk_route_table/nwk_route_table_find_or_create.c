/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * nwk_route_table_find_or_create(undefined4 param_1)

{
  int iVar1;
  undefined2 *__s;
  
  iVar1 = core_globals_get();
  __s = (undefined2 *)route_table_find(iVar1 + 0xc58,param_1);
  if ((__s == (undefined2 *)0x0) &&
     (__s = (undefined2 *)route_table_new(iVar1 + 0xc58), __s != (undefined2 *)0x0)) {
    memset(__s,0,0x10);
    *__s = (short)param_1;
    __s[1] = 0xffff;
    __s[7] = __s[7] & 0xfff8 | 3;
  }
  return __s;
}

