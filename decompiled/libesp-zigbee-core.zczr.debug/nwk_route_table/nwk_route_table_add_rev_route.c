/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_add_rev_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_route_table_add_rev_route(uint param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 0xfff8) {
    if (param_2 < 0xfff8) {
      if (param_1 == param_2) {
        uVar2 = 2;
      }
      else {
        iVar1 = nwk_route_table_find_or_create();
        if (iVar1 == 0) {
          uVar2 = 1;
        }
        else {
          nwk_route_table_update_rev_route(param_2,param_3);
          uVar2 = 0;
        }
      }
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

