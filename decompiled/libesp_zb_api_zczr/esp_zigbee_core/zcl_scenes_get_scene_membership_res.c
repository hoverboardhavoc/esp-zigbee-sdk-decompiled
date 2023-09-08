/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_get_scene_membership_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_get_scene_membership_res(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint auStack_38 [7];
  byte bStack_1c;
  undefined2 uStack_1a;
  byte bStack_18;
  byte *pbStack_14;
  
  iVar1 = zb_zcl_basic_message_create(auStack_38);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < 6) {
      pbStack_14 = (byte *)0x0;
      auStack_38[0] = 1;
    }
    else {
      pbStack_14 = (byte *)zb_buf_begin_func(param_1);
      if (pbStack_14 == (byte *)0x0) {
        auStack_38[0] = 1;
      }
      else {
        auStack_38[0] = (uint)*pbStack_14;
      }
    }
    if (pbStack_14 == (byte *)0x0) {
      bStack_1c = 0;
      uStack_1a = 0xffff;
      bStack_18 = 0;
      pbStack_14 = (byte *)0x0;
    }
    else {
      bStack_1c = pbStack_14[1];
      uStack_1a = *(undefined2 *)(pbStack_14 + 2);
      bStack_18 = pbStack_14[4];
      pbStack_14 = pbStack_14 + 5;
    }
    iVar1 = (*zb_core_action_cb)(0x1022,auStack_38,zb_core_action_cb);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",
                  "zcl_scenes_get_scene_membership_res",0x5e3);
  }
  return iVar1;
}

