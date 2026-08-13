/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_setup_stamp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_packet_setup_stamp
              (int param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,int param_5,
              undefined1 param_6,undefined1 *param_7)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  byte bVar7;
  int iVar8;
  undefined1 *extraout_a1;
  undefined1 uVar9;
  undefined *puVar10;
  
  if (param_7 != (undefined1 *)0x0) {
    *(undefined1 *)(param_1 + 0x14) = param_2;
    *(undefined1 *)(param_1 + 0x15) = param_3;
    *(undefined2 *)(param_1 + 0x16) = param_4;
    *(short *)(param_1 + 0x18) = (short)param_5;
    *(undefined1 *)(param_1 + 10) = param_6;
    uVar9 = param_7[1];
    uVar1 = param_7[2];
    uVar2 = param_7[3];
    uVar3 = param_7[4];
    uVar4 = param_7[5];
    uVar5 = param_7[6];
    uVar6 = param_7[7];
    *(undefined1 *)(param_1 + 0xc) = *param_7;
    *(undefined1 *)(param_1 + 0xd) = uVar9;
    *(undefined1 *)(param_1 + 0xe) = uVar1;
    *(undefined1 *)(param_1 + 0xf) = uVar2;
    *(undefined1 *)(param_1 + 0x10) = uVar3;
    *(undefined1 *)(param_1 + 0x11) = uVar4;
    *(undefined1 *)(param_1 + 0x12) = uVar5;
    *(undefined1 *)(param_1 + 0x13) = uVar6;
    return param_1;
  }
  puVar10 = &_L0;
  uVar9 = 0xe8;
  iVar8 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0xfa);
  if (iVar8 == 0) {
    iVar8 = 0x87;
  }
  else if (extraout_a1 == (undefined1 *)0x0) {
    iVar8 = 0x87;
  }
  else {
    *(undefined1 *)(iVar8 + 0x1e) = extraout_a1[0x1e];
    *(undefined1 *)(iVar8 + 0x20) = uVar9;
    *(undefined2 *)(iVar8 + 0x1c) = *(undefined2 *)(extraout_a1 + 0x1c);
    bVar7 = extraout_a1[0x1a];
    *(byte *)(iVar8 + 0x1a) = bVar7;
    if ((bVar7 & 8) == 0) {
      *(byte *)(iVar8 + 0x1a) = bVar7 | 8;
    }
    else {
      *(byte *)(iVar8 + 0x1a) = bVar7 & 0xf7;
    }
    if (param_5 == 0) {
      *(byte *)(iVar8 + 0x1a) = *(byte *)(iVar8 + 0x1a) & 0xef;
    }
    else {
      *(byte *)(iVar8 + 0x1a) = *(byte *)(iVar8 + 0x1a) | 0x10;
    }
    zcl_packet_setup_stamp
              (iVar8,extraout_a1[0x15],extraout_a1[0x14],*(undefined2 *)(extraout_a1 + 0x16),
               *(undefined2 *)(extraout_a1 + 0x18),*extraout_a1,extraout_a1 + 2);
    if (puVar10 == (undefined *)0x0) {
      *(undefined1 *)(iVar8 + 0x1e) = extraout_a1[0x1e];
      *(byte *)(iVar8 + 0x1a) = *(byte *)(iVar8 + 0x1a) | 0x20;
      iVar8 = 0;
    }
    else {
      *(undefined1 *)(iVar8 + 0x1e) = 0xff;
      *(byte *)(iVar8 + 0x1a) = *(byte *)(iVar8 + 0x1a) & 0xdf;
      iVar8 = 0;
    }
  }
  return iVar8;
}

