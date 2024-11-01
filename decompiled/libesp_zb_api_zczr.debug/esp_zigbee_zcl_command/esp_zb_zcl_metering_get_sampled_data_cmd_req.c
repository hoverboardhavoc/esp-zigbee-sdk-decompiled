/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_metering_get_sampled_data_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_metering_get_sampled_data_cmd_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  code *pcVar4;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_metering_get_sampled_data_cmd_req",0x801,
                  "esp_zb_zcl_metering_get_sampled_data_cmd_req");
    pcVar3 = (char *)zb_zcl_get_ctx();
    *pcVar3 = *pcVar3 + '\x01';
  }
  else {
    uStack_1c = *(undefined2 *)(param_1 + 0x10);
    uStack_1a = (undefined2)*(undefined4 *)(param_1 + 0x14);
    uStack_18 = (undefined2)((uint)*(undefined4 *)(param_1 + 0x14) >> 0x10);
    uStack_16 = (undefined1)*(undefined4 *)(param_1 + 0x18);
    uStack_15 = (undefined1)*(undefined2 *)(param_1 + 0x1c);
    uStack_14 = (undefined1)((ushort)*(undefined2 *)(param_1 + 0x1c) >> 8);
    pcVar4 = zb_zcl_cmd_send_status_cb;
    if (zb_zcl_cmd_send_status_cb != (code *)0x0) {
      pcVar4 = zb_zcl_cmd_send_status_handler;
    }
    zb_zcl_metering_send_cmd_get_sampled_data
              (iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),&uStack_1c,pcVar4);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

