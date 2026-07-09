/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_start(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = core_globals_get();
  if (*(char *)(iVar3 + 0xd20) == '\0') {
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar3 + 0xd20) = 1;
    iVar3 = core_globals_get();
    for (puVar1 = *(undefined4 **)(iVar3 + 0xd34); puVar2 = puVar1 + -1,
        puVar2 != (undefined4 *)0xfffffffc; puVar1 = (undefined4 *)*puVar1) {
      if (puVar2 != (undefined4 *)0x0) {
        process_attr_report(*puVar2);
      }
    }
    uVar4 = 0;
  }
  else {
    uVar4 = 3;
  }
  return uVar4;
}

