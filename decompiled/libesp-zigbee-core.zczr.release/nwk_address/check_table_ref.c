/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> check_table_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool check_table_ref(uint param_1,int param_2,uint param_3)

{
  undefined4 unaff_retaddr;
  undefined1 *puVar1;
  int extraout_a1;
  byte *pbVar2;
  uint uVar3;
  
  puVar1 = (undefined1 *)register0x00002008;
  if (param_1 < param_3) goto _L0;
  do {
    register0x00002008 = (BADSPACEBASE *)(puVar1 + -0x10);
    *(undefined4 *)(puVar1 + -4) = unaff_retaddr;
    unaff_retaddr = 0x10480;
    param_1 = __assert_func(0,0,0,0);
    param_2 = extraout_a1;
_L0:
    uVar3 = 1 << (param_1 & 7) & 0xff;
    pbVar2 = (byte *)(param_2 + (param_1 >> 3));
    fence();
    fence();
    puVar1 = (undefined1 *)register0x00002008;
  } while ((*pbVar2 & uVar3) == 0);
  fence();
  fence();
  return (uVar3 & *pbVar2) != 0;
}

