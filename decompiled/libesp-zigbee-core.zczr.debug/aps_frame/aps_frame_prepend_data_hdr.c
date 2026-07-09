/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_frame.o -> aps_frame_prepend_data_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_frame_prepend_data_hdr
               (undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  byte *pbVar6;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  byte abStack_2c [20];
  
  abStack_2c[0] = 0;
  abStack_2c[1] = 0;
  abStack_2c[2] = 0;
  abStack_2c[3] = 0;
  abStack_2c[4] = 0;
  abStack_2c[5] = 0;
  abStack_2c[6] = 0;
  abStack_2c[7] = 0;
  abStack_2c[8] = 0;
  abStack_2c[9] = 0;
  abStack_2c[10] = 0;
  abStack_2c[0xb] = 0;
  if (*(short *)(param_2 + 4) == 0) {
    if (*(ushort *)(param_2 + 2) < 0xfff8) {
      bVar2 = 0;
    }
    else {
      bVar2 = 8;
    }
  }
  else {
    bVar2 = 0xc;
  }
  if (param_4 == 0) {
_L0:
    uVar5 = abStack_2c._0_4_;
    if (((bVar2 & 0xc) == 0) && (param_3 != 0)) {
      bVar2 = bVar2 | 0x40;
    }
    if (param_5 != 0) {
      bVar2 = bVar2 | 0x80;
    }
    abStack_2c[0] = bVar2;
    if ((bVar2 & 0xc) != 0xc) {
      abStack_2c._2_2_ = SUB42(uVar5,2);
      abStack_2c[1] = *(undefined1 *)(param_2 + 7);
      pbVar6 = abStack_2c + 2;
      goto _L0;
    }
  }
  else {
    bVar2 = bVar2 | 0x20;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    if (param_6 == 0) {
      uVar5 = 5;
    }
    else {
      uStack_3c = 0x20;
      uVar5 = 0xd;
    }
    iVar3 = zmsg_prepend_bytes(param_1,uVar5,&uStack_3c);
    if (iVar3 == 0) goto _L0;
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_frame.c",0xd9,
                  "aps_frame_prepend_data_hdr",
                  "(zmsg_prepend_bytes(msg, aux_hdr_size, &aux_hdr)) == 0");
  }
  uVar5 = abStack_2c._0_4_;
  abStack_2c[1] = (char)*(undefined2 *)(param_2 + 4);
  abStack_2c[3] = SUB41(uVar5,3);
  abStack_2c[2] = (char)((ushort)*(undefined2 *)(param_2 + 4) >> 8);
  pbVar6 = abStack_2c + 3;
_L0:
  *(undefined2 *)pbVar6 = *(undefined2 *)(param_2 + 8);
  *(undefined2 *)(pbVar6 + 2) = *(undefined2 *)(param_2 + 10);
  pbVar6[4] = *(byte *)(param_2 + 6);
  pbVar4 = (byte *)core_globals_get();
  bVar1 = *pbVar4;
  *pbVar4 = bVar1 + 1;
  pbVar6[5] = bVar1;
  pbVar4 = pbVar6 + 6;
  if ((char)bVar2 < '\0') {
    pbVar6[6] = 1;
    pbVar4 = pbVar6 + 8;
  }
  zmsg_prepend_bytes(param_1,(int)pbVar4 - (int)abStack_2c & 0xffff);
  return;
}

