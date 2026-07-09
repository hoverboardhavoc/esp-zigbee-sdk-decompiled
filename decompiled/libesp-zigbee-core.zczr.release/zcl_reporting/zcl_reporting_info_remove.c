/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_info_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_reporting_info_remove(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  zcl_reporting_stop();
  iVar3 = core_globals_get();
  piVar1 = *(int **)(iVar3 + 0xd34);
  if (piVar1 != (int *)0x0) {
    for (; piVar2 = piVar1 + -1, piVar2 != (int *)0xfffffffc; piVar1 = (int *)*piVar1) {
      iVar3 = *piVar2;
      if ((((*(char *)(iVar3 + 1) == *(char *)(param_1 + 1)) &&
           (*(short *)(iVar3 + 4) == *(short *)(param_1 + 4))) &&
          ((*(byte *)(iVar3 + 8) & *(byte *)(param_1 + 8)) != 0)) &&
         ((*(short *)(iVar3 + 6) == *(short *)(param_1 + 6) &&
          (*(short *)(iVar3 + 0x30) == *(short *)(param_1 + 0x30))))) {
        iVar3 = core_globals_get();
        list_remove_node(iVar3 + 0xd34,piVar1);
        mm_free(piVar2);
        zcl_reporting_remove_stored_reporting_info(param_1);
        break;
      }
    }
  }
  iVar3 = zcl_reporting_start();
  return -(uint)(iVar3 != 0);
}

