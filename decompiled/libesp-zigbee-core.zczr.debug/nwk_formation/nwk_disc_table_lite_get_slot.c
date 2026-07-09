/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_disc_table_lite_get_slot
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_disc_table_lite_get_slot(uint param_1)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 < 2) {
    iVar3 = core_globals_get();
    return iVar3 + 0xb2c + param_1 * 0x3c;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_formation.c",0x56,
                "nwk_disc_table_lite_get_slot","slot < NWK_DISC_TABLE_LITE_SLOT_NR");
  iVar3 = core_globals_get();
  uVar1 = *(undefined1 *)(iVar3 + 0xba4);
  iVar3 = core_globals_get();
  bVar2 = *(char *)(iVar3 + 0xba4) + 1U & 1;
  iVar3 = nwk_disc_table_lite_get_slot(uVar1);
  iVar4 = nwk_disc_table_lite_get_slot(bVar2);
  if (*(byte *)(iVar4 + 2) < *(byte *)(iVar3 + 2)) {
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + 0xba4) = bVar2;
  }
  iVar3 = core_globals_get();
  iVar3 = nwk_disc_table_lite_get_slot(*(undefined1 *)(iVar3 + 0xba4));
  return iVar3;
}

