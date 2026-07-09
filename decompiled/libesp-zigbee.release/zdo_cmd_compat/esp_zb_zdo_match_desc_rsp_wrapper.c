/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_match_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_match_desc_rsp_wrapper(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  
  if ((*(char *)((int)param_2 + 9) != '\0') || ((code *)*param_2 == (code *)0x0)) goto _L0;
  puVar4 = *(undefined1 **)(param_1 + 4);
  if (puVar4 == (undefined1 *)0x0) {
    uVar1 = 0x85;
_L0:
    uVar3 = 0xff;
    uVar2 = 0xffff;
  }
  else {
    uVar1 = *puVar4;
    if (puVar4[4] == '\0') goto _L0;
    uVar2 = *(undefined2 *)(puVar4 + 2);
    uVar3 = **(undefined1 **)(puVar4 + 8);
  }
  (*(code *)*param_2)(uVar1,uVar2,uVar3,param_2[1]);
_L0:
  *(undefined1 *)((int)param_2 + 9) = 1;
  if ((*(char *)(param_2 + 2) != '\0') && (*(int *)(param_1 + 4) != 0)) {
    return;
  }
  free(param_2);
  return;
}

