/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> check_table_ref__1
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
  _Bool _Var2;
  undefined2 in_register_0000202a;
  undefined3 extraout_var;
  uint uVar3;
  undefined2 in_register_00002032;
  uint uVar4;
  bitmap_t __atomic_load_tmp;
  uint uVar5;
  
  uVar4 = CONCAT22(in_register_00002032,table_size);
  uVar3 = CONCAT22(in_register_0000202a,ref);
  puVar1 = (undefined1 *)register0x00002008;
  if (uVar3 < uVar4) goto _L0;
  do {
    register0x00002008 = (BADSPACEBASE *)(puVar1 + -0x10);
    *(undefined4 *)(puVar1 + -4) = unaff_retaddr;
    unaff_retaddr = 0x10568;
    _Var2 = check_table_ref((uint16_t)uVar3,table_map,(uint16_t)uVar4);
    uVar3 = CONCAT31(extraout_var,_Var2);
_L0:
    uVar5 = uVar3 & 7;
    uVar3 = uVar3 >> 3;
    uVar5 = 1 << uVar5 & 0xff;
    table_map = table_map + uVar3;
    fence();
    fence();
    puVar1 = (undefined1 *)register0x00002008;
  } while ((*table_map & uVar5) == 0);
  fence();
  fence();
  return (uVar5 & *table_map) != 0;
}

