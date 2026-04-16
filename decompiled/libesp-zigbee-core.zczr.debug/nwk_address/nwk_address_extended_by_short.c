/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_extended_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_address_extended_by_short(ezb_shortaddr_t shortaddr,ezb_extaddr_t *extaddr)

{
  int iVar1;
  ezb_err_t eVar2;
  nwk_addr_ref_t anStack_12 [2];
  nwk_addr_ref_t ref;
  
  eVar2 = nwk_address_ref_by_short(shortaddr,anStack_12);
  if ((eVar2 == 0) && (eVar2 = nwk_address_extended_by_ref(anStack_12[0],extaddr), eVar2 == 0)) {
    iVar1 = *(int *)((int)&extaddr->field_0 + 4);
    if (*(int *)&extaddr->field_0 == 0 && iVar1 == 0) {
      eVar2 = 5;
    }
    else if ((*(int *)&extaddr->field_0 == -1) && (iVar1 == -1)) {
      eVar2 = 5;
    }
  }
  return eVar2;
}

