/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_data_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void prepare_data_msg(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined2 local_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  local_30 = *(undefined2 *)(param_1 + 10);
  uStack_2e = *(undefined2 *)(param_3 + 0x18);
  uVar1 = mac_frame_write_hdr(&uStack_2c,param_3 + 4,&local_30,0,1,0);
  zmsg_prepend_bytes(param_2,uVar1,&uStack_2c);
  return;
}

