/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  _Var1 = addr_table_is_inited((nwk_addr_table_t *)(iVar2 + 0xcb0));
  if (CONCAT31(extraout_var,_Var1) == 0) {
    *(undefined1 *)&((nwk_addr_table_t *)(iVar2 + 0xcb0))->ent_in_use = 0;
    *(undefined1 *)(iVar2 + 0xcb1) = 0;
    *(undefined1 *)(iVar2 + 0xcb2) = 0;
    *(undefined1 *)(iVar2 + 0xcb3) = 0;
    *(undefined1 *)(iVar2 + 0xcb4) = 0;
    *(undefined1 *)(iVar2 + 0xcb5) = 0;
    *(undefined1 *)(iVar2 + 0xcb6) = 0;
    *(undefined1 *)(iVar2 + 0xcb7) = 0;
    *(undefined1 *)(iVar2 + 0xcb8) = 0;
    *(undefined1 *)(iVar2 + 0xcb9) = 0;
    *(undefined1 *)(iVar2 + 0xcba) = 0;
    *(undefined1 *)(iVar2 + 0xcbb) = 0;
    *(uint16_t *)(iVar2 + 0xcb8) = capacity;
    uVar3 = mm_calloc(CONCAT22(in_register_0000202a,capacity),0x10);
    *(undefined4 *)(iVar2 + 0xcb4) = uVar3;
    uVar3 = mm_calloc(*(ushort *)(iVar2 + 0xcb8) + 7 >> 3,1);
    *(undefined4 *)(iVar2 + 0xcb0) = uVar3;
    *(undefined2 *)(iVar2 + 0xcba) = 0xffff;
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_address.c",799,"nwk_address_init",&_L0);
  iVar2 = core_globals_get();
  uVar4 = 0;
  while (uVar4 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0xcb0),*(undefined2 *)(iVar2 + 0xcb8),uVar4),
        uVar4 < *(ushort *)(iVar2 + 0xcb8)) {
    nwk_address_delete((nwk_addr_ref_t)uVar4);
    uVar4 = uVar4 + 1 & 0xffff;
  }
  return;
}

