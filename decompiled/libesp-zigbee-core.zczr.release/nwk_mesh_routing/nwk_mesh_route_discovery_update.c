/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_route_discovery_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
nwk_mesh_route_discovery_update
          (undefined4 param_1,int param_2,uint param_3,undefined4 param_4,undefined2 param_5,
          int param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = nwk_route_disc_table_find_or_create(param_4,param_1);
  if (iVar1 == 0) {
_L0:
    uVar3 = 1;
  }
  else {
    if (*(byte *)(iVar1 + 0xb) <= param_3) {
      return 0xffffffff;
    }
    *(char *)(iVar1 + 0xb) = (char)param_3;
    *(undefined2 *)(iVar1 + 2) = param_5;
    if ((((param_2 == 0) && (*(int *)(iVar1 + 4) == 0)) &&
        (iVar2 = nwk_get_short_address(0xffffffff), iVar2 != param_6)) &&
       ((iVar2 = nwk_neighbor_table_get_by_short(param_6), iVar2 == 0 ||
        ((*(uint *)(iVar2 + 0xc) & 0x3c0) != 0x40)))) {
      iVar2 = nwk_route_table_find_or_create(param_6);
      if (iVar2 == 0) {
        nwk_route_disc_table_delete(iVar1);
        goto _L0;
      }
      nwk_route_start_discovery(iVar1);
    }
    uVar3 = 0;
  }
  return uVar3;
}

