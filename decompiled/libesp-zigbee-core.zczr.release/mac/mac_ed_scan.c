/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_ed_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
mac_ed_scan(int param_1,uint param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((*(uint *)(param_1 + 0x9c) & 1) != 0) {
    iVar1 = mac_can_scan();
    uVar3 = 9;
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x32) = 0xff;
      *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0x7ffffff | (param_2 >> 0x1b) << 0x1b;
      *(undefined4 *)(param_1 + 0x38) = param_4;
      *(undefined4 *)(param_1 + 0x3c) = param_5;
      *(undefined1 *)(param_1 + 0x33) = param_3;
      uVar2 = 0;
      if (*(uint *)(param_1 + 0x18) >> 0x1b == param_2 >> 0x1b) {
        uVar2 = *(uint *)(param_1 + 0x18) & 0x7ffffff & param_2 & 0x7ffffff;
      }
      *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xf8000000 | uVar2;
      mac_start_op(param_1,2);
      uVar3 = 0;
    }
    return uVar3;
  }
  return 3;
}

