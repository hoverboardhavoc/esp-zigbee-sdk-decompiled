/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zb_zcl_privilege_command_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_privilege_command_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_48 [23];
  undefined1 uStack_31;
  undefined2 uStack_30;
  undefined1 uStack_2c;
  char cStack_2b;
  undefined2 uStack_28;
  undefined4 uStack_24;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  iVar2 = zb_zcl_basic_message_create(param_1,auStack_48);
  if (iVar2 == 0) {
    iVar2 = zcl_privilege_command_list_find(uStack_31,uStack_30,uStack_2c);
    if (iVar2 != 0) {
      uStack_28 = zb_buf_len_func(param_1);
      uStack_24 = zb_buf_begin_func(param_1);
      iVar4 = 0;
      if (zb_core_action_cb != (code *)0x0) {
        if (cStack_2b == '\x01') {
          iVar4 = (*zb_core_action_cb)(0x1051,auStack_48);
        }
        else {
          iVar4 = (*zb_core_action_cb)(0x1050,auStack_48);
        }
      }
      if (iVar1 != 0) {
        zb_zcl_send_default_handler(param_1,iVar1,iVar4 != 0);
      }
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC18,uVar3,"ESP_ZIGBEE_CORE",
                  "zb_zcl_privilege_command_handler",0xa1a);
    iVar2 = 1;
  }
  return iVar2;
}

