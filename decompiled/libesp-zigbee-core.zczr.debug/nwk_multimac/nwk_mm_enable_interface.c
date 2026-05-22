/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac.o -> nwk_mm_enable_interface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_enable_interface(uint8_t iface_id)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  int iVar2;
  ezb_err_t eVar3;
  
  if (CONCAT31(in_register_00002029,iface_id) == 0) {
    _Var1 = nwk_mm_iface_is_disabled(iface_id);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      eVar3 = 3;
    }
    else {
      iVar2 = core_globals_get();
      *(uint *)(iVar2 + 0xc7c) = *(uint *)(iVar2 + 0xc7c) & 0xffffff9f | 0x40;
      mac_iface_set_enabled(iface_id,true);
      eVar3 = 0;
    }
  }
  else {
    eVar3 = 2;
  }
  return eVar3;
}

