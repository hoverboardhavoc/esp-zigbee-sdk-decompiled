/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zcl_custom_cluster_cmd_req(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_34 [2];
  undefined1 auStack_32 [8];
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  byte bStack_24;
  undefined4 uStack_20;
  undefined1 uStack_18;
  undefined2 uStack_16;
  undefined4 uStack_14;
  
  memset(auStack_34,0,0x24);
  if (param_1 != (void *)0x0) {
    uStack_20 = get_zcl_send_status_cb_handle();
    uVar3 = *(uint *)((int)param_1 + 0x10);
    bStack_24 = (byte)(uVar3 >> 1) & 2 | (byte)uVar3 & 1 | (byte)(uVar3 >> 1) & 4 | bStack_24 & 0xf8
    ;
    uStack_26 = *(undefined2 *)((int)param_1 + 0x12);
    auStack_34[0] = *(undefined1 *)((int)param_1 + 10);
    uStack_2a = *(undefined2 *)((int)param_1 + 8);
    uStack_28 = *(undefined2 *)((int)param_1 + 0xe);
    memcpy(auStack_32,param_1,8);
    uStack_18 = (undefined1)*(undefined2 *)((int)param_1 + 0x14);
    uStack_16 = *(undefined2 *)((int)param_1 + 0x1a);
    uStack_14 = *(undefined4 *)((int)param_1 + 0x1c);
    iVar1 = ezb_zcl_custom_cmd_req(auStack_34);
    if (iVar1 == 0) {
      uVar2 = zcl_get_current_tsn();
      return uVar2;
    }
  }
  return 0xff;
}

