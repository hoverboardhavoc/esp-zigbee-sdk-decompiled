/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_drlc.o -> zcl_drlc_cancel_load_control_event_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_drlc_cancel_load_control_event_cb_handler(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_28 [4];
  undefined1 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined2 uStack_1c;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  memset(auStack_28,0,0x18);
  uStack_24 = *(undefined1 *)(iVar3 + 4);
  uStack_22 = 0x701;
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined4 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined1 **)(iVar3 + 0x14);
  uStack_20 = *puVar2;
  uStack_1c = *(undefined2 *)(puVar2 + 1);
  uStack_1a = *(undefined1 *)((int)puVar2 + 6);
  uStack_19 = *(undefined1 *)((int)puVar2 + 7);
  uStack_18 = puVar2[2];
  esp_zb_core_action_handler_schedule(0x41,auStack_28);
  iVar3 = esp_err_to_zb_ret();
  if ((iVar3 == 0) && (puStack_14 != (undefined1 *)0x0)) {
    *puVar1 = *puStack_14;
    puVar1[1] = puStack_14[1];
    puVar1[2] = puStack_14[2];
    puVar1[3] = puStack_14[3];
    puVar1[4] = puStack_14[4];
    puVar1[5] = puStack_14[8];
    puVar1[6] = puStack_14[9];
    puVar1[7] = puStack_14[10];
    puVar1[8] = puStack_14[0xb];
    puVar1[9] = puStack_14[0xc];
    puVar1[10] = puStack_14[0xe];
    puVar1[0xb] = (char)((ushort)*(undefined2 *)(puStack_14 + 0xe) >> 8);
    puVar1[0xc] = puStack_14[0x10];
    puVar1[0xd] = puStack_14[0x11];
    puVar1[0xe] = puStack_14[0x12];
    puVar1[0xf] = puStack_14[0x13];
    puVar1[0x10] = puStack_14[0x14];
    puVar1[0x11] = puStack_14[0x15];
    memcpy(puVar1 + 0x12,puStack_14 + 0x16,0x2a);
  }
  return iVar3;
}

