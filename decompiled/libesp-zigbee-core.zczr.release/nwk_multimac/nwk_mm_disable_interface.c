/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac.o -> nwk_mm_disable_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_disable_interface(uint8_t iface_id)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  int iVar2;
  undefined1 in_a1;
  ezb_err_t eVar3;
  
  if (CONCAT31(in_register_00002029,iface_id) == 0) {
    _Var1 = nwk_mm_is_iface_enabled(iface_id);
    eVar3 = 3;
    if (CONCAT31(extraout_var,_Var1) != 0) {
      mac_iface_set_enabled('\0',(_Bool)in_a1);
      iVar2 = core_globals_get();
      *(uint *)(iVar2 + 0xce0) = *(uint *)(iVar2 + 0xce0) & 0xffffff9f | 0x20;
      eVar3 = 0;
    }
    return eVar3;
  }
  return 2;
}

