/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    _Var2 = nwk_mm_is_iface_enabled('\0');
    if ((CONCAT31(extraout_var,_Var2) != 0) &&
       (iVar3 = core_globals_get(), (*(uint *)(iVar3 + 0xce0) >> 7 & 1) != 0)) break;
    uVar1 = '\0';
  }
  *iface_id = '\0';
  return 0;
}

