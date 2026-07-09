/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> zdo_mgmt_leave_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_leave_confirm(undefined1 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = core_globals_get();
  puVar2 = (undefined4 *)(iVar1 + 0xce0);
  puVar3 = *(undefined4 **)(iVar1 + 0xce0);
  do {
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    if (((*(byte *)(puVar3 + 7) & 1) != 0) && (*(short *)(puVar3 + -1) == 0x34)) {
      if ((puVar3[1] == *(int *)(param_1 + 4)) && (puVar3[2] == *(int *)(param_1 + 8))) {
        *puVar2 = *puVar3;
        if (puVar3 == (undefined4 *)0x4) {
          return;
        }
        if ((code *)puVar3[5] != (code *)0x0) {
          (*(code *)puVar3[5])(*param_1,puVar3[6]);
        }
        if (puVar3 == (undefined4 *)0x4) {
          return;
        }
        mm_free();
        return;
      }
    }
    puVar2 = puVar3;
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}

