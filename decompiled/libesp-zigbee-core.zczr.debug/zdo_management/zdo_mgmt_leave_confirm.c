/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_leave_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_leave_confirm(undefined1 *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = core_globals_get();
  piVar3 = (int *)(iVar1 + 0xce0);
  do {
    do {
      piVar2 = piVar3;
      piVar3 = (int *)*piVar2;
      if (piVar3 == (int *)0x0) {
        return;
      }
    } while (((*(byte *)(piVar3 + 7) & 1) == 0) || (*(short *)(piVar3 + -1) != 0x34));
  } while ((piVar3[1] != *(int *)(param_1 + 4)) || (piVar3[2] != *(int *)(param_1 + 8)));
  *piVar2 = *piVar3;
  zdo_mgmt_req_finish(piVar3 + -1,*param_1);
  return;
}

