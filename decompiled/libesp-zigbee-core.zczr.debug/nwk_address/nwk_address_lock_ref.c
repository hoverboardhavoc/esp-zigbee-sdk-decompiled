/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_lock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_lock_ref(nwk_addr_ref_t ref)

{
  undefined2 in_register_0000202a;
  int iVar1;
  int iVar2;
  
  iVar1 = core_globals_get();
  do_lock_ref((nwk_addr_table_t *)(iVar1 + 0xc4c),ref);
  iVar2 = *(int *)(iVar1 + 0xc50) + CONCAT22(in_register_0000202a,ref) * 0x12;
  if ((*(byte *)(iVar2 + 0x11) & 4) != 0) {
    do_lock_ref((nwk_addr_table_t *)(iVar1 + 0xc4c),*(nwk_addr_ref_t *)(iVar2 + 0xe));
  }
  return;
}

