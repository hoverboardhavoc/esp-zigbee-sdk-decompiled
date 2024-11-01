/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_write_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_write_attr_cmd_req(int param_1)

{
  int iVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined2 uVar9;
  int iVar10;
  
  iVar4 = zb_af_get_endpoint_desc(*(undefined1 *)(param_1 + 9));
  if (iVar4 == 0) {
    uVar9 = 0x104;
  }
  else {
    uVar9 = *(undefined2 *)(iVar4 + 1);
  }
  iVar4 = 0;
  sVar3 = 0x98;
  while ((iVar4 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
    iVar10 = *(int *)(param_1 + 0x18) + iVar4 * 0xc;
    sVar2 = esp_zb_zcl_get_attribute_size(*(undefined1 *)(iVar10 + 2),*(undefined4 *)(iVar10 + 8));
    sVar3 = sVar2 + sVar3;
    iVar4 = iVar4 + 1;
  }
  iVar4 = zb_buf_get_func(0,sVar3);
  if (iVar4 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_write_attr_cmd_req",0xe5,"esp_zb_zcl_write_attr_cmd_req");
    pcVar6 = (char *)zb_zcl_get_ctx();
    *pcVar6 = *pcVar6 + '\x01';
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x10);
    uVar5 = zb_zcl_construct_general_command_header
                      (uVar8 >> 0x12 & 1,uVar8 >> 0x10 & 3,*(undefined2 *)(param_1 + 0x14),
                       uVar8 >> 0x13 & 1,2);
    iVar10 = 0;
    while ((iVar10 < (int)(uint)*(byte *)(param_1 + 0x16) && (*(int *)(param_1 + 0x18) != 0))) {
      iVar1 = iVar10 * 0xc;
      puVar7 = (undefined1 *)zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar1));
      *puVar7 = (char)*(undefined2 *)(*(int *)(param_1 + 0x18) + iVar1 + 2);
      iVar1 = *(int *)(param_1 + 0x18) + iVar1;
      uVar5 = zb_zcl_put_value_to_packet
                        (puVar7 + 1,*(undefined1 *)(iVar1 + 2),*(undefined4 *)(iVar1 + 8));
      iVar10 = iVar10 + 1;
    }
    zb_zcl_finish_and_send_packet
              (iVar4,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),uVar9,*(undefined2 *)(param_1 + 0x10));
    zb_zcl_frame_get_sequence_number(iVar4);
  }
  return;
}

