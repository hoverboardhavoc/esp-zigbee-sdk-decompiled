/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_info_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_info_free(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  zcl_reporting_stop();
  while (iVar1 = core_globals_get(), *(int *)(iVar1 + 0xd34) != 0) {
    iVar1 = core_globals_get();
    puVar2 = *(undefined4 **)(iVar1 + 0xd34);
    if (puVar2 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar1 + 0xd34) = *puVar2;
      *puVar2 = puVar2;
    }
    mm_free(puVar2 + -1);
  }
  return;
}

