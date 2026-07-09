/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_scenes_get_scene_membership_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_scenes_get_scene_membership_resp_handler(int param_1,code *param_2)

{
  undefined1 uVar1;
  undefined1 auStack_3c [32];
  undefined1 uStack_1c;
  undefined2 uStack_1a;
  undefined1 uStack_18;
  undefined4 uStack_14;
  
  memset(auStack_3c,0,0x2c);
  convert_to_esp_zb_zcl_cmd_info(auStack_3c,*(undefined4 *)(param_1 + 8));
  auStack_3c[0] = *(undefined1 *)(param_1 + 0xc);
  uStack_1c = *(undefined1 *)(param_1 + 0xd);
  uStack_1a = *(undefined2 *)(param_1 + 0xe);
  uStack_18 = *(undefined1 *)(param_1 + 0x10);
  uStack_14 = *(undefined4 *)(param_1 + 0x14);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x14,auStack_3c);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 0x18) = uVar1;
  }
  return;
}

