/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_cmd_default_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cmd_default_resp_handler(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 auStack_38 [8];
  undefined1 uStack_18;
  uint uStack_14;
  
  iVar1 = zb_zcl_basic_message_create(auStack_38);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < 2) {
      auStack_38[0] = 1;
      uStack_18 = 0xff;
      uStack_14 = 1;
    }
    else {
      auStack_38[0] = 0;
      puVar4 = (undefined1 *)zb_buf_begin_func(param_1);
      uStack_18 = *puVar4;
      iVar1 = zb_buf_begin_func(param_1);
      uStack_14 = (uint)*(byte *)(iVar1 + 1);
    }
    iVar1 = (*zb_core_action_cb)(0x1005,auStack_38,zb_core_action_cb);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE","zcl_cmd_default_resp_handler",
                  0x7a3);
  }
  return iVar1;
}

