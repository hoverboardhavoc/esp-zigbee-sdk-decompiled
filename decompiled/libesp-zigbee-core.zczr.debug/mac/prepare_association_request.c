/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_association_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 prepare_association_request(undefined2 *param_1,int *param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined1 auStack_24 [2];
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined1 uStack_1a;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  auStack_24[0] = 3;
  uStack_22 = *param_1;
  uStack_20 = param_1[1];
  uStack_1e = param_1[2];
  uStack_1c = param_1[3];
  uStack_1a = 3;
  uStack_18 = *(undefined4 *)(param_1 + 8);
  uStack_14 = *(undefined4 *)(param_1 + 10);
  uStack_28 = 0xffff;
  uStack_26 = param_1[5];
  if ((ushort)param_1[7] < 0xfffe) {
    uStack_1a = 2;
    uVar1 = (uint)uStack_18 >> 0x10;
    uStack_18 = CONCAT22((short)uVar1,param_1[7]);
  }
  cVar2 = mac_frame_write_hdr(*param_2,auStack_24,&uStack_28,0,3,1);
  *(char *)(param_2 + 1) = cVar2 + '\x02';
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  mac_frame_set_seq_num(param_2);
  iVar4 = *param_2;
  iVar3 = mac_frame_find_payload_index(param_2);
  *(undefined1 *)(iVar4 + iVar3 + 1) = *(undefined1 *)(param_1 + 0x20);
  *(char *)(param_2 + 1) = (char)param_2[1] + '\x01';
  return 0;
}

