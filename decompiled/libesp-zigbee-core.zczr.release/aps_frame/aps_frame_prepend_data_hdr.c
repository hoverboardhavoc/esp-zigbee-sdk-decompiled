/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_prepend_data_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_frame_prepend_data_hdr
               (undefined4 param_1,int param_2,uint param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 uVar7;
  byte abStack_3c [12];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  abStack_3c[0] = 0;
  abStack_3c[1] = 0;
  abStack_3c[2] = 0;
  abStack_3c[3] = 0;
  abStack_3c[4] = 0;
  abStack_3c[5] = 0;
  abStack_3c[6] = 0;
  abStack_3c[7] = 0;
  abStack_3c[8] = 0;
  abStack_3c[9] = 0;
  abStack_3c[10] = 0;
  abStack_3c[0xb] = 0;
  if (*(short *)(param_2 + 4) == 0) {
    uVar3 = (uint)(0xfff7 < *(ushort *)(param_2 + 2)) << 3;
    if (param_4 != 0) goto _L0;
  }
  else {
    uVar3 = 0xc;
    if (param_4 == 0) goto _L0;
_L0:
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uVar3 = uVar3 | 0x20;
    uVar7 = 5;
    if (param_6 != 0) {
      uStack_30 = 0x20;
      uVar7 = 0xd;
    }
    iVar5 = zmsg_prepend_bytes(param_1,uVar7,&uStack_30);
    if (iVar5 != 0) {
      __assert_func(0,0,0,0);
    }
  }
  if ((uVar3 & 0xc) == 0) {
    uVar3 = uVar3 | (param_3 & 3) << 6;
  }
_L0:
  uVar7 = abStack_3c._0_4_;
  bVar2 = (byte)uVar3 | (byte)(param_5 << 7);
  if ((uVar3 & 0xc) == 0xc) {
    pbVar4 = abStack_3c + 3;
    abStack_3c[1] = (char)*(undefined2 *)(param_2 + 4);
    abStack_3c[0] = bVar2;
    abStack_3c[3] = SUB41(uVar7,3);
    abStack_3c[2] = (char)((ushort)*(undefined2 *)(param_2 + 4) >> 8);
  }
  else {
    pbVar4 = abStack_3c + 2;
    abStack_3c[1] = *(undefined1 *)(param_2 + 7);
    abStack_3c[0] = bVar2;
  }
  *(undefined2 *)pbVar4 = *(undefined2 *)(param_2 + 8);
  *(undefined2 *)(pbVar4 + 2) = *(undefined2 *)(param_2 + 10);
  pbVar4[4] = *(byte *)(param_2 + 6);
  pbVar6 = (byte *)core_globals_get();
  bVar1 = *pbVar6;
  *pbVar6 = bVar1 + 1;
  pbVar4[5] = bVar1;
  if ((char)bVar2 < '\0') {
    pbVar4[6] = 1;
    pbVar4 = pbVar4 + 8;
  }
  else {
    pbVar4 = pbVar4 + 6;
  }
  zmsg_prepend_bytes(param_1,(int)pbVar4 - (int)abStack_3c & 0xffff);
  return;
}

