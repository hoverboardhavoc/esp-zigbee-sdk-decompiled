/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zcl_scenes_add_scene_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_scenes_add_scene_res(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  uint auStack_34 [8];
  undefined2 uStack_14;
  byte bStack_12;
  
  iVar1 = zb_zcl_basic_message_create(auStack_34);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if ((uVar2 < 4) || (pbVar4 = (byte *)zb_buf_begin_func(param_1), pbVar4 == (byte *)0x0)) {
      auStack_34[0] = 1;
      uStack_14 = 0xffff;
      bStack_12 = 0xff;
    }
    else {
      auStack_34[0] = (uint)*pbVar4;
      uStack_14 = *(undefined2 *)(pbVar4 + 1);
      bStack_12 = pbVar4[3];
    }
    iVar1 = esp_zb_core_action_handler_schedule(0x1020,auStack_34);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_SCENES",
            "E (%lu) %s: %s(%d): Failed to create add_scene_response message\n",uVar3,
            "ESP_ZIGBEE_ZCL_SCENES","zcl_scenes_add_scene_res",0x2d4);
  }
  return iVar1;
}

