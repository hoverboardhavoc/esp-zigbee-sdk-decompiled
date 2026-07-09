/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zdo_packet_init(undefined1 *param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (undefined1 *)0x0) {
    return 0x80;
  }
  if (param_3 < 0xfff8) {
    param_1[8] = 1;
    goto _L0;
  }
  if (param_2 == 0x13) {
_L0:
    param_1[8] = 0;
  }
  else {
    if (param_2 < 0x14) {
      if (param_2 < 2) {
        param_1[8] = 1;
        goto _L0;
      }
      if (param_2 != 6) {
        return 0x84;
      }
    }
    else {
      if (param_2 == 0x36) goto _L0;
      if (param_2 < 0x37) {
        if ((param_2 != 0x15) && (param_2 != 0x1f)) {
          return 0x84;
        }
      }
      else if (param_2 != 0x38) {
        return 0x84;
      }
    }
    param_1[8] = 2;
  }
_L0:
  *(short *)(param_1 + 6) = (short)param_2;
  *(short *)(param_1 + 2) = (short)param_3;
  *param_1 = 0xff;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x10) = param_5;
  iVar1 = zmsg_alloc(1);
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0x8a;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

