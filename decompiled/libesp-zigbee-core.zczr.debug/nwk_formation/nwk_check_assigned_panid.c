/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_check_assigned_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_check_assigned_panid(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = core_globals_get();
  iVar1 = nwk_disc_table_lite_get_slot(*(undefined1 *)(iVar1 + 0xba4));
  if ((param_1 - 1 & 0xffff) < 0xfffe) {
    for (uVar3 = 0; uVar3 < *(byte *)(iVar1 + 2); uVar3 = uVar3 + 1 & 0xff) {
      if (*(ushort *)(uVar3 * 2 + iVar1 + 4) == param_1) {
        return 0;
      }
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

