/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_write_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mac_frame_write_hdr(undefined2 *param_1,byte *param_2,short *param_3,uint param_4,uint param_5,
                        undefined1 param_6)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  
  uVar10 = (uint)param_2[10];
  uVar11 = (uint)*param_2;
  uVar7 = uVar10 << 10 | uVar11 << 0xe | param_5 | param_4;
  sVar1 = *param_3;
  sVar2 = param_3[1];
  uVar8 = uVar7 & 0xffff;
  if (uVar10 == 0) {
    if (((param_4 != 0x1000) && (param_4 == 0x2000)) && (uVar11 == 0)) {
      uVar8 = uVar7 & 0xffff | 0x40;
    }
    goto _L0;
  }
  if (((uVar10 != 2) || (*(short *)(param_2 + 0xc) != -1)) && (param_5 != 2)) {
    uVar8 = uVar7 & 0xffff | 0x20;
  }
  if (param_4 == 0x1000) {
_L0:
    if (uVar11 == 0) goto _L0;
  }
  else {
    if (param_4 != 0x2000) {
      if (param_4 != 0) goto _L0;
      goto _L0;
    }
    if ((uVar11 == 0) || ((uVar10 != 2 && (uVar11 != 2)))) goto _L0;
  }
  if (sVar1 == sVar2) {
    uVar8 = uVar8 | 0x40;
  }
_L0:
  bVar3 = (uVar8 & 0x100) == 0;
  *param_1 = (short)uVar8;
  psVar5 = (short *)((int)param_1 + bVar3 + 2);
  iVar9 = mac_fcf_has_dst_panid(uVar8);
  if (iVar9 != 0) {
    *psVar5 = sVar2;
    psVar5 = (short *)((int)param_1 + bVar3 + 4);
  }
  if (uVar10 == 2) {
    psVar6 = psVar5 + 1;
    *psVar5 = *(short *)(param_2 + 0xc);
  }
  else {
    psVar6 = psVar5;
    if (uVar10 == 3) {
      uVar4 = *(undefined4 *)(param_2 + 0x10);
      *(undefined4 *)psVar5 = *(undefined4 *)(param_2 + 0xc);
      *(undefined4 *)(psVar5 + 2) = uVar4;
      psVar6 = psVar5 + 4;
    }
  }
  iVar9 = mac_fcf_has_src_panid(uVar8);
  if (iVar9 != 0) {
    *psVar6 = sVar1;
    psVar6 = psVar6 + 1;
  }
  if (uVar11 == 2) {
    psVar5 = psVar6 + 1;
    *psVar6 = *(short *)(param_2 + 2);
  }
  else {
    psVar5 = psVar6;
    if (uVar11 == 3) {
      uVar4 = *(undefined4 *)(param_2 + 6);
      *(undefined4 *)psVar6 = *(undefined4 *)(param_2 + 2);
      *(undefined4 *)(psVar6 + 2) = uVar4;
      psVar5 = psVar6 + 4;
    }
  }
  if (param_5 == 3) {
    *(undefined1 *)psVar5 = param_6;
    psVar5 = (short *)((int)psVar5 + 1);
  }
  return (int)psVar5 - (int)param_1 & 0xff;
}

