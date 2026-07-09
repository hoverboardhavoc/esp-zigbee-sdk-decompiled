/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_update_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_table_update_route(undefined2 *param_1,undefined2 param_2)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = param_1[7];
  param_1[1] = param_2;
  param_1[7] = uVar2 & 0xfff8;
  if ((uVar2 & 7) == 1) {
    bVar1 = *(byte *)((int)param_1 + 0xf);
    param_1[7] = param_1[7] & 0xfeff;
    nwk_fwd_handle_route_disc_done(*param_1,0);
    if ((bVar1 & 1) != 0) {
      nwk_mesh_route_discovery_done(*param_1,0,0);
    }
  }
  return;
}

