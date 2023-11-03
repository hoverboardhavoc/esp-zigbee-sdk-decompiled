/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_cmd_write_attr_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cmd_write_attr_resp_handler(undefined4 param_1)

{
  uint *puVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined1 auStack_44 [32];
  uint *puStack_24;
  
  puStack_24 = (uint *)0x0;
  iVar3 = zb_zcl_basic_message_create(auStack_44);
  if (iVar3 == 0) {
    puVar7 = (uint *)0x0;
    do {
      iVar3 = zb_buf_len_func(param_1);
      puVar6 = puVar7;
      if (iVar3 == 0) {
        pbVar2 = (byte *)0x0;
_L0:
        puVar1 = puStack_24;
        if (pbVar2 != (byte *)0x0) {
          puVar6 = (uint *)malloc(0xc);
          *puVar6 = (uint)*pbVar2;
          if (*pbVar2 == 0) {
            uVar8 = 0xffff;
          }
          else {
            uVar8 = *(undefined2 *)(pbVar2 + 1);
          }
          *(undefined2 *)(puVar6 + 1) = uVar8;
          puVar6[2] = 0;
          puVar1 = puVar6;
          if (puVar7 != (uint *)0x0) {
            puVar7[2] = (uint)puVar6;
            puVar1 = puStack_24;
          }
        }
      }
      else {
        pbVar2 = (byte *)zb_buf_begin_func(param_1);
        puVar1 = puStack_24;
        if (pbVar2 != (byte *)0x0) {
          iVar3 = zb_zcl_zcl8_statuses_conversion(*pbVar2);
          *pbVar2 = (byte)iVar3;
          if (iVar3 == 0) {
            uVar9 = 1;
          }
          else {
            zb_buf_len_func(param_1);
            uVar9 = 3;
          }
          uVar5 = zb_buf_len_func(param_1);
          if (uVar9 <= uVar5) {
            zb_buf_cut_left_func(param_1,uVar9);
            goto _L0;
          }
          pbVar2 = (byte *)0x0;
          puVar1 = puStack_24;
        }
      }
      puStack_24 = puVar1;
      puVar7 = puVar6;
    } while (pbVar2 != (byte *)0x0);
    iVar3 = (*zb_core_action_cb)(0x1001,auStack_44,zb_core_action_cb);
    puVar7 = puStack_24;
    while (puVar7 != (uint *)0x0) {
      puVar6 = (uint *)puVar7[2];
      free(puVar7);
      puVar7 = puVar6;
    }
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE","zcl_cmd_write_attr_resp_handler"
                  ,0x687);
  }
  return iVar3;
}

