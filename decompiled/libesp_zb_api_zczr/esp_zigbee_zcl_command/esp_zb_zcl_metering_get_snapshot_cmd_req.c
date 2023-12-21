/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_metering_get_snapshot_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_metering_get_snapshot_cmd_req(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  
  uVar1 = zb_buf_get_out_func();
  local_20 = *(undefined4 *)(param_1 + 0x10);
  uStack_1c = *(undefined4 *)(param_1 + 0x14);
  uStack_18 = *(undefined1 *)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(param_1 + 0x1c);
  uStack_17 = (undefined1)uVar2;
  uStack_16 = (undefined1)((uint)uVar2 >> 8);
  uStack_15 = (undefined1)((uint)uVar2 >> 0x10);
  uStack_14 = (undefined1)((uint)uVar2 >> 0x18);
  pcVar3 = zb_zcl_cmd_send_status_cb;
  if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
    pcVar3 = zb_zcl_cmd_send_status_handler;
  }
  zb_zcl_metering_send_cmd_get_snapshot
            (uVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),&local_20,pcVar3);
  zb_zcl_frame_get_sequence_number(uVar1);
  return;
}

