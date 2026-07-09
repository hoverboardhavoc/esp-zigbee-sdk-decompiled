/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_nwk_update_notify_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_mgmt_nwk_update_notify_wrapper(int *param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  byte *pbVar3;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  pcVar1 = (code *)*param_2;
  if (pcVar1 == (code *)0x0) goto _L0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (*param_1 == 0) {
    pbVar3 = (byte *)param_1[1];
    if (pbVar3 == (byte *)0x0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                    ,0x1fa,"esp_zb_zdo_mgmt_nwk_update_notify_wrapper","result->rsp");
      goto _L0;
    }
    uStack_38 = (uint)*pbVar3;
    uStack_34 = *(undefined4 *)(pbVar3 + 4);
    iVar2 = param_1[1];
    uStack_30 = *(undefined4 *)(iVar2 + 8);
    uStack_2c = (uint)*(byte *)(iVar2 + 0xc);
    if (*(char *)(iVar2 + 0xc) != '\0') {
      memcpy((void *)((int)&uStack_2c + 1),(void *)(iVar2 + 0xd),(uint)*(byte *)(iVar2 + 0xc));
    }
  }
  else {
_L0:
    uStack_38 = CONCAT31(uStack_38._1_3_,0x85);
  }
  (*pcVar1)(&uStack_38,param_2[1]);
_L0:
  free(param_2);
  return;
}

