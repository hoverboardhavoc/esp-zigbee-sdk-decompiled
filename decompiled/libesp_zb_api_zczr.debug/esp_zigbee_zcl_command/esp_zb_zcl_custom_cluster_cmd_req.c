/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 uVar5;
  char *pcVar6;
  byte bVar7;
  
  uVar1 = esp_zb_zcl_get_attribute_size
                    (*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
  if ((uVar1 == 0xffff) && (uVar1 = (uint)*(ushort *)(param_1 + 0x20), uVar1 == 0xffff)) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar5,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_custom_cluster_cmd_req",0x917);
    pcVar6 = (char *)zb_zcl_get_ctx();
    *pcVar6 = *pcVar6 + '\x01';
  }
  else {
    iVar2 = zb_buf_get_func(0,uVar1 + 0x1a);
    if (iVar2 == 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar5,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_custom_cluster_cmd_req",0x918,"esp_zb_zcl_custom_cluster_cmd_req");
      pcVar6 = (char *)zb_zcl_get_ctx();
      *pcVar6 = *pcVar6 + '\x01';
    }
    else {
      pbVar3 = (byte *)zb_buf_reuse_func();
      if ((*(byte *)(param_1 + 0x14) & 3) == 0) {
        bVar7 = 1;
      }
      else {
        bVar7 = 5;
      }
      *pbVar3 = (byte)((*(uint *)(param_1 + 0x14) >> 3 & 1) << 4) |
                (byte)((*(uint *)(param_1 + 0x14) >> 2 & 1) << 3) | bVar7;
      pbVar3 = pbVar3 + 1;
      if ((*(byte *)(param_1 + 0x14) & 3) != 0) {
        pbVar3 = (byte *)zb_put_next_htole16(pbVar3,*(undefined2 *)(param_1 + 0x16));
      }
      pbVar4 = (byte *)zb_zcl_get_ctx();
      bVar7 = *pbVar4;
      *pbVar4 = bVar7 + 1;
      *pbVar3 = bVar7;
      pbVar3[1] = (byte)*(undefined2 *)(param_1 + 0x18);
      uVar5 = esp_zb_zcl_put_attribute_value
                        (pbVar3 + 2,*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),
                         uVar1);
      zb_zcl_finish_and_send_packet
                (iVar2,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),
                 *(undefined2 *)(param_1 + 0x12));
      zb_zcl_frame_get_sequence_number(iVar2);
    }
  }
  return;
}

