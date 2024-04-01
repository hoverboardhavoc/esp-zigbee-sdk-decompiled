/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_config_report_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar6,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_config_report_cmd_req",0x159,*(undefined1 *)(param_1 + 9));
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    iVar3 = zb_buf_get_out_func();
    if (iVar3 == 0) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar6,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_config_report_cmd_req",0x15a,"esp_zb_zcl_config_report_cmd_req");
      pcVar5 = (char *)zb_zcl_get_ctx();
      *pcVar5 = *pcVar5 + '\x01';
    }
    else {
      if (**(int **)(param_1 + 0x14) == 0) {
        puVar4 = (undefined1 *)zb_buf_reuse_func();
        *puVar4 = 0;
        pcVar5 = (char *)zb_zcl_get_ctx();
        cVar1 = *pcVar5;
        *pcVar5 = cVar1 + '\x01';
        puVar4[1] = cVar1;
        puVar4[2] = 6;
      }
      else {
        puVar4 = (undefined1 *)zb_buf_reuse_func();
        *puVar4 = 8;
        pcVar5 = (char *)zb_zcl_get_ctx();
        cVar1 = *pcVar5;
        *pcVar5 = cVar1 + '\x01';
        puVar4[1] = cVar1;
        puVar4[2] = 6;
      }
      puVar4 = puVar4 + 3;
      iVar9 = 0;
      while ((iVar9 < (int)(uint)*(ushort *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
        *puVar4 = 0;
        iVar8 = iVar9 * 0x10;
        puVar4 = (undefined1 *)
                 zb_put_next_htole16(puVar4 + 1,
                                     *(undefined2 *)(*(int *)(param_1 + 0x14) + iVar8 + 4));
        *puVar4 = *(undefined1 *)(*(int *)(param_1 + 0x14) + iVar8 + 6);
        zb_put_next_htole16(puVar4 + 1,*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar8 + 8));
        puVar4 = (undefined1 *)
                 zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar8 + 10));
        iVar7 = zb_zcl_is_analog_data_type(*(undefined1 *)(*(int *)(param_1 + 0x14) + iVar8 + 6));
        if (iVar7 != 0) {
          iVar8 = *(int *)(param_1 + 0x14) + iVar8;
          puVar4 = (undefined1 *)
                   zb_zcl_put_value_to_packet
                             (puVar4,*(undefined1 *)(iVar8 + 6),*(undefined4 *)(iVar8 + 0xc));
        }
        iVar9 = iVar9 + 1;
      }
      zb_zcl_finish_and_send_packet
                (iVar3,puVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar2 + 1),
                 *(undefined2 *)(param_1 + 0x10));
      zb_zcl_frame_get_sequence_number(iVar3);
    }
  }
  return;
}

