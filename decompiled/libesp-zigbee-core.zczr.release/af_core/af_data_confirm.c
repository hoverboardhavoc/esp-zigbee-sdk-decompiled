/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_data_confirm(int param_1)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 == 0) {
    param_1 = af_data_confirm_part_0();
  }
  iVar4 = core_globals_get();
  piVar2 = *(int **)(iVar4 + 0xca4);
  if (piVar2 != (int *)0x0) {
    for (; piVar3 = piVar2 + -3, piVar3 != (int *)0xfffffff4; piVar2 = (int *)*piVar2) {
      if (*piVar3 == *(int *)(param_1 + 0x14)) {
        iVar4 = core_globals_get();
        list_remove_node(iVar4 + 0xca4,piVar2);
        sVar1 = *(short *)(param_1 + 0xe);
        if ((sVar1 == 0x104) || (sVar1 == -0x3fa2)) {
          zcl_confirm_handler(param_1,piVar2 + -2);
        }
        else if (sVar1 == 0) {
          zdo_confirm_handler(param_1,piVar2 + -2);
        }
        mm_free(piVar3);
        break;
      }
    }
  }
  zmsg_free(*(undefined4 *)(param_1 + 0x14));
  return;
}

