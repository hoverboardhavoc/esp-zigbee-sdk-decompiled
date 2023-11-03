/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
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
  undefined1 *puVar4;
  
  uVar1 = zb_buf_get_out_func();
  uVar2 = zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x1c),0);
  uVar3 = zb_zcl_get_attribute_size(*(undefined1 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10))
  ;
  puVar4 = (undefined1 *)zb_put_next_htole32(uVar2,*(undefined4 *)(param_1 + 0x14));
  *puVar4 = (char)uVar3;
  uVar2 = esp_zb_zcl_put_attribute_value
                    (puVar4 + 1,*(undefined1 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),
                     uVar3);
  zb_zcl_finish_and_send_packet
            (uVar1,uVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),*(undefined2 *)(param_1 + 0x18),
             *(undefined2 *)(param_1 + 0x1a));
  return;
}

