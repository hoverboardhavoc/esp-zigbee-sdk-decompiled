/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_drlc_load_control_event_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_drlc_load_control_event_req(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_28 [4];
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 auStack_21 [4];
  undefined1 uStack_1d;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    pcVar2 = (char *)zb_zcl_get_ctx();
    *pcVar2 = *pcVar2 + '\x01';
  }
  else {
    memcpy(auStack_28,(void *)(param_1 + 0x10),4);
    uStack_24 = *(undefined1 *)(param_1 + 0x14);
    uStack_23 = *(undefined1 *)(param_1 + 0x15);
    uStack_22 = *(undefined1 *)(param_1 + 0x16);
    memcpy(auStack_21,(void *)(param_1 + 0x18),4);
    uStack_1d = *(undefined1 *)(param_1 + 0x1c);
    uStack_1c = *(undefined1 *)(param_1 + 0x1d);
    uStack_1b = *(undefined1 *)(param_1 + 0x1e);
    uStack_1a = *(undefined1 *)(param_1 + 0x1f);
    uStack_19 = *(undefined1 *)(param_1 + 0x20);
    uStack_18 = *(undefined1 *)(param_1 + 0x22);
    uStack_17 = *(undefined1 *)(param_1 + 0x23);
    uStack_16 = *(undefined1 *)(param_1 + 0x24);
    uStack_15 = *(undefined1 *)(param_1 + 0x25);
    uStack_14 = *(undefined2 *)(param_1 + 0x26);
    uStack_12 = *(undefined1 *)(param_1 + 0x28);
    zb_zcl_send_cmd(iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),1,
                    *(undefined1 *)(param_1 + 9),auStack_28,0x17);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

