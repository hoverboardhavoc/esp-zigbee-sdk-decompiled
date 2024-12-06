/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_drlc.o -> zcl_drlc_load_control_event_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_drlc_load_control_event_cb_handler(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_38;
  ushort uStack_34;
  undefined2 uStack_32;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  
  iVar4 = zb_buf_get_tail_func(0x38);
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  puStack_14 = (undefined4 *)0x0;
  _uStack_34 = CONCAT22(0x701,(ushort)*(byte *)(iVar4 + 4));
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar2 = *(undefined4 **)(iVar4 + 0x10);
  iVar4 = zb_buf_get_tail_func(param_1,0x38);
  puVar3 = *(undefined1 **)(iVar4 + 0x14);
  uStack_30 = *puVar2;
  uStack_2c = CONCAT13(uStack_2c._3_1_,*(undefined3 *)(puVar2 + 1));
  uStack_28 = *(undefined4 *)((int)puVar2 + 7);
  uStack_24 = *(undefined4 *)((int)puVar2 + 0xb);
  uStack_20 = CONCAT31(uStack_20._1_3_,*(undefined1 *)((int)puVar2 + 0xf));
  uStack_20 = CONCAT22(*(undefined2 *)(puVar2 + 4),(undefined2)uStack_20);
  uStack_1c = *(undefined4 *)((int)puVar2 + 0x12);
  uStack_18 = CONCAT31(uStack_18._1_3_,*(undefined1 *)((int)puVar2 + 0x16));
  esp_zb_core_action_handler_schedule(0x40,&uStack_38);
  iVar4 = esp_err_to_zb_ret();
  if ((iVar4 == 0) && (puStack_14 != (undefined4 *)0x0)) {
    uVar5 = *puStack_14;
    *puVar3 = (char)uVar5;
    puVar3[1] = (char)((uint)uVar5 >> 8);
    puVar3[2] = (char)((uint)uVar5 >> 0x10);
    puVar3[3] = (char)((uint)uVar5 >> 0x18);
    puVar3[4] = *(undefined1 *)(puStack_14 + 1);
    uVar5 = puStack_14[2];
    puVar3[5] = (char)uVar5;
    puVar3[6] = (char)((uint)uVar5 >> 8);
    puVar3[7] = (char)((uint)uVar5 >> 0x10);
    puVar3[8] = (char)((uint)uVar5 >> 0x18);
    puVar3[9] = *(undefined1 *)(puStack_14 + 3);
    uVar1 = *(undefined2 *)((int)puStack_14 + 0xe);
    puVar3[10] = (char)uVar1;
    puVar3[0xb] = (char)((ushort)uVar1 >> 8);
    uVar1 = *(undefined2 *)(puStack_14 + 4);
    puVar3[0xc] = (char)uVar1;
    puVar3[0xd] = (char)((ushort)uVar1 >> 8);
    puVar3[0xe] = *(undefined1 *)((int)puStack_14 + 0x12);
    puVar3[0xf] = *(undefined1 *)((int)puStack_14 + 0x13);
    puVar3[0x10] = *(undefined1 *)(puStack_14 + 5);
    puVar3[0x11] = *(undefined1 *)((int)puStack_14 + 0x15);
    memcpy(puVar3 + 0x12,(void *)((int)puStack_14 + 0x16),0x2a);
  }
  return iVar4;
}

