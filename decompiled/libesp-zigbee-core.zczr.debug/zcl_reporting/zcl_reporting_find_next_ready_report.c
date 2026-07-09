/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_find_next_ready_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_reporting_find_next_ready_report(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  uVar1 = milli_timer_get_now();
  iVar2 = core_globals_get();
  puVar3 = *(undefined4 **)(iVar2 + 0xd34);
  while( true ) {
    piVar4 = puVar3 + -1;
    if (piVar4 == (int *)0xfffffffc) {
      return 0;
    }
    if ((((piVar4 != (int *)0x0) && (iVar2 = *piVar4, (*(byte *)(iVar2 + 9) & 0xf) == 3)) &&
        (*(uint *)(iVar2 + 0xc) < uVar1)) &&
       (((*(char *)(iVar2 + 1) == *(char *)(param_1 + 1) &&
         (*(short *)(iVar2 + 4) == *(short *)(param_1 + 4))) &&
        ((*(short *)(iVar2 + 2) == *(short *)(param_1 + 2) &&
         (*(short *)(iVar2 + 0x30) == *(short *)(param_1 + 0x30))))))) break;
    puVar3 = (undefined4 *)*puVar3;
  }
  *(byte *)(iVar2 + 9) = *(byte *)(iVar2 + 9) & 0xf0 | 4;
  return *piVar4;
}

