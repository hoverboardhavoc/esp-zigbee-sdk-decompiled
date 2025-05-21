/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_general.o -> zcl_cmd_read_report_config_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cmd_read_report_config_resp_handler(undefined4 param_1)

{
  byte bVar1;
  uint *puVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  undefined1 auStack_44 [32];
  uint *puStack_24;
  
  puStack_24 = (uint *)0x0;
  iVar4 = zb_zcl_basic_message_create(auStack_44);
  if (iVar4 == 0) {
    puVar9 = (uint *)0x0;
    do {
      uVar6 = zb_buf_len_func(param_1);
      if (uVar6 < 4) {
        pbVar3 = (byte *)0x0;
        uVar6 = 0;
      }
      else {
        pbVar3 = (byte *)zb_buf_begin_func(param_1);
        if (pbVar3 == (byte *)0x0) {
          uVar6 = 0;
        }
        else {
          if (pbVar3[1] == 0) {
            iVar4 = zb_zcl_is_analog_data_type(pbVar3[4]);
            if (iVar4 == 0) {
              uVar6 = 9;
            }
            else {
              uVar6 = 10;
            }
          }
          else {
            uVar6 = 6;
          }
          iVar4 = zb_zcl_zcl8_statuses_conversion(*pbVar3);
          *pbVar3 = (byte)iVar4;
          if ((iVar4 != 0) && (iVar4 != 0x80)) {
            uVar6 = 4;
          }
        }
      }
      uVar7 = zb_buf_len_func(param_1);
      puVar8 = puVar9;
      if (uVar7 < uVar6) {
        pbVar3 = (byte *)0x0;
        puVar2 = puStack_24;
      }
      else {
        zb_buf_cut_left_func(param_1,uVar6);
        puVar2 = puStack_24;
        if (pbVar3 != (byte *)0x0) {
          puVar8 = (uint *)malloc(0x14);
          *puVar8 = (uint)*pbVar3;
          *(undefined2 *)((int)puVar8 + 6) = *(undefined2 *)(pbVar3 + 2);
          bVar1 = pbVar3[1];
          *(byte *)(puVar8 + 1) = bVar1;
          if (*pbVar3 == 0) {
            if (bVar1 == 0) {
              *(byte *)(puVar8 + 2) = pbVar3[4];
              *(undefined2 *)((int)puVar8 + 10) = *(undefined2 *)(pbVar3 + 5);
              *(undefined2 *)(puVar8 + 3) = *(undefined2 *)(pbVar3 + 7);
              *(byte *)((int)puVar8 + 0xe) = pbVar3[9];
            }
            else {
              *(undefined2 *)(puVar8 + 2) = *(undefined2 *)(pbVar3 + 4);
            }
          }
          else {
            *(undefined1 *)(puVar8 + 2) = 0;
            *(undefined1 *)((int)puVar8 + 9) = 0;
            *(undefined1 *)((int)puVar8 + 10) = 0;
            *(undefined1 *)((int)puVar8 + 0xb) = 0;
            *(undefined1 *)(puVar8 + 3) = 0;
            *(undefined1 *)((int)puVar8 + 0xd) = 0;
            *(undefined1 *)((int)puVar8 + 0xe) = 0;
            *(undefined1 *)((int)puVar8 + 0xf) = 0;
          }
          puVar8[4] = 0;
          puVar2 = puVar8;
          if (puVar9 != (uint *)0x0) {
            puVar9[4] = (uint)puVar8;
            puVar2 = puStack_24;
          }
        }
      }
      puStack_24 = puVar2;
      puVar9 = puVar8;
    } while (pbVar3 != (byte *)0x0);
    esp_zb_core_action_handler_schedule(0x1003,auStack_44);
    iVar4 = esp_err_to_zb_ret();
    puVar9 = puStack_24;
    while (puVar9 != (uint *)0x0) {
      puVar8 = (uint *)puVar9[4];
      free(puVar9);
      puVar9 = puVar8;
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC7,uVar5,0x10000,"zcl_cmd_read_report_config_resp_handler",0x8c);
  }
  return iVar4;
}

