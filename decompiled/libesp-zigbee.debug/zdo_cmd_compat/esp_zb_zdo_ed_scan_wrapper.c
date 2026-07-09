/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_ed_scan_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_ed_scan_wrapper(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    puVar2 = (undefined4 *)0x0;
    if (*(short *)(param_2 + 9) != 0) {
      puVar2 = param_2 + 1;
    }
    if ((code *)*param_2 != (code *)0x0) {
      (*(code *)*param_2)(0,puVar2);
    }
    free(param_2);
  }
  else {
    uVar1 = *(ushort *)(param_2 + 9);
    uVar3 = (uint)uVar1;
    if (uVar3 < 0x10) {
      *(undefined1 *)((int)param_2 + uVar3 * 2 + 4) = *(undefined1 *)(param_1 + 1);
      *(undefined1 *)((int)param_2 + uVar3 * 2 + 5) = *(undefined1 *)(param_1 + 2);
      *(ushort *)(param_2 + 9) = uVar1 + 1;
    }
  }
  return;
}

