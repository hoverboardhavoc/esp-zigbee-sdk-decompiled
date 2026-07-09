/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_update_neighbor
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_mesh_update_neighbor(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  sVar1 = *(short *)(param_1 + 2);
  iVar2 = nwk_neighbor_table_get_by_short(sVar1);
  if (iVar2 == 0) {
    iVar2 = nwk_neighbor_table_new(1);
    if (iVar2 == 0) {
      return 0;
    }
    iVar3 = nwk_address_by_short(sVar1,1,iVar2);
    if (iVar3 != 0) {
      nwk_neighbor_table_delete(iVar2);
      return 0;
    }
  }
  iVar3 = nwk_neighbor_get_incoming_cost(iVar2);
  if (iVar3 == 0) {
    *(uint *)(iVar2 + 0xc) =
         *(uint *)(iVar2 + 0xc) & 0xfffc1fff | (*(byte *)(param_1 + 8) & 0x1f) << 0xd;
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x19) = *(undefined1 *)(iVar3 + 0xa25);
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar2 + 0x18) = *(undefined1 *)(iVar3 + 0xa25);
    nwk_neighbor_update_lqa(iVar2,*(undefined1 *)(param_1 + 9),(int)*(char *)(param_1 + 10));
    uVar4 = *(uint *)(iVar2 + 0xc);
    *(uint *)(iVar2 + 0xc) = uVar4 & 0xfffffffc | (uint)(sVar1 != 0);
    uVar4 = uVar4 & 0xfffffc3c | (uint)(sVar1 != 0);
    *(uint *)(iVar2 + 0xc) = uVar4 | 0x80;
    *(uint *)(iVar2 + 0xc) = uVar4 | 0x1c000080;
  }
  else {
    iVar3 = nwk_neighbor_get_outgoing_cost(iVar2);
    if (iVar3 == 0) {
      iVar2 = 0;
    }
  }
  return iVar2;
}

