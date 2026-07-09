/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_beacon_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 prepare_beacon_request(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_14 = 0;
  uStack_1c = 0x20000;
  uStack_18 = 0xffff;
  uStack_28 = 0xffff;
  uStack_26 = 0xffff;
  cVar1 = mac_frame_write_hdr(*param_2,&uStack_24,&uStack_28,0,3,7);
  *(char *)(param_2 + 1) = cVar1 + '\x02';
  *(char *)(param_1 + 0xc) = *(char *)(param_1 + 0xc) + '\x01';
  mac_frame_set_seq_num(param_2);
  return 0;
}

