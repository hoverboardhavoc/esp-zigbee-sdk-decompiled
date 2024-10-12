/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_drlc.o -> zcl_drlc_report_event_status_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_drlc_report_event_status_cb_handler(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  undefined2 uStack_52;
  undefined4 uStack_50;
  undefined1 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 auStack_3a [46];
  
  iVar1 = zb_buf_get_tail_func(0x38);
  memset(auStack_58,0,0x48);
  uStack_54 = *(undefined1 *)(iVar1 + 4);
  uStack_52 = 0x701;
  iVar1 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined4 **)(iVar1 + 0x10);
  uStack_50 = *puVar2;
  uStack_4c = *(undefined1 *)(puVar2 + 1);
  uStack_48 = *(undefined4 *)((int)puVar2 + 5);
  uStack_44 = *(undefined1 *)((int)puVar2 + 9);
  uStack_42 = *(undefined2 *)((int)puVar2 + 10);
  uStack_40 = *(undefined2 *)(puVar2 + 3);
  uStack_3e = *(undefined1 *)((int)puVar2 + 0xe);
  uStack_3d = *(undefined1 *)((int)puVar2 + 0xf);
  uStack_3c = *(undefined1 *)(puVar2 + 4);
  uStack_3b = *(undefined1 *)((int)puVar2 + 0x11);
  memcpy(auStack_3a,(void *)((int)puVar2 + 0x12),0x2a);
  esp_zb_core_action_handler_schedule(0x43,auStack_58);
  esp_err_to_zb_ret();
  return;
}

