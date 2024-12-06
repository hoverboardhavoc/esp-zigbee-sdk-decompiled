/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_drlc.o -> zcl_drlc_get_scheduled_events_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_drlc_get_scheduled_events_cb_handler(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_28;
  ushort uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  uStack_28 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  puStack_14 = (undefined4 *)0x0;
  _uStack_24 = CONCAT22(0x701,(ushort)*(byte *)(iVar4 + 4));
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined4 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar3 = *(undefined1 **)(iVar4 + 0x14);
  uStack_18 = *(undefined4 *)((int)puVar2 + 5);
  uStack_20 = *puVar2;
  uStack_1c = CONCAT31(uStack_1c._1_3_,*(undefined1 *)(puVar2 + 1));
  esp_zb_core_action_handler_schedule(0x44,&uStack_28);
  iVar4 = esp_err_to_zb_ret();
  if ((iVar4 == 0) && (puStack_14 != (undefined4 *)0x0)) {
    uVar5 = *puStack_14;
    *puVar3 = (char)uVar5;
    puVar3[1] = (char)((uint)uVar5 >> 8);
    puVar3[2] = (char)((uint)uVar5 >> 0x10);
    puVar3[3] = (char)((uint)uVar5 >> 0x18);
    uVar1 = *(undefined2 *)(puStack_14 + 1);
    puVar3[4] = (char)uVar1;
    puVar3[5] = (char)((ushort)uVar1 >> 8);
    puVar3[6] = *(undefined1 *)((int)puStack_14 + 6);
    uVar5 = puStack_14[2];
    puVar3[7] = (char)uVar5;
    puVar3[8] = (char)((uint)uVar5 >> 8);
    puVar3[9] = (char)((uint)uVar5 >> 0x10);
    puVar3[10] = (char)((uint)uVar5 >> 0x18);
    uVar1 = *(undefined2 *)(puStack_14 + 3);
    puVar3[0xb] = (char)uVar1;
    puVar3[0xc] = (char)((ushort)uVar1 >> 8);
    puVar3[0xd] = *(undefined1 *)((int)puStack_14 + 0xe);
    puVar3[0xe] = *(undefined1 *)((int)puStack_14 + 0xf);
    puVar3[0xf] = *(undefined1 *)(puStack_14 + 4);
    uVar1 = *(undefined2 *)((int)puStack_14 + 0x12);
    puVar3[0x10] = (char)uVar1;
    puVar3[0x11] = (char)((ushort)uVar1 >> 8);
    uVar1 = *(undefined2 *)(puStack_14 + 5);
    puVar3[0x12] = (char)uVar1;
    puVar3[0x13] = (char)((ushort)uVar1 >> 8);
    puVar3[0x14] = *(undefined1 *)((int)puStack_14 + 0x16);
    puVar3[0x15] = *(undefined1 *)((int)puStack_14 + 0x17);
    puVar3[0x16] = *(undefined1 *)(puStack_14 + 6);
  }
  return;
}

