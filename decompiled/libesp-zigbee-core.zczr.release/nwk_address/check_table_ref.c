/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> check_table_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool check_table_ref(uint16_t ref,bitmap_t *table_map,uint16_t table_size)

{
  undefined4 unaff_retaddr;
  undefined1 *puVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  bitmap_t *extraout_a1;
  undefined2 in_register_00002032;
  bitmap_t __atomic_load_tmp;
  uint uVar3;
  
  uVar2 = CONCAT22(in_register_0000202a,ref);
  puVar1 = (undefined1 *)register0x00002008;
  if (uVar2 < CONCAT22(in_register_00002032,table_size)) goto _L0;
  do {
    register0x00002008 = (BADSPACEBASE *)(puVar1 + -0x10);
    *(undefined4 *)(puVar1 + -4) = unaff_retaddr;
    unaff_retaddr = 0x1042c;
    uVar2 = __assert_func(0,0,0,0);
    table_map = extraout_a1;
_L0:
    uVar3 = 1 << (uVar2 & 7) & 0xff;
    fence();
    fence();
    puVar1 = (undefined1 *)register0x00002008;
  } while ((table_map[uVar2 >> 3] & uVar3) == 0);
  fence();
  fence();
  return (uVar3 & table_map[uVar2 >> 3]) != 0;
}

