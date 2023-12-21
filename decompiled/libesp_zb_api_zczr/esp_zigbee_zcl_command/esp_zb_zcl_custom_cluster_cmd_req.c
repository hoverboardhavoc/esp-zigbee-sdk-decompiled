/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 uVar5;
  
  uVar2 = zb_buf_get_out_func();
  pbVar3 = (byte *)zb_buf_reuse_func();
  *pbVar3 = (byte)((*(uint *)(param_1 + 0x18) & 0x1f) << 3) | 1;
  pbVar4 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar4;
  *pbVar4 = bVar1 + 1;
  pbVar3[1] = bVar1;
  pbVar3[2] = (byte)*(undefined2 *)(param_1 + 0x14);
  uVar5 = zb_zcl_get_attribute_size(*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20))
  ;
  uVar5 = esp_zb_zcl_put_attribute_value
                    (pbVar3 + 3,*(undefined1 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),
                     uVar5);
  zb_zcl_finish_and_send_packet
            (uVar2,uVar5,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x10),
             *(undefined2 *)(param_1 + 0x12));
  zb_zcl_frame_get_sequence_number(uVar2);
  return;
}

