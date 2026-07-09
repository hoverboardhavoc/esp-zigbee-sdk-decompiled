/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte zdo_packet_init(undefined1 *param_1,uint param_2,uint param_3,undefined4 param_4,
                    undefined4 param_5)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  
  if (param_1 == (undefined1 *)0x0) {
    return 0x80;
  }
  if (param_3 < 0xfff8) {
    uVar2 = 1;
    goto _L0;
  }
  if (param_2 == 0x13) {
_L0:
    uVar2 = 0;
  }
  else {
    if (param_2 < 0x14) {
      uVar2 = 1;
      if (param_2 < 2) goto _L0;
      uVar3 = 6;
_L48:
      if (param_2 != uVar3) {
        return 0x84;
      }
    }
    else {
      if (param_2 == 0x36) goto _L0;
      if (param_2 < 0x37) {
        if (param_2 != 0x15) {
          uVar3 = 0x1f;
          goto _L48;
        }
      }
      else if (param_2 != 0x38) {
        return 0x84;
      }
    }
    uVar2 = 2;
  }
_L0:
  param_1[8] = uVar2;
  *(short *)(param_1 + 6) = (short)param_2;
  *(short *)(param_1 + 2) = (short)param_3;
  *param_1 = 0xff;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x10) = param_5;
  iVar1 = zmsg_alloc(1);
  *(int *)(param_1 + 0x14) = iVar1;
  return -(iVar1 == 0) & 0x8a;
}

