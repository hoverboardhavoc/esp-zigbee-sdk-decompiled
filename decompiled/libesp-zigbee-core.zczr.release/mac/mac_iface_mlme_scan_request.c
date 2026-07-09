/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mlme_scan_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_iface_mlme_scan_request(int *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  
  bVar1 = *param_2;
  iVar4 = *param_1;
  if (bVar1 == 1) {
    uVar8 = *(undefined4 *)(param_2 + 0xc);
    uVar6 = *(undefined4 *)(param_2 + 8);
    bVar1 = param_2[1];
    uVar5 = *(uint *)(param_2 + 4);
    if ((*(uint *)(iVar4 + 0x9c) & 1) == 0) {
      return 3;
    }
    iVar3 = mac_can_scan();
    iVar9 = 9;
    if (iVar3 != 0) {
      *(undefined1 *)(iVar4 + 0x32) = 0xff;
      uVar2 = uVar5 >> 0x1b;
      *(uint *)(iVar4 + 0x34) = *(uint *)(iVar4 + 0x34) & 0x7ffffff | uVar2 << 0x1b;
      *(undefined4 *)(iVar4 + 0x38) = uVar6;
      *(undefined4 *)(iVar4 + 0x3c) = uVar8;
      *(byte *)(iVar4 + 0x33) = bVar1;
      uVar7 = 0;
      if (*(uint *)(iVar4 + 0x18) >> 0x1b == uVar2) {
        uVar7 = *(uint *)(iVar4 + 0x18) & 0x7ffffff & uVar5 & 0x7ffffff;
      }
      *(uint *)(iVar4 + 0x34) = *(uint *)(iVar4 + 0x34) & 0xf8000000 | uVar7;
      mac_start_op(iVar4,1);
      iVar9 = 0;
    }
    return iVar9;
  }
  if (bVar1 < 2) {
    uVar8 = *(undefined4 *)(param_2 + 0xc);
    uVar6 = *(undefined4 *)(param_2 + 8);
    bVar1 = param_2[1];
    uVar5 = *(uint *)(param_2 + 4);
    if ((*(uint *)(iVar4 + 0x9c) & 1) == 0) {
      return 3;
    }
    iVar3 = mac_can_scan();
    iVar9 = 9;
    if (iVar3 != 0) {
      *(undefined1 *)(iVar4 + 0x32) = 0xff;
      uVar2 = uVar5 >> 0x1b;
      *(uint *)(iVar4 + 0x34) = *(uint *)(iVar4 + 0x34) & 0x7ffffff | uVar2 << 0x1b;
      *(undefined4 *)(iVar4 + 0x38) = uVar6;
      *(undefined4 *)(iVar4 + 0x3c) = uVar8;
      *(byte *)(iVar4 + 0x33) = bVar1;
      uVar7 = 0;
      if (*(uint *)(iVar4 + 0x18) >> 0x1b == uVar2) {
        uVar7 = *(uint *)(iVar4 + 0x18) & 0x7ffffff & uVar5 & 0x7ffffff;
      }
      *(uint *)(iVar4 + 0x34) = *(uint *)(iVar4 + 0x34) & 0xf8000000 | uVar7;
      mac_start_op(iVar4,2);
      iVar9 = 0;
    }
    return iVar9;
  }
  return (-(uint)(2 < (byte)(bVar1 - 2)) & 0xfffffffc) + 6;
}

