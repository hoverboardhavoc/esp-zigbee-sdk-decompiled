/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_get_new_nbr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nbt_get_new_nbr(undefined4 *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    uVar3 = (uint)*(ushort *)(param_1 + 2);
    uVar2 = uVar3 - *(ushort *)((int)param_1 + 10) & 0xffff;
  }
  else {
    uVar3 = (uint)*(ushort *)(param_1 + 2) - (uint)*(ushort *)((int)param_1 + 10) & 0xffff;
    uVar2 = 0;
  }
  uVar2 = bitmap_find_next_zero_bit(*param_1,*(undefined2 *)(param_1 + 2),uVar2);
  if (uVar2 < uVar3) {
    cVar1 = test_and_set_bitmap(*param_1);
    if (cVar1 == '\x01') {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x124,
                    "nbt_get_new_nbr",0x101f4);
    }
    else {
      uVar2 = param_1[1] + uVar2 * 0x1c;
      if (param_2 != 0) {
        nbt_inc_router_cnt(param_1);
        return uVar2;
      }
    }
    nbt_inc_ed_cnt(param_1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

