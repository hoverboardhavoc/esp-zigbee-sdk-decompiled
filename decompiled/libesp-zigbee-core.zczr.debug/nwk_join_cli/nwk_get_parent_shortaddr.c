/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_get_parent_shortaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_shortaddr_t nwk_get_parent_shortaddr(void)

{
  ezb_shortaddr_t eVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  if (*(int *)(iVar2 + 0xac4) == 0) {
    eVar1 = 0xffff;
  }
  else {
    iVar2 = nwk_is_joined();
    if (iVar2 == 0) {
      iVar2 = core_globals_get();
      eVar1 = **(ezb_shortaddr_t **)(iVar2 + 0xac4);
    }
    else {
      iVar2 = core_globals_get();
      eVar1 = nwk_neighbor_get_shortaddr(*(undefined4 *)(iVar2 + 0xac4));
    }
  }
  return eVar1;
}

