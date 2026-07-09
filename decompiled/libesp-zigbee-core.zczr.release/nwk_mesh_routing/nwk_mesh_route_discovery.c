/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_route_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_mesh_route_discovery(int param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = 2;
  if ((param_1 != 0) == 0xfff7 < param_2) {
    uVar3 = nwk_get_short_address();
    iVar2 = core_globals_get();
    cVar1 = *(char *)(iVar2 + 0x9da);
    *(char *)(iVar2 + 0x9da) = cVar1 + '\x01';
    iVar2 = nwk_mesh_route_discovery_update(cVar1,param_1,0,uVar3,param_2);
    if (iVar2 == 0) {
      nwk_mesh_send_rreq(param_2,cVar1,param_3,param_1);
    }
  }
  return iVar2;
}

