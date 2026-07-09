/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_write_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mac_frame_write_hdr(undefined2 *param_1,byte *param_2,short *param_3,int param_4,int param_5,
                        undefined1 param_6)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  short *psVar7;
  int iVar8;
  uint uVar9;
  
  sVar2 = *param_3;
  sVar3 = param_3[1];
  bVar1 = param_2[10];
  uVar9 = (uint)*param_2;
  uVar5 = (int)(short)((ushort)bVar1 << 10 | (ushort)param_5 | (ushort)param_4) | uVar9 << 0xe;
  uVar6 = uVar5 & 0xffff;
  if ((bVar1 != 0) && (((bVar1 != 2 || (*(short *)(param_2 + 0xc) != -1)) && (param_5 != 2)))) {
    uVar6 = uVar5 & 0xffff | 0x20;
  }
  if (param_4 != 0x1000) {
    if (param_4 == 0x2000) {
      if ((bVar1 == 0) || (uVar9 == 0)) {
        if ((bVar1 == 0) && (uVar9 == 0)) {
          uVar6 = uVar6 | 0x40;
        }
      }
      else if (((bVar1 == 2) || (uVar9 == 2)) && (sVar2 == sVar3)) {
        uVar6 = uVar6 | 0x40;
      }
      goto _L0;
    }
    if (param_4 != 0) goto _L0;
  }
  if (((uVar9 != 0) && (bVar1 != 0)) && (sVar2 == sVar3)) {
    uVar6 = uVar6 | 0x40;
  }
_L0:
  *param_1 = (short)uVar6;
  iVar8 = 2;
  if ((uVar6 & 0x100) == 0) {
    iVar8 = 3;
  }
  psVar7 = (short *)((int)param_1 + iVar8);
  iVar8 = mac_fcf_has_dst_panid(uVar6);
  if (iVar8 != 0) {
    *psVar7 = sVar3;
    psVar7 = psVar7 + 1;
  }
  if (param_2[10] == 2) {
    *psVar7 = *(short *)(param_2 + 0xc);
    psVar7 = psVar7 + 1;
  }
  else if (param_2[10] == 3) {
    uVar4 = *(undefined4 *)(param_2 + 0x10);
    *(undefined4 *)psVar7 = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(psVar7 + 2) = uVar4;
    psVar7 = psVar7 + 4;
  }
  iVar8 = mac_fcf_has_src_panid(uVar6);
  if (iVar8 != 0) {
    *psVar7 = sVar2;
    psVar7 = psVar7 + 1;
  }
  if (*param_2 == 2) {
    *psVar7 = *(short *)(param_2 + 2);
    psVar7 = psVar7 + 1;
  }
  else if (*param_2 == 3) {
    uVar4 = *(undefined4 *)(param_2 + 6);
    *(undefined4 *)psVar7 = *(undefined4 *)(param_2 + 2);
    *(undefined4 *)(psVar7 + 2) = uVar4;
    psVar7 = psVar7 + 4;
  }
  if (param_5 == 3) {
    *(undefined1 *)psVar7 = param_6;
    psVar7 = (short *)((int)psVar7 + 1);
  }
  return (int)psVar7 - (int)param_1 & 0xff;
}

