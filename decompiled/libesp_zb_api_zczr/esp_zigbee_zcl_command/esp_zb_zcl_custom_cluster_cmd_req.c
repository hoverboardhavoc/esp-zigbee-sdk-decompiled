/*
 * Last changed at upstream commit 6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * https://github.com/espressif/esp-zigbee-sdk/commit/6663e9a47e70aeb89bdde3d1385b4fa8af6242fa
 * Upstream date: 2023-11-21 18:28:11 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.4(be3a8a97)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = zb_buf_get_out_func();
  uVar2 = zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x1c),0);
  uVar3 = zb_zcl_get_attribute_size(*(undefined1 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10))
  ;
  uVar2 = esp_zb_zcl_put_attribute_value
                    (uVar2,*(undefined1 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),uVar3);
  zb_zcl_finish_and_send_packet
            (uVar1,uVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x18),
             *(undefined2 *)(param_1 + 0x1a));
  return;
}

