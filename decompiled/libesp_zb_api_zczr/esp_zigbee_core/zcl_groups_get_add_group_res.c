/*
 * Last changed at upstream commit 2e2b779251f791b76c34cc582bf68595de9ac19b
 * https://github.com/espressif/esp-zigbee-sdk/commit/2e2b779251f791b76c34cc582bf68595de9ac19b
 * Upstream date: 2024-02-02 22:15:44 +0800
 * Upstream subject: feat(spinel): support zigbee radio spinel
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_groups_get_add_group_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_groups_get_add_group_res(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  uint auStack_34 [8];
  undefined2 uStack_14;
  
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
    iVar1 = (*zb_core_action_cb)(0x1010,auStack_34,zb_core_action_cb);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC12,uVar4,"ESP_ZIGBEE_CORE","zcl_groups_get_add_group_res",
                  0x7db);
  }
  return iVar1;
}

