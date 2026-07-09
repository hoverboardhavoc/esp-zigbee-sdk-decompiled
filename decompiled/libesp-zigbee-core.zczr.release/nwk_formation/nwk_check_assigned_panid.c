/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_formation.o -> nwk_check_assigned_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_check_assigned_panid(uint param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  ushort *puVar5;
  
  iVar2 = core_globals_get();
  iVar2 = nwk_disc_table_lite_get_slot(*(undefined1 *)(iVar2 + 0xba4));
  if ((param_1 - 1 & 0xffff) < 0xfffe) {
    puVar5 = (ushort *)(iVar2 + 4);
    for (cVar4 = '\0'; *(char *)(iVar2 + 2) != cVar4; cVar4 = cVar4 + '\x01') {
      uVar1 = *puVar5;
      puVar5 = puVar5 + 1;
      if (uVar1 == param_1) goto _L0;
    }
    uVar3 = 1;
  }
  else {
_L0:
    uVar3 = 0;
  }
  return uVar3;
}

