/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_intrp_prepend_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_intrp_prepend_header(zmsg_t *msg)

{
  ezb_err_t eVar1;
  undefined2 auStack_12 [2];
  uint16_t fcf;
  
  auStack_12[0] = 0xb;
  eVar1 = zmsg_prepend_bytes(2,auStack_12);
  return eVar1;
}

