/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_init(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = core_globals_get();
  iVar2 = addr_table_is_inited((undefined1 *)(iVar1 + 0xc4c));
  if (iVar2 == 0) {
    *(undefined1 *)(iVar1 + 0xc4c) = 0;
    *(undefined1 *)(iVar1 + 0xc4d) = 0;
    *(undefined1 *)(iVar1 + 0xc4e) = 0;
    *(undefined1 *)(iVar1 + 0xc4f) = 0;
    *(undefined1 *)(iVar1 + 0xc50) = 0;
    *(undefined1 *)(iVar1 + 0xc51) = 0;
    *(undefined1 *)(iVar1 + 0xc52) = 0;
    *(undefined1 *)(iVar1 + 0xc53) = 0;
    *(undefined1 *)(iVar1 + 0xc54) = 0;
    *(undefined1 *)(iVar1 + 0xc55) = 0;
    *(undefined1 *)(iVar1 + 0xc56) = 0;
    *(undefined1 *)(iVar1 + 0xc57) = 0;
    *(short *)(iVar1 + 0xc54) = (short)param_1;
    uVar3 = mm_calloc(param_1,0x12);
    *(undefined4 *)(iVar1 + 0xc50) = uVar3;
    uVar3 = mm_calloc(*(ushort *)(iVar1 + 0xc54) + 7 >> 3,1);
    *(undefined4 *)(iVar1 + 0xc4c) = uVar3;
    *(undefined2 *)(iVar1 + 0xc56) = 0xffff;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x2b5,
                "nwk_address_init",&_L0);
  iVar1 = core_globals_get();
  uVar4 = 0;
  while( true ) {
    uVar4 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar1 + 0xc4c),*(undefined2 *)(iVar1 + 0xc54),uVar4);
    if (*(ushort *)(iVar1 + 0xc54) <= uVar4) break;
    nwk_address_delete(uVar4);
    uVar4 = uVar4 + 1 & 0xffff;
  }
  return;
}

