/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_scenes_remove_all_scene_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_remove_all_scene_res(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  uint auStack_34 [8];
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  iVar1 = zb_zcl_basic_message_create(auStack_34);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < 3) {
      pbVar3 = (byte *)0x0;
      auStack_34[0] = 1;
    }
    else {
      pbVar3 = (byte *)zb_buf_begin_func(param_1);
      if (pbVar3 == (byte *)0x0) {
        auStack_34[0] = 1;
      }
      else {
        auStack_34[0] = (uint)*pbVar3;
      }
    }
    if (pbVar3 == (byte *)0x0) {
      uStack_14 = 0xffff;
    }
    else {
      uStack_14 = *(undefined2 *)(pbVar3 + 1);
    }
    uStack_12 = 0xff;
    iVar1 = (*zb_core_action_cb)(0x1020,auStack_34,zb_core_action_cb);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE","zcl_scenes_remove_all_scene_res"
                  ,0x871);
  }
  return iVar1;
}

