/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_config_report_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_config_report_cmd_req",0x151);
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    if (**(int **)(param_1 + 0x14) == 0) {
      puVar3 = (undefined1 *)zb_buf_reuse_func();
      *puVar3 = 0;
      pcVar4 = (char *)zb_zcl_get_ctx();
      cVar1 = *pcVar4;
      *pcVar4 = cVar1 + '\x01';
      puVar3[1] = cVar1;
      puVar3[2] = 6;
    }
    else {
      puVar3 = (undefined1 *)zb_buf_reuse_func();
      *puVar3 = 8;
      pcVar4 = (char *)zb_zcl_get_ctx();
      cVar1 = *pcVar4;
      *pcVar4 = cVar1 + '\x01';
      puVar3[1] = cVar1;
      puVar3[2] = 6;
    }
    puVar3 = puVar3 + 3;
    iVar8 = 0;
    while ((iVar8 < (int)(uint)*(ushort *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
      *puVar3 = 0;
      iVar7 = iVar8 * 0x10;
      puVar3 = (undefined1 *)
               zb_put_next_htole16(puVar3 + 1,*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar7 + 4))
      ;
      *puVar3 = *(undefined1 *)(*(int *)(param_1 + 0x14) + iVar7 + 6);
      zb_put_next_htole16(puVar3 + 1,*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar7 + 8));
      puVar3 = (undefined1 *)
               zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar7 + 10));
      iVar6 = zb_zcl_is_analog_data_type(*(undefined1 *)(*(int *)(param_1 + 0x14) + iVar7 + 6));
      if (iVar6 != 0) {
        iVar7 = *(int *)(param_1 + 0x14) + iVar7;
        puVar3 = (undefined1 *)
                 zb_zcl_put_value_to_packet
                           (puVar3,*(undefined1 *)(iVar7 + 6),*(undefined4 *)(iVar7 + 0xc));
      }
      iVar8 = iVar8 + 1;
    }
    zb_zcl_finish_and_send_packet
              (iVar2,puVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}

