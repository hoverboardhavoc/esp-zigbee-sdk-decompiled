/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> zcl_time_server_sync_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_time_server_sync_callback(int param_1,undefined1 param_2)

{
  uint uVar1;
  undefined1 extraout_a1;
  char *pcVar2;
  undefined4 uStack_48;
  undefined1 auStack_44 [2];
  undefined2 uStack_42;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined2 uStack_38;
  undefined1 uStack_28;
  undefined4 *puStack_24;
  
  if (param_1 == 0) {
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  pcVar2 = *(char **)(param_1 + 4);
  if (((pcVar2 != (char *)0x0) && (*pcVar2 == '\0')) && (pcVar2[4] != '\0')) {
    memset(auStack_44,0,0x20);
    uStack_42 = *(undefined2 *)(pcVar2 + 2);
    auStack_44[0] = 2;
    uStack_28 = 2;
    uStack_48 = 0x10000;
    puStack_24 = &uStack_48;
    uStack_38 = 10;
    uVar1 = 0;
    uStack_39 = param_2;
    while( true ) {
      if (*(byte *)(*(int *)(param_1 + 4) + 4) <= uVar1) break;
      uStack_3a = *(undefined1 *)(*(int *)(*(int *)(param_1 + 4) + 8) + uVar1);
      uVar1 = uVar1 + 1 & 0xff;
      ezb_zcl_read_attr_cmd_req(auStack_44);
    }
  }
  return;
}

