/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_info_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_reporting_info_find(uint param_1,uint param_2,byte param_3,uint param_4,uint param_5)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = core_globals_get();
  piVar2 = *(int **)(iVar1 + 0xd34);
  while( true ) {
    if (piVar2 + -1 == (int *)0xfffffffc) {
      return 0;
    }
    iVar1 = piVar2[-1];
    if ((((*(byte *)(iVar1 + 1) == param_1) && (*(ushort *)(iVar1 + 4) == param_2)) &&
        ((param_3 & *(byte *)(iVar1 + 8)) != 0)) &&
       ((*(ushort *)(iVar1 + 6) == param_4 && (*(ushort *)(iVar1 + 0x30) == param_5)))) break;
    piVar2 = (int *)*piVar2;
  }
  return iVar1;
}

