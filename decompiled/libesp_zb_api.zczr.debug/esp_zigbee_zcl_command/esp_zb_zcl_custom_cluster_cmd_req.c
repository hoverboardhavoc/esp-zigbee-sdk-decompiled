/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined4 uVar4;
  char *pcVar5;
  byte bVar6;
  int iVar7;
  
  uVar1 = esp_zb_zcl_get_attribute_size
                    (*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
  if ((uVar1 == 0xffff) && (uVar1 = (uint)*(ushort *)(param_1 + 0x20), uVar1 == 0xffff)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC1,uVar4,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_custom_cluster_cmd_req",0x900);
    pcVar5 = (char *)zb_zcl_get_ctx();
    *pcVar5 = *pcVar5 + '\x01';
  }
  else {
    if ((*(byte *)(param_1 + 0x14) & 3) == 0) {
      iVar7 = 0x5a;
    }
    else {
      iVar7 = 0x5c;
    }
    iVar7 = zb_buf_get_func(0,uVar1 + iVar7);
    if (iVar7 == 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar4,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_custom_cluster_cmd_req",0x901,"esp_zb_zcl_custom_cluster_cmd_req");
      pcVar5 = (char *)zb_zcl_get_ctx();
      *pcVar5 = *pcVar5 + '\x01';
    }
    else {
      pbVar2 = (byte *)zb_buf_reuse_func();
      if ((*(byte *)(param_1 + 0x14) & 3) == 0) {
        bVar6 = 1;
      }
      else {
        bVar6 = 5;
      }
      *pbVar2 = (byte)((*(uint *)(param_1 + 0x14) >> 3 & 1) << 4) |
                bVar6 | (byte)((*(uint *)(param_1 + 0x14) >> 2 & 1) << 3);
      pbVar2 = pbVar2 + 1;
      if ((*(byte *)(param_1 + 0x14) & 3) != 0) {
        pbVar2 = (byte *)zb_put_next_htole16(pbVar2,*(undefined2 *)(param_1 + 0x16));
      }
      pbVar3 = (byte *)zb_zcl_get_ctx();
      bVar6 = *pbVar3;
      *pbVar3 = bVar6 + 1;
      *pbVar2 = bVar6;
      pbVar2[1] = (byte)*(undefined2 *)(param_1 + 0x18);
      uVar4 = esp_zb_zcl_put_attribute_value
                        (pbVar2 + 2,*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),
                         uVar1);
      zb_zcl_finish_and_send_packet
                (iVar7,uVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),
                 *(undefined2 *)(param_1 + 0x12));
      zb_zcl_frame_get_sequence_number(iVar7);
    }
  }
  return;
}

