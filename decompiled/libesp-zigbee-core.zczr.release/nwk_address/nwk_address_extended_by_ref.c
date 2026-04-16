/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_extended_by_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000109ec) */
/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_extended_by_ref(nwk_addr_ref_t ref,ezb_extaddr_t *extaddr)

{
  uint uVar1;
  _Bool _Var2;
  int iVar3;
  undefined3 extraout_var;
  undefined2 in_register_0000202a;
  int iVar4;
  ezb_err_t eVar5;
  
  uVar1 = CONCAT22(in_register_0000202a,ref);
  iVar3 = core_globals_get();
  iVar4 = *(int *)(iVar3 + 0xcb4) + uVar1 * 0x10;
  if ((*(byte *)(iVar4 + 0xf) & 4) != 0) {
    uVar1 = (uint)*(ushort *)(iVar4 + 0xc);
  }
  _Var2 = check_table_ref((uint16_t)uVar1,*(bitmap_t **)(iVar3 + 0xcb0),*(uint16_t *)(iVar3 + 0xcb8)
                         );
  eVar5 = 5;
  if (CONCAT31(extraout_var,_Var2) != 0) {
    if (extaddr != (ezb_extaddr_t *)0x0) {
      nwk_extaddr_decompress(extaddr,(nwk_extaddr_c_t *)(*(int *)(iVar3 + 0xcb4) + uVar1 * 0x10));
    }
    eVar5 = 0;
  }
  return eVar5;
}

