/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_read_report_config_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_read_report_config_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar3 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar3 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar7,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_read_report_config_cmd_req",0x16a,*(undefined1 *)(param_1 + 9));
    pcVar6 = (char *)zb_zcl_get_ctx();
    *pcVar6 = *pcVar6 + '\x01';
  }
  else {
    iVar4 = zb_buf_get_out_func();
    if (iVar4 == 0) {
      uVar7 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar7,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_read_report_config_cmd_req",0x16b,
                    "esp_zb_zcl_read_report_config_cmd_req");
      pcVar6 = (char *)zb_zcl_get_ctx();
      *pcVar6 = *pcVar6 + '\x01';
    }
    else {
      puVar5 = (undefined1 *)zb_buf_reuse_func();
      *puVar5 = 0;
      pcVar6 = (char *)zb_zcl_get_ctx();
      cVar1 = *pcVar6;
      *pcVar6 = cVar1 + '\x01';
      puVar5[1] = cVar1;
      puVar5[2] = 8;
      puVar5 = puVar5 + 3;
      iVar2 = 0;
      while ((iVar2 < (int)(uint)*(ushort *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
        iVar8 = iVar2 * 4;
        if (*(char *)(*(int *)(param_1 + 0x14) + iVar8) == '\0') {
          *puVar5 = 0;
          puVar5 = (undefined1 *)
                   zb_put_next_htole16(puVar5 + 1,
                                       *(undefined2 *)(*(int *)(param_1 + 0x14) + iVar8 + 2));
        }
        else {
          *puVar5 = 1;
          puVar5 = (undefined1 *)
                   zb_put_next_htole16(puVar5 + 1,
                                       *(undefined2 *)(*(int *)(param_1 + 0x14) + iVar8 + 2));
        }
        iVar2 = iVar2 + 1;
      }
      zb_zcl_finish_and_send_packet
                (iVar4,puVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(iVar3 + 1),
                 *(undefined2 *)(param_1 + 0x10));
      zb_zcl_frame_get_sequence_number(iVar4);
    }
  }
  return;
}

