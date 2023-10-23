/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_cmd_config_report_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cmd_config_report_resp_handler(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint local_40 [7];
  undefined2 uStack_24;
  
  iVar2 = zb_zcl_basic_message_create(local_40);
  if (iVar2 == 0) {
    do {
      iVar5 = zb_buf_len_func(param_1);
      if (iVar5 == 0) {
        pbVar1 = (byte *)0x0;
_L0:
        if (pbVar1 != (byte *)0x0) {
          local_40[0] = (uint)*pbVar1;
          if (*pbVar1 == 0) {
            uStack_24 = 0xffff;
          }
          else {
            uStack_24 = *(undefined2 *)(pbVar1 + 2);
          }
          iVar2 = (*zb_core_action_cb)(0x1002,local_40,zb_core_action_cb);
        }
      }
      else {
        pbVar1 = (byte *)zb_buf_begin_func(param_1);
        if (pbVar1 != (byte *)0x0) {
          iVar5 = zb_zcl_zcl8_statuses_conversion(*pbVar1);
          *pbVar1 = (byte)iVar5;
          if (iVar5 == 0) {
            uVar6 = 1;
          }
          else if (iVar5 == 0x80) {
            uVar6 = 1;
          }
          else {
            zb_buf_len_func(param_1);
            uVar6 = 4;
          }
          uVar4 = zb_buf_len_func(param_1);
          if (uVar6 <= uVar4) {
            zb_buf_cut_left_func(param_1,uVar6);
            goto _L0;
          }
          pbVar1 = (byte *)0x0;
        }
      }
    } while (pbVar1 != (byte *)0x0);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",
                  "zcl_cmd_config_report_resp_handler",0x4ce);
  }
  return iVar2;
}

