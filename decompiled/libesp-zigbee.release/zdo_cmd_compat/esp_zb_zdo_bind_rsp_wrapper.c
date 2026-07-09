/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_bind_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_bind_rsp_wrapper(int *param_1,int *param_2)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  code *pcVar5;
  
  pcVar5 = (code *)*param_2;
  if (pcVar5 != (code *)0x0) {
    if (*param_1 == 0) {
      puVar4 = (undefined1 *)param_1[1];
      piVar2 = param_2;
      if (puVar4 == (undefined1 *)0x0) {
        piVar2 = (int *)__assert_func(0,0,0,0);
      }
      iVar3 = piVar2[1];
      uVar1 = *puVar4;
    }
    else {
      if (*param_1 != 7) goto _L0;
      iVar3 = param_2[1];
      uVar1 = 0x85;
    }
    (*pcVar5)(uVar1,iVar3);
  }
_L0:
  free(param_2);
  return;
}

