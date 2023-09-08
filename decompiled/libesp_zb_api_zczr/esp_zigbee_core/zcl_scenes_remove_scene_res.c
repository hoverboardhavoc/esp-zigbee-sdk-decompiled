/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_remove_scene_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_remove_scene_res(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  uint local_30 [7];
  undefined2 uStack_14;
  byte bStack_12;
  
  iVar1 = zb_zcl_basic_message_create(local_30);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < 4) {
      pbVar3 = (byte *)0x0;
      local_30[0] = 1;
    }
    else {
      pbVar3 = (byte *)zb_buf_begin_func(param_1);
      if (pbVar3 == (byte *)0x0) {
        local_30[0] = 1;
      }
      else {
        local_30[0] = (uint)*pbVar3;
      }
    }
    if (pbVar3 == (byte *)0x0) {
      uStack_14 = 0xffff;
      bStack_12 = 0xff;
    }
    else {
      uStack_14 = *(undefined2 *)(pbVar3 + 1);
      bStack_12 = pbVar3[3];
    }
    iVar1 = (*zb_core_action_cb)(0x1020,local_30,zb_core_action_cb);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC8,uVar4,"ESP_ZIGBEE_CORE","zcl_scenes_remove_scene_res",
                  0x586);
  }
  return iVar1;
}

