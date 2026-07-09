/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_conflicts.o -> nwk_change_child_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_change_child_address(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = nwk_neighbor_table_get_by_short();
  if ((iVar1 != 0) && (uVar3 = *(uint *)(iVar1 + 0xc), (uVar3 & 3) == 2)) {
    if ((-1 < (int)(uVar3 << 0x14)) && (((uVar3 & 0x3c0) != 0x140 && ((uVar3 & 0x3c0) != 0x180)))) {
      uVar3 = *(uint *)(iVar1 + 0xc);
      *(uint *)(iVar1 + 0xc) = uVar3 & 0xfffffc3f | 0x200;
      if ((uVar3 & 0x400) == 0) {
        return;
      }
      nwk_child_address_change_request();
      return;
    }
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffc3f | 0x1c0;
    uVar2 = nwk_neighbor_get_shortaddr();
    log_write(2,"nwk_conflicts.c","Address 0x%04hxconflicts with joining child, skip",uVar2);
  }
  return;
}

