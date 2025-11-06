/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_groups.o -> zcl_groups_get_add_group_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_groups_get_add_group_res(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  uint auStack_34 [8];
  undefined2 uStack_14;
  
  iVar1 = zb_zcl_basic_message_create(auStack_34);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < 3) {
      auStack_34[0] = 1;
      uStack_14 = 0xffff;
    }
    else {
      pbVar4 = (byte *)zb_buf_begin_func(param_1);
      if (pbVar4 == (byte *)0x0) {
        auStack_34[0] = 1;
        uStack_14 = 0xffff;
      }
      else {
        auStack_34[0] = (uint)*pbVar4;
        uStack_14 = *(undefined2 *)(pbVar4 + 1);
      }
    }
    iVar1 = esp_zb_core_action_handler_schedule(0x1010,auStack_34);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Failed to create add_group_response message\n",uVar3,
            0x10000,"zcl_groups_get_add_group_res",0x37);
  }
  return iVar1;
}

