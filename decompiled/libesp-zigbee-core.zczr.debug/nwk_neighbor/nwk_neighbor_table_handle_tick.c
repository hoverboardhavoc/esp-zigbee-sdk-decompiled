/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_table_handle_tick(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = 0;
_L0:
  iVar2 = nwk_neighbor_table_next(iVar2);
  if (iVar2 == 0) {
    return;
  }
  uVar4 = *(uint *)(iVar2 + 0xc) & 0x3c0;
  if (uVar4 != 0x140) goto _L0;
  goto _L0;
_L0:
  if (uVar4 == 0x40) {
    iVar3 = nwk_get_keepalive_mode();
    bVar1 = iVar3 != 0;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
_L0:
    if ((*(uint *)(iVar2 + 0x14) & 0xfffff) == 0) {
      nwk_neighbor_table_delete(iVar2);
    }
    else {
      *(uint *)(iVar2 + 0x14) =
           *(uint *)(iVar2 + 0x14) & 0xfff00000 |
           (*(uint *)(iVar2 + 0x14) & 0xfffff) + 0xfffff & 0xfffff;
    }
  }
  goto _L0;
}

