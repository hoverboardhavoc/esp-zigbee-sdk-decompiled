/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_command.o -> esp_zb_zcl_drlc_report_event_status_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_drlc_report_event_status_req(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0x80000000;
  uStack_40 = 0xff808000;
  uStack_3c = 0xffff0000;
  uStack_38 = 0xffffffff;
  uStack_34 = 0xffffffff;
  uStack_30 = 0xffffffff;
  uStack_2c = 0xffffffff;
  uStack_28 = 0xffffffff;
  uStack_24 = 0xffffffff;
  uStack_20 = 0xffffffff;
  uStack_1c = 0xffffffff;
  uStack_18 = 0xffffffff;
  uStack_14 = 0xffffffff;
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_L0,uVar2,"ESP_ZIGBEE_COMMAND",
                  "esp_zb_zcl_drlc_report_event_status_req",0x834,
                  "esp_zb_zcl_drlc_report_event_status_req");
    pcVar3 = (char *)zb_zcl_get_ctx();
    *pcVar3 = *pcVar3 + '\x01';
  }
  else {
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    uStack_4c = *(undefined4 *)(param_1 + 0x10);
    uStack_48 = CONCAT13(*(undefined1 *)(param_1 + 0x1a),
                         CONCAT12(*(undefined1 *)(param_1 + 0x19),
                                  CONCAT11(*(undefined1 *)(param_1 + 0x18),
                                           *(undefined1 *)(param_1 + 0x14))));
    uStack_44 = CONCAT13(*(undefined1 *)(param_1 + 0x1f),
                         CONCAT12(*(undefined1 *)(param_1 + 0x1e),*(undefined2 *)(param_1 + 0x1b)));
    uStack_40 = *(undefined4 *)(param_1 + 0x20);
    uStack_3c = (uint)*(ushort *)(param_1 + 0x24);
    memcpy((void *)((int)&uStack_3c + 2),(void *)(param_1 + 0x26),0x2a);
    zb_zcl_send_cmd(iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),0,
                    *(undefined1 *)(param_1 + 9),&uStack_4c,0x3c);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

