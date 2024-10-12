/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_drlc_cancel_load_control_event_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_drlc_cancel_load_control_event_req(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_16;
  undefined1 auStack_14 [8];
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    pcVar2 = (char *)zb_zcl_get_ctx();
    *pcVar2 = *pcVar2 + '\x01';
  }
  else {
    memcpy(auStack_1c,(void *)(param_1 + 0x10),4);
    uStack_18 = *(undefined1 *)(param_1 + 0x14);
    uStack_17 = *(undefined1 *)(param_1 + 0x15);
    uStack_16 = *(undefined2 *)(param_1 + 0x16);
    memcpy(auStack_14,(void *)(param_1 + 0x18),4);
    zb_zcl_send_cmd(iVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),1,
                    *(undefined1 *)(param_1 + 9),auStack_1c,0xc);
    zb_zcl_frame_get_sequence_number(iVar1);
  }
  return;
}

