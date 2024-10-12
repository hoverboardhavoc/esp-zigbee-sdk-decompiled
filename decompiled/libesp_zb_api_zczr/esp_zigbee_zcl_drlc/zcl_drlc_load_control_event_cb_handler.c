/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_drlc.o -> zcl_drlc_load_control_event_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_drlc_load_control_event_cb_handler(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 auStack_38 [4];
  undefined1 uStack_34;
  undefined2 uStack_32;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined1 uStack_22;
  undefined1 uStack_21;
  undefined1 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 *puStack_14;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  memset(auStack_38,0,0x28);
  uStack_34 = *(undefined1 *)(iVar3 + 4);
  uStack_32 = 0x701;
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined4 **)(iVar3 + 0x10);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined1 **)(iVar3 + 0x14);
  uStack_30 = *puVar1;
  uStack_2c = *(undefined2 *)(puVar1 + 1);
  uStack_2a = *(undefined1 *)((int)puVar1 + 6);
  uStack_28 = *(undefined4 *)((int)puVar1 + 7);
  uStack_24 = *(undefined2 *)((int)puVar1 + 0xb);
  uStack_22 = *(undefined1 *)((int)puVar1 + 0xd);
  uStack_21 = *(undefined1 *)((int)puVar1 + 0xe);
  uStack_20 = *(undefined1 *)((int)puVar1 + 0xf);
  uStack_1e = *(undefined2 *)(puVar1 + 4);
  uStack_1c = *(undefined2 *)((int)puVar1 + 0x12);
  uStack_1a = *(undefined1 *)(puVar1 + 5);
  uStack_19 = *(undefined1 *)((int)puVar1 + 0x15);
  uStack_18 = *(undefined1 *)((int)puVar1 + 0x16);
  esp_zb_core_action_handler_schedule(0x40,auStack_38);
  iVar3 = esp_err_to_zb_ret();
  if ((iVar3 == 0) && (puStack_14 != (undefined1 *)0x0)) {
    *puVar2 = *puStack_14;
    puVar2[1] = puStack_14[1];
    puVar2[2] = puStack_14[2];
    puVar2[3] = puStack_14[3];
    puVar2[4] = puStack_14[4];
    puVar2[5] = puStack_14[8];
    puVar2[6] = puStack_14[9];
    puVar2[7] = puStack_14[10];
    puVar2[8] = puStack_14[0xb];
    puVar2[9] = puStack_14[0xc];
    puVar2[10] = puStack_14[0xe];
    puVar2[0xb] = (char)((ushort)*(undefined2 *)(puStack_14 + 0xe) >> 8);
    puVar2[0xc] = puStack_14[0x10];
    puVar2[0xd] = puStack_14[0x11];
    puVar2[0xe] = puStack_14[0x12];
    puVar2[0xf] = puStack_14[0x13];
    puVar2[0x10] = puStack_14[0x14];
    puVar2[0x11] = puStack_14[0x15];
    memcpy(puVar2 + 0x12,puStack_14 + 0x16,0x2a);
  }
  return iVar3;
}

