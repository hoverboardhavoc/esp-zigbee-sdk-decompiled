/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_server_sync_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_time_server_sync_callback(int param_1,int param_2,int param_3)

{
  uint unaff_s0;
  char *pcVar1;
  int aiStack_38 [2];
  undefined2 uStack_30;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined2 *puStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  if (param_1 != 0) {
    pcVar1 = *(char **)(param_1 + 4);
    if (((pcVar1 != (char *)0x0) && (*pcVar1 == '\0')) && (pcVar1[4] != '\0')) {
      aiStack_38[1] = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
      aiStack_38[0] = (uint)*(ushort *)(*(int *)(param_1 + 4) + 2) << 0x10;
      aiStack_38[0] = CONCAT31(aiStack_38[0]._1_3_,2);
      _uStack_30 = param_2 << 0x18;
      uStack_2c = 10;
      uStack_1c = 2;
      uStack_14 = 0;
      uStack_12 = 1;
      puStack_18 = &uStack_14;
      for (unaff_s0 = 0; param_3 = *(int *)(param_1 + 4), unaff_s0 < *(byte *)(param_3 + 4);
          unaff_s0 = unaff_s0 + 1 & 0xff) {
_L0:
        _uStack_30 = CONCAT12(*(undefined1 *)(*(int *)(param_3 + 8) + unaff_s0),uStack_30);
        ezb_zcl_read_attr_cmd_req(aiStack_38);
      }
    }
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/time.c",0x99,
                "zcl_time_server_sync_callback",&_LC5);
  goto _L0;
}

