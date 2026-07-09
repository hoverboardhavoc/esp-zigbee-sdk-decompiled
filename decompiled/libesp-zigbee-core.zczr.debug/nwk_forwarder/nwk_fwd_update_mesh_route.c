/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_update_mesh_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_fwd_update_mesh_route(uint param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = nwk_route_table_find(param_2[1]);
  if (iVar2 != 0) {
    if ((*(ushort *)(iVar2 + 0xe) & 7) == 0) {
      iVar3 = nwk_neighbor_table_get_by_short(*(undefined2 *)(iVar2 + 2));
      if (iVar3 == 0) {
        return 0x2d1;
      }
      uVar5 = *(uint *)(iVar3 + 0xc) & 0x3c0;
      if ((uVar5 != 0x80) && (uVar5 != 0x240)) {
        return 0x2d1;
      }
      if (*(int *)(iVar2 + 4) != -1) {
        *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
      }
      if (*(char *)(iVar2 + 10) != -1) {
        *(char *)(iVar2 + 10) = *(char *)(iVar2 + 10) + '\x01';
      }
      if (*(char *)(iVar3 + 0x18) != -1) {
        *(char *)(iVar3 + 0x18) = *(char *)(iVar3 + 0x18) + '\x01';
      }
      if (((param_1 & 3) == 0) && (iVar4 = nwk_fwd_is_addr_in_realm(*param_2), iVar4 != 0)) {
        *(byte *)((int)param_2 + 7) =
             (*(uint *)(iVar2 + 0xc) & 0x300000) == 0x300000 | *(byte *)((int)param_2 + 7) & 0xfe;
      }
      uVar1 = nwk_neighbor_get_shortaddr(iVar3);
      param_2[2] = uVar1;
      *(byte *)(param_2 + 3) = (byte)(*(uint *)(iVar3 + 0xc) >> 0xd) & 0x1f;
      return 0;
    }
    if (((*(ushort *)(iVar2 + 0xe) & 7) == 1) && (*(char *)(iVar2 + 0xd) != '\0')) {
      return 0xc;
    }
  }
  if ((param_1 & 0xc0) == 0x40) {
    iVar2 = nwk_mesh_route_discovery(0,param_2[1],0x1e);
    if (iVar2 == 0) {
      iVar2 = 0xc;
    }
  }
  else {
    iVar2 = 0x2d1;
  }
  return iVar2;
}

