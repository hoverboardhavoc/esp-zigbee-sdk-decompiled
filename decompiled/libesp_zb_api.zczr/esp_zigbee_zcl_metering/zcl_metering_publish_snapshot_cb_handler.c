/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_metering.o -> zcl_metering_publish_snapshot_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_metering_publish_snapshot_cb_handler(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_50 [4];
  undefined1 uStack_4c;
  undefined2 uStack_4a;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [40];
  
  iVar2 = zb_buf_get_tail_func(0x38);
  iVar3 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined4 **)(iVar3 + 0x10);
  memset(auStack_50,0,0x40);
  uStack_4c = *(undefined1 *)(iVar2 + 4);
  uStack_4a = 0x702;
  uStack_48 = *puVar1;
  uStack_44 = puVar1[1];
  uStack_40 = *(undefined1 *)(puVar1 + 2);
  uStack_3f = *(undefined1 *)((int)puVar1 + 9);
  uStack_3e = *(undefined1 *)((int)puVar1 + 10);
  uStack_3c = *(undefined4 *)((int)puVar1 + 0xb);
  uStack_38 = (uint)*(byte *)((int)puVar1 + 0xf);
  memcpy(auStack_34,puVar1 + 4,0x21);
  esp_zb_core_action_handler_schedule(0xd,auStack_50);
  esp_err_to_zb_ret();
  return;
}

