/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_power_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_power_desc_rsp_wrapper(int *param_1,int *param_2)

{
  code *pcVar1;
  undefined1 *puVar2;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  pcVar1 = (code *)*param_2;
  if (pcVar1 != (code *)0x0) {
    uStack_18 = 0;
    uStack_14 = 0;
    if (*param_1 == 0) {
      puVar2 = (undefined1 *)param_1[1];
      if (puVar2 == (undefined1 *)0x0) {
        __assert_func(0,0,0,0);
      }
      uStack_18 = CONCAT31(uStack_18._1_3_,*puVar2);
      uStack_18 = CONCAT22(*(undefined2 *)(puVar2 + 2),(undefined2)uStack_18);
      uStack_14 = *(undefined2 *)(puVar2 + 4);
    }
    else {
      uStack_18 = 0x85;
    }
    (*pcVar1)(&uStack_18,param_2[1]);
  }
  free(param_2);
  return;
}

