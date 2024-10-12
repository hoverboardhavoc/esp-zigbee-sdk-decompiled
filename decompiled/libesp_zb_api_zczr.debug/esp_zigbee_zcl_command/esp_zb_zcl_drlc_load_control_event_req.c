/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_drlc_load_control_event_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_drlc_load_control_event_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uStack_28;
  undefined3 uStack_24;
  undefined1 uStack_21;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC6,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_drlc_load_control_event_req",0x826,
                  "esp_zb_zcl_drlc_load_control_event_req");
    pcVar3 = (char *)zb_zcl_get_ctx();
    *pcVar3 = *pcVar3 + '\x01';
  }
  else {
    uStack_28 = *(undefined4 *)(param_1 + 0x10);
    _uStack_24 = CONCAT13(*(undefined1 *)(param_1 + 0x18),*(undefined3 *)(param_1 + 0x14));
    uStack_20 = *(undefined4 *)(param_1 + 0x19);
    uStack_1c = *(undefined4 *)(param_1 + 0x1d);
    uStack_18 = *(undefined4 *)(param_1 + 0x22);
    uStack_14 = *(undefined2 *)(param_1 + 0x26);
    uStack_12 = *(undefined1 *)(param_1 + 0x28);
    zb_zcl_send_cmd(iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),1,
                    *(undefined1 *)(param_1 + 9),&uStack_28,0x17);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

