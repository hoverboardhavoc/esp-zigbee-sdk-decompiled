/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_drlc_cancel_load_control_event_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_drlc_cancel_load_control_event_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_drlc_cancel_load_control_event_req",0x80b,
                  "esp_zb_zcl_drlc_cancel_load_control_event_req");
    pcVar3 = (char *)zb_zcl_get_ctx();
    *pcVar3 = *pcVar3 + '\x01';
  }
  else {
    uStack_1c = *(undefined4 *)(param_1 + 0x10);
    uStack_18 = *(undefined4 *)(param_1 + 0x14);
    uStack_14 = *(undefined4 *)(param_1 + 0x18);
    zb_zcl_send_cmd(iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),1,
                    *(undefined1 *)(param_1 + 9),&uStack_1c,0xc);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

