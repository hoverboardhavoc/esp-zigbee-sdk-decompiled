/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_config_report_cmd_req(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined2 uVar9;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar9 = 0x104;
  }
  else {
    uVar9 = *(undefined2 *)(iVar2 + 1);
  }
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar4,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_config_report_cmd_req",0x160,"esp_zb_zcl_config_report_cmd_req");
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x10);
    puVar3 = (undefined1 *)
             zb_zcl_construct_general_command_header
                       (uVar7 >> 0x12 & 1,uVar7 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                        uVar7 >> 0x13 & 1,6);
    iVar8 = 0;
    while ((iVar8 < (int)(uint)*(ushort *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
      piVar1 = (int *)(*(int *)(param_1 + 0x18) + iVar8 * 0x14);
      if (*piVar1 == 0) {
        *puVar3 = 0;
        puVar3 = (undefined1 *)zb_put_next_htole16(puVar3 + 1,(short)piVar1[1]);
        *puVar3 = (char)piVar1[2];
        zb_put_next_htole16(puVar3 + 1,*(undefined2 *)((int)piVar1 + 10));
        puVar3 = (undefined1 *)zb_put_next_htole16((short)piVar1[3]);
        iVar6 = zb_zcl_is_analog_data_type((char)piVar1[2]);
        if (iVar6 != 0) {
          puVar3 = (undefined1 *)zb_zcl_put_value_to_packet(puVar3,(char)piVar1[2],piVar1[4]);
        }
      }
      else {
        *puVar3 = 1;
        zb_put_next_htole16(puVar3 + 1,(short)piVar1[1]);
        puVar3 = (undefined1 *)zb_put_next_htole16((short)piVar1[2]);
      }
      iVar8 = iVar8 + 1;
    }
    zb_zcl_finish_and_send_packet
              (iVar2,puVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar9,*(undefined2 *)(param_1 + 0x10));
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}

