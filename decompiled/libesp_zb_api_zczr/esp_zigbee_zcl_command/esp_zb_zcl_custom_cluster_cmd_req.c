/*
 * Last changed at upstream commit 0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * https://github.com/espressif/esp-zigbee-sdk/commit/0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * Upstream date: 2024-01-19 19:10:32 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.9(b7135493)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 uVar6;
  
  uVar2 = esp_zb_zcl_get_attribute_size
                    (*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
  if ((uVar2 == 0xffff) && (uVar2 = (uint)*(ushort *)(param_1 + 0x20), uVar2 == 0xffff)) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar6,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_custom_cluster_cmd_req",0x593);
    uVar6 = 0xff;
  }
  else {
    iVar3 = zb_buf_get_func(0,uVar2 + 0x1a);
    if (iVar3 == 0) {
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar6,"ESP_ZIGBEE_COMMAND",
                    "esp_zb_zcl_custom_cluster_cmd_req",0x594);
      uVar6 = 0xff;
    }
    else {
      pbVar4 = (byte *)zb_buf_reuse_func();
      *pbVar4 = (byte)((*(uint *)(param_1 + 0x18) & 0x1f) << 3) | 1;
      pbVar5 = (byte *)zb_zcl_get_ctx();
      bVar1 = *pbVar5;
      *pbVar5 = bVar1 + 1;
      pbVar4[1] = bVar1;
      pbVar4[2] = (byte)*(undefined2 *)(param_1 + 0x14);
      uVar6 = esp_zb_zcl_put_attribute_value
                        (pbVar4 + 3,*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),
                         uVar2);
      zb_zcl_finish_and_send_packet
                (iVar3,uVar6,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                 *(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),
                 *(undefined2 *)(param_1 + 0x12));
      uVar6 = zb_zcl_frame_get_sequence_number(iVar3);
    }
  }
  return uVar6;
}

