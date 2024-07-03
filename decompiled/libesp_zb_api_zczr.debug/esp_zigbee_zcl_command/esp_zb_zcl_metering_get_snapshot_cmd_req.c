/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_metering_get_snapshot_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_metering_get_snapshot_cmd_req(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar3,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_metering_get_snapshot_cmd_req",0x7d5,
                  "esp_zb_zcl_metering_get_snapshot_cmd_req");
    pcVar2 = (char *)zb_zcl_get_ctx();
    *pcVar2 = *pcVar2 + '\x01';
  }
  else {
    local_20 = *(undefined4 *)(param_1 + 0x10);
    uStack_1c = *(undefined4 *)(param_1 + 0x14);
    uStack_18 = *(undefined1 *)(param_1 + 0x18);
    uVar3 = *(undefined4 *)(param_1 + 0x1c);
    uStack_17 = (undefined1)uVar3;
    uStack_16 = (undefined1)((uint)uVar3 >> 8);
    uStack_15 = (undefined1)((uint)uVar3 >> 0x10);
    uStack_14 = (undefined1)((uint)uVar3 >> 0x18);
    pcVar4 = zb_zcl_cmd_send_status_cb;
    if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
      pcVar4 = zb_zcl_cmd_send_status_handler;
    }
    zb_zcl_metering_send_cmd_get_snapshot
              (iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),&local_20,pcVar4);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

