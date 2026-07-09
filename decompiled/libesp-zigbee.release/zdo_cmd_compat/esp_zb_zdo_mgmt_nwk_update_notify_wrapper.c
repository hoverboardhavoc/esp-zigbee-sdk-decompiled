/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_nwk_update_notify_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_mgmt_nwk_update_notify_wrapper(int *param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  code *pcVar2;
  undefined1 auStack_38 [4];
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  byte bStack_2c;
  undefined1 auStack_2b [27];
  
  pcVar2 = (code *)*param_2;
  if (pcVar2 != (code *)0x0) {
    memset(auStack_38,0,0x28);
    if (*param_1 == 0) {
      puVar1 = (undefined1 *)param_1[1];
      if (puVar1 == (undefined1 *)0x0) {
        puVar1 = (undefined1 *)__assert_func(0,0,0);
      }
      auStack_38[0] = *puVar1;
      bStack_2c = puVar1[0xc];
      uStack_34 = *(undefined4 *)(puVar1 + 4);
      uStack_30 = *(undefined2 *)(puVar1 + 8);
      uStack_2e = *(undefined2 *)(puVar1 + 10);
      if (bStack_2c != 0) {
        memcpy(auStack_2b,puVar1 + 0xd,(uint)bStack_2c);
      }
    }
    else {
      auStack_38[0] = 0x85;
    }
    (*pcVar2)(auStack_38,param_2[1]);
  }
  free(param_2);
  return;
}

