/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_extended_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_address_extended_by_short(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 auStack_12 [3];
  
  iVar1 = nwk_address_ref_by_short(auStack_12);
  if ((iVar1 == 0) &&
     ((iVar1 = nwk_address_extended_by_ref(auStack_12[0],param_1), iVar1 != 0 ||
      (iVar2 = ezb_eui64_is_invalid(param_1), iVar1 = 0, iVar2 != 0)))) {
    iVar1 = 5;
  }
  return iVar1;
}

