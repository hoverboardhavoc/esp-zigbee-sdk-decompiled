/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_publish_snapshot_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_metering_publish_snapshot_cb_handler(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
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
  if (zb_core_action_cb == (code *)0x0) {
    uVar4 = 0;
  }
  else {
    (*zb_core_action_cb)(0x13,auStack_50);
    uVar4 = error_to_zb_ret();
  }
  return uVar4;
}

