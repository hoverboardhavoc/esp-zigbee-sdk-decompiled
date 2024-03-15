/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_groups_get_view_group_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_groups_get_view_group_res(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint auStack_38 [8];
  undefined2 uStack_18;
  byte *pbStack_14;
  
  iVar1 = zb_zcl_basic_message_create(auStack_38);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < 4) {
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
      uStack_18 = 0xffff;
      pbStack_14 = (byte *)0x0;
    }
    else {
      uStack_18 = *(undefined2 *)(pbStack_14 + 1);
      pbStack_14 = pbStack_14 + 3;
    }
    iVar1 = (*zb_core_action_cb)(0x1011,auStack_38,zb_core_action_cb);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC14,uVar3,"ESP_ZIGBEE_CORE","zcl_groups_get_view_group_res"
                  ,0x810);
  }
  return iVar1;
}

