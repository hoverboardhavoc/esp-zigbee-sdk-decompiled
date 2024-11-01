/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_read_report_config_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_read_report_config_cmd_req(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC7,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_read_report_config_cmd_req",0x17c,*(undefined1 *)(param_1 + 9));
    pcVar6 = (char *)zb_zcl_get_ctx();
    *pcVar6 = *pcVar6 + '\x01';
  }
  else {
    iVar3 = zb_buf_get_out_func();
    if (iVar3 == 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar5,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_read_report_config_cmd_req",0x17d,
                    "esp_zb_zcl_read_report_config_cmd_req");
      pcVar6 = (char *)zb_zcl_get_ctx();
      *pcVar6 = *pcVar6 + '\x01';
    }
    else {
      uVar7 = *(uint *)(param_1 + 0x10);
      puVar4 = (undefined1 *)
               zb_zcl_construct_general_command_header
                         (uVar7 >> 0x12 & 1,uVar7 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                          uVar7 >> 0x13 & 1,8);
      iVar1 = 0;
      while ((iVar1 < (int)(uint)*(ushort *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
        iVar8 = iVar1 * 4;
        if (*(char *)(*(int *)(param_1 + 0x18) + iVar8) == '\0') {
          *puVar4 = 0;
          puVar4 = (undefined1 *)
                   zb_put_next_htole16(puVar4 + 1,
                                       *(undefined2 *)(*(int *)(param_1 + 0x18) + iVar8 + 2));
        }
        else {
          *puVar4 = 1;
          puVar4 = (undefined1 *)
                   zb_put_next_htole16(puVar4 + 1,
                                       *(undefined2 *)(*(int *)(param_1 + 0x18) + iVar8 + 2));
        }
        iVar1 = iVar1 + 1;
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

