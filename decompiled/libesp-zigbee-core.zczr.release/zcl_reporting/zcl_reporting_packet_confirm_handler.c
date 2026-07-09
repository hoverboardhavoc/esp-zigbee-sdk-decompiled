/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_packet_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_packet_confirm_handler(int param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  
  if ((param_1 == 0) || (param_2 != 0)) {
    __assert_func(0,0,0,0);
  }
  iVar3 = core_globals_get();
  for (piVar2 = *(int **)(iVar3 + 0xd34); piVar2 + -1 != (int *)0xfffffffc; piVar2 = (int *)*piVar2)
  {
    iVar3 = piVar2[-1];
    bVar1 = *(byte *)(iVar3 + 9);
    if ((bVar1 & 0xf) == 4) {
      *(byte *)(iVar3 + 9) = bVar1 & 0xf0 | 1;
      process_attr_report();
    }
  }
  return;
}

