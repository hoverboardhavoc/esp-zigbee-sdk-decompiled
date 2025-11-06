/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zcl_scenes_get_scene_membership_res
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
  uint auStack_3c [8];
  byte bStack_1c;
  undefined2 uStack_1a;
  byte bStack_18;
  byte *pbStack_14;
  
  iVar1 = zb_zcl_basic_message_create(auStack_3c);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if ((uVar2 < 6) || (pbStack_14 = (byte *)zb_buf_begin_func(param_1), pbStack_14 == (byte *)0x0))
    {
      auStack_3c[0] = 1;
      bStack_1c = 0;
      uStack_1a = 0xffff;
      bStack_18 = 0;
      pbStack_14 = (byte *)0x0;
    }
    else {
      auStack_3c[0] = (uint)*pbStack_14;
      bStack_1c = pbStack_14[1];
      uStack_1a = *(undefined2 *)(pbStack_14 + 2);
      bStack_18 = pbStack_14[4];
      pbStack_14 = pbStack_14 + 5;
    }
    iVar1 = esp_zb_core_action_handler_schedule(0x1022,auStack_3c);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_SCENES",
            "E (%lu) %s: %s(%d): Failed to create get_scene_membership_response message\n",uVar3,
            "ESP_ZIGBEE_ZCL_SCENES","zcl_scenes_get_scene_membership_res",0x33f);
  }
  return iVar1;
}

