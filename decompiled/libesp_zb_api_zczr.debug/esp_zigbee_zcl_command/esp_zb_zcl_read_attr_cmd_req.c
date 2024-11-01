/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_read_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_read_attr_cmd_req(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  undefined2 uVar6;
  
  iVar2 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar2 == 0) {
    uVar6 = 0x104;
  }
  else {
    uVar6 = *(undefined2 *)(iVar2 + 1);
  }
  iVar2 = zb_buf_get_out_func();
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar3,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_read_attr_cmd_req",0xcd,"esp_zb_zcl_read_attr_cmd_req");
    pcVar4 = (char *)zb_zcl_get_ctx();
    *pcVar4 = *pcVar4 + '\x01';
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x10);
    uVar3 = zb_zcl_construct_general_command_header
                      (uVar5 >> 0x12 & 1,uVar5 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                       uVar5 >> 0x13 & 1,0);
    iVar1 = 0;
    while ((iVar1 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
      uVar3 = zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar1 * 2));
      iVar1 = iVar1 + 1;
    }
    zb_zcl_finish_and_send_packet
              (iVar2,uVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar6,*(undefined2 *)(param_1 + 0x10));
    zb_zcl_frame_get_sequence_number(iVar2);
  }
  return;
}

