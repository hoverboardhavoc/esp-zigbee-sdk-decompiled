/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_cmd_read_report_config_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cmd_read_report_config_resp_handler(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint auStack_4c [8];
  byte bStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  byte bStack_22;
  
  iVar2 = zb_zcl_basic_message_create(auStack_4c);
  if (iVar2 == 0) {
    do {
      uVar5 = zb_buf_len_func(param_1);
      if (uVar5 < 5) {
        uVar5 = 4;
        pbVar1 = (byte *)0x0;
_L0:
        if (pbVar1 == (byte *)0x0) {
          uVar5 = 0;
        }
        else {
          iVar6 = zb_zcl_zcl8_statuses_conversion(*pbVar1);
          *pbVar1 = (byte)iVar6;
          if ((iVar6 != 0) && (iVar6 != 0x80)) {
            zb_buf_len_func(param_1);
            uVar5 = 4;
          }
        }
      }
      else {
        pbVar1 = (byte *)zb_buf_begin_func(param_1);
        if (pbVar1 == (byte *)0x0) {
          uVar5 = 0;
        }
        else {
          if (pbVar1[1] == 0) {
            iVar6 = zb_zcl_is_analog_data_type(pbVar1[4]);
            if (iVar6 == 0) {
              uVar5 = 9;
            }
            else {
              uVar5 = 10;
            }
          }
          else {
            uVar5 = 6;
          }
          uVar4 = zb_buf_len_func(param_1);
          if (uVar5 <= uVar4) goto _L0;
          pbVar1 = (byte *)0x0;
          uVar5 = 0;
        }
      }
      uVar4 = zb_buf_len_func(param_1);
      if (uVar4 < uVar5) {
        pbVar1 = (byte *)0x0;
      }
      else {
        zb_buf_cut_left_func(param_1,uVar5);
        if (pbVar1 != (byte *)0x0) {
          auStack_4c[0] = (uint)*pbVar1;
          if (*pbVar1 == 0) {
            uStack_2a = 0xffff;
          }
          else {
            uStack_2a = *(undefined2 *)(pbVar1 + 2);
          }
          bStack_2c = pbVar1[1];
          if (bStack_2c == 0) {
            uStack_28 = CONCAT11(uStack_28._1_1_,pbVar1[4]);
            uStack_26 = *(undefined2 *)(pbVar1 + 5);
            uStack_24 = *(undefined2 *)(pbVar1 + 7);
            bStack_22 = pbVar1[9];
          }
          else {
            uStack_28 = *(undefined2 *)(pbVar1 + 4);
          }
          iVar2 = (*zb_core_action_cb)(0x1003,auStack_4c,zb_core_action_cb);
        }
      }
    } while (pbVar1 != (byte *)0x0);
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC36,uVar3,"ESP_ZIGBEE_CORE",
                  "zcl_cmd_read_report_config_resp_handler",0x764);
  }
  return iVar2;
}

