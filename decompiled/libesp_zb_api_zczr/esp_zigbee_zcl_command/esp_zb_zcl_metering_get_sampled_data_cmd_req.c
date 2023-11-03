/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_metering_get_sampled_data_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_metering_get_sampled_data_cmd_req(int param_1)

{
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  
  zb_buf_get_out_func();
  uStack_1c = *(undefined2 *)(param_1 + 0x10);
  uStack_1a = (undefined2)*(undefined4 *)(param_1 + 0x14);
  uStack_18 = (undefined2)((uint)*(undefined4 *)(param_1 + 0x14) >> 0x10);
  uStack_16 = (undefined1)*(undefined4 *)(param_1 + 0x18);
  uStack_15 = (undefined1)*(undefined2 *)(param_1 + 0x1c);
  uStack_14 = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x1c) >> 8);
  zb_zcl_metering_send_cmd_get_sampled_data
            (param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),&uStack_1c,0);
  return;
}

