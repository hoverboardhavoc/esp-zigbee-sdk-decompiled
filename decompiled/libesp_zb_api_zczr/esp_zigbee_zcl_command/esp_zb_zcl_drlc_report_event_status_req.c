/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_drlc_report_event_status_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_drlc_report_event_status_req(int param_1)

{
  int iVar1;
  char *pcVar2;
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
  
  uStack_44 = 0x80000000;
  uStack_40 = 0xff808000;
  uStack_3c = 0xffff0000;
  uStack_4c = 0;
  uStack_48 = 0;
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
    pcVar2 = (char *)zb_zcl_get_ctx();
    *pcVar2 = *pcVar2 + '\x01';
  }
  else {
    memcpy(&uStack_4c,(void *)(param_1 + 0x10),4);
    uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(param_1 + 0x14));
    memcpy((void *)((int)&uStack_48 + 1),(void *)(param_1 + 0x18),4);
    uStack_44 = CONCAT13(*(undefined1 *)(param_1 + 0x1f),
                         CONCAT12(*(undefined1 *)(param_1 + 0x1e),
                                  CONCAT11(*(undefined1 *)(param_1 + 0x1c),(undefined1)uStack_44)));
    uStack_40 = *(undefined4 *)(param_1 + 0x20);
    uStack_3c = CONCAT22(uStack_3c._2_2_,*(undefined2 *)(param_1 + 0x24));
    memcpy((void *)((int)&uStack_3c + 2),(void *)(param_1 + 0x26),0x2a);
    zb_zcl_send_cmd(iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),0,
                    *(undefined1 *)(param_1 + 9),&uStack_4c,0x3c);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

