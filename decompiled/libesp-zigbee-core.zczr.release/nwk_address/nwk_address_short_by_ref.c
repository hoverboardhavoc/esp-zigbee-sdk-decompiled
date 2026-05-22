/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_short_by_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000108c4) */
/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_short_by_ref(nwk_addr_ref_t ref,ezb_shortaddr_t *shortaddr)

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
  iVar4 = *(int *)(iVar3 + 0xc50) + uVar1 * 0x12;
  if ((*(byte *)(iVar4 + 0x11) & 4) != 0) {
    uVar1 = (uint)*(ushort *)(iVar4 + 0xe);
  }
  _Var2 = check_table_ref((uint16_t)uVar1,*(bitmap_t **)(iVar3 + 0xc4c),*(uint16_t *)(iVar3 + 0xc54)
                         );
  eVar5 = 5;
  if (CONCAT31(extraout_var,_Var2) != 0) {
    if (shortaddr != (ezb_shortaddr_t *)0x0) {
      *shortaddr = *(ezb_shortaddr_t *)(*(int *)(iVar3 + 0xc50) + uVar1 * 0x12 + 8);
    }
    eVar5 = 0;
  }
  return eVar5;
}

