/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_api.o -> ezb_mac_get_csma_ca_params
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_mac_get_csma_ca_params(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  iVar1 = nwk_mm_get_pib_attr(0,0x4f,param_1,1);
  if ((iVar1 == 0) && (iVar1 = nwk_mm_get_pib_attr(0x57,param_1 + 1), iVar1 == 0)) {
    iVar1 = nwk_mm_get_pib_attr(0x4e,param_1 + 2,1);
    return iVar1;
  }
  return iVar1;
}

