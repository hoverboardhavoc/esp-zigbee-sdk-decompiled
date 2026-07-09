/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 prepare_data_request(ushort *param_1,undefined4 *param_2)

{
  uint uVar1;
  char cVar2;
  ushort uStack_28;
  ushort uStack_26;
  undefined1 auStack_24 [2];
  ushort uStack_22;
  ushort uStack_20;
  ushort uStack_1e;
  ushort uStack_1c;
  undefined1 uStack_1a;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  auStack_24[0] = 3;
  uStack_20 = param_1[1];
  uStack_1e = param_1[2];
  uStack_1c = param_1[3];
  uStack_1a = 3;
  uStack_18 = *(undefined4 *)(param_1 + 8);
  uStack_14 = *(undefined4 *)(param_1 + 10);
  uStack_28 = param_1[5];
  if (param_1[7] < 0xfffe) {
    uStack_1a = 2;
    uVar1 = (uint)uStack_18 >> 0x10;
    uStack_18 = CONCAT22((short)uVar1,param_1[7]);
  }
  uStack_22 = *param_1;
  if (param_1[4] < 0xfffe) {
    auStack_24[0] = 2;
    uStack_22 = param_1[4];
  }
  uStack_26 = uStack_28;
  cVar2 = mac_frame_write_hdr(*param_2,auStack_24,&uStack_28,0,3,4);
  *(char *)(param_2 + 1) = cVar2 + '\x02';
  *(char *)(param_1 + 6) = (char)param_1[6] + '\x01';
  mac_frame_set_seq_num(param_2);
  return 0;
}

