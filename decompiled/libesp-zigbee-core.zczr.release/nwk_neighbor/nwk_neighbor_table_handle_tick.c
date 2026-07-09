/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_table_handle_tick(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = 0;
  while (iVar1 = nwk_neighbor_table_next(iVar1), iVar1 != 0) {
    uVar3 = *(uint *)(iVar1 + 0xc) & 0x3c0;
    if ((uVar3 == 0x140) || ((uVar3 == 0x40 && (iVar2 = nwk_get_keepalive_mode(), iVar2 != 0)))) {
      uVar3 = *(uint *)(iVar1 + 0x14) & 0xfffff;
      if (uVar3 == 0) {
        nwk_neighbor_table_delete(iVar1);
      }
      else {
        *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xfff00000 | uVar3 + 0xfffff & 0xfffff;
      }
    }
  }
  return;
}

