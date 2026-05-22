/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_init(uint16_t capacity)

{
  _Bool _Var1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = core_globals_get();
  _Var1 = addr_table_is_inited((nwk_addr_table_t *)(iVar2 + 0xc4c));
  if (CONCAT31(extraout_var,_Var1) == 0) {
    *(undefined1 *)&((nwk_addr_table_t *)(iVar2 + 0xc4c))->ent_in_use = 0;
    *(undefined1 *)(iVar2 + 0xc4d) = 0;
    *(undefined1 *)(iVar2 + 0xc4e) = 0;
    *(undefined1 *)(iVar2 + 0xc4f) = 0;
    *(undefined1 *)(iVar2 + 0xc50) = 0;
    *(undefined1 *)(iVar2 + 0xc51) = 0;
    *(undefined1 *)(iVar2 + 0xc52) = 0;
    *(undefined1 *)(iVar2 + 0xc53) = 0;
    *(undefined1 *)(iVar2 + 0xc54) = 0;
    *(undefined1 *)(iVar2 + 0xc55) = 0;
    *(undefined1 *)(iVar2 + 0xc56) = 0;
    *(undefined1 *)(iVar2 + 0xc57) = 0;
    *(uint16_t *)(iVar2 + 0xc54) = capacity;
    uVar3 = mm_calloc(CONCAT22(in_register_0000202a,capacity),0x12);
    *(undefined4 *)(iVar2 + 0xc50) = uVar3;
    uVar3 = mm_calloc(*(ushort *)(iVar2 + 0xc54) + 7 >> 3,1);
    *(undefined4 *)(iVar2 + 0xc4c) = uVar3;
    *(undefined2 *)(iVar2 + 0xc56) = 0xffff;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x2b3,
                "nwk_address_init",&_L0);
  iVar2 = core_globals_get();
  uVar4 = 0;
  while (uVar4 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0xc4c),*(undefined2 *)(iVar2 + 0xc54),uVar4),
        uVar4 < *(ushort *)(iVar2 + 0xc54)) {
    nwk_address_delete((nwk_addr_ref_t)uVar4);
    uVar4 = uVar4 + 1 & 0xffff;
  }
  return;
}

