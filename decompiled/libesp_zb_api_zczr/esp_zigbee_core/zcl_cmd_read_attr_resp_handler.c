/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_cmd_read_attr_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cmd_read_attr_resp_handler(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint auStack_48 [4];
  short sStack_36;
  undefined2 uStack_2c;
  ushort uStack_2a;
  undefined2 uStack_28;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  
  iVar3 = zb_zcl_basic_message_create(auStack_48);
  if (iVar3 == 0) {
    do {
      uVar7 = zb_buf_len_func(param_1);
      if (uVar7 < 3) {
        puVar1 = (undefined2 *)0x0;
_L0:
        if (puVar1 != (undefined2 *)0x0) {
          if (sStack_36 == 10) {
            zb_zcl_time_server_read_attr_handle(param_1);
          }
          auStack_48[0] = (uint)*(byte *)(puVar1 + 1);
          uStack_2c = *puVar1;
          uStack_2a = (ushort)*(byte *)((int)puVar1 + 3);
          uStack_28 = 0;
          puVar2 = puVar1 + 2;
          uStack_26 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar1 + 3),puVar2);
          uStack_25 = SUB41(puVar2,0);
          uStack_24 = (undefined1)((uint)puVar2 >> 8);
          uStack_23 = (undefined1)((uint)puVar2 >> 0x10);
          uStack_22 = (undefined1)((uint)puVar2 >> 0x18);
          iVar3 = (*zb_core_action_cb)(0x1000,auStack_48,zb_core_action_cb);
        }
      }
      else {
        puVar1 = (undefined2 *)zb_buf_begin_func(param_1);
        if (puVar1 != (undefined2 *)0x0) {
          iVar5 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar1 + 1));
          *(char *)(puVar1 + 1) = (char)iVar5;
          if (iVar5 == 0) {
            iVar5 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar1 + 3),puVar1 + 2);
            uVar7 = iVar5 + 4U & 0xff;
            zb_buf_len_func(param_1);
          }
          else {
            uVar7 = 3;
          }
          uVar6 = zb_buf_len_func(param_1);
          if (uVar7 <= uVar6) {
            zb_buf_cut_left_func(param_1,uVar7);
            goto _L0;
          }
          puVar1 = (undefined2 *)0x0;
        }
      }
    } while (puVar1 != (undefined2 *)0x0);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC25,uVar4,"ESP_ZIGBEE_CORE",
                  "zcl_cmd_read_attr_resp_handler",0x48b);
  }
  return iVar3;
}

