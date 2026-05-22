/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac.o -> nwk_mm_get_next_router_iface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_get_next_router_iface(uint8_t *iface_id)

{
  uint8_t uVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  int iVar3;
  
  uVar1 = *iface_id;
  while( true ) {
    if (uVar1 != 0xff) {
      *iface_id = '\0';
      return 5;
    }
    _Var2 = nwk_mm_iface_is_enabled('\0');
    if ((CONCAT31(extraout_var,_Var2) != 0) &&
       (iVar3 = core_globals_get(), (*(uint *)(iVar3 + 0xc7c) >> 7 & 1) != 0)) break;
    uVar1 = '\0';
  }
  *iface_id = '\0';
  return 0;
}

