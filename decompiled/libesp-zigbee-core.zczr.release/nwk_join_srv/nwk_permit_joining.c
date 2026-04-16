/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_permit_joining
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_permit_joining(uint8_t permit_duration)

{
  _Bool _Var1;
  undefined3 in_register_00002029;
  undefined3 extraout_var;
  int iVar2;
  ezb_err_t eVar3;
  undefined1 uStack_18;
  undefined1 uStack_17;
  uint8_t uStack_16;
  nwk_nlme_event_ind_t ind;
  
  _Var1 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    eVar3 = 0x2c2;
  }
  else {
    iVar2 = core_globals_get();
    if ((uint)*(byte *)(iVar2 + 0xb07) != CONCAT31(in_register_00002029,permit_duration)) {
      nwk_set_mac_permit_joining(CONCAT31(in_register_00002029,permit_duration) != 0);
      memset(&uStack_17,0,7);
      uStack_18 = 1;
      uStack_16 = permit_duration;
      nwk_nlme_event_indication(&uStack_18);
      iVar2 = core_globals_get();
      *(uint8_t *)(iVar2 + 0xb07) = permit_duration;
    }
    eVar3 = 0;
  }
  return eVar3;
}

