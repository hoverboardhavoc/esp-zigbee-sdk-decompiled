/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_power_desc_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_power_desc_rsp_wrapper(int *param_1,int *param_2)

{
  byte *pbVar1;
  code *pcVar2;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  pcVar2 = (code *)*param_2;
  if (pcVar2 == (code *)0x0) goto _L0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (*param_1 == 0) {
    pbVar1 = (byte *)param_1[1];
    if (pbVar1 == (byte *)0x0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                    ,300,"esp_zb_zdo_power_desc_rsp_wrapper","result->rsp");
      goto _L0;
    }
    uStack_18 = CONCAT22(*(undefined2 *)(pbVar1 + 2),(ushort)*pbVar1);
    uStack_14 = *(undefined2 *)(pbVar1 + 4);
  }
  else {
_L0:
    uStack_18 = CONCAT31(uStack_18._1_3_,0x85);
  }
  (*pcVar2)(&uStack_18,param_2[1]);
_L0:
  free(param_2);
  return;
}

