/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_active_scan_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_active_scan_wrapper(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
    puVar4 = (undefined4 *)0x0;
    if (*(char *)(param_2 + 0x71) != '\0') {
      puVar4 = param_2 + 1;
    }
    if ((code *)*param_2 != (code *)0x0) {
      (*(code *)*param_2)(0,puVar4);
    }
    free(param_2);
  }
  else {
    uVar3 = (uint)*(byte *)(param_2 + 0x71);
    if (uVar3 < 0x20) {
      for (iVar1 = 0; iVar1 < (int)uVar3; iVar1 = iVar1 + 1) {
        iVar2 = memcmp((void *)((int)param_2 + iVar1 * 0xe + 7),(void *)(param_1 + 4),8);
        if (iVar2 == 0) {
          return;
        }
      }
      ezb_active_scan_result_to_esp(param_1,(int)param_2 + uVar3 * 0xe + 4);
      *(char *)(param_2 + 0x71) = *(char *)(param_2 + 0x71) + '\x01';
    }
  }
  return;
}

