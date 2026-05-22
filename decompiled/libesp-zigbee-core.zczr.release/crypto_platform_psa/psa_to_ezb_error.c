/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> crypto_platform_psa.o -> psa_to_ezb_error
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t psa_to_ezb_error(psa_status_t psa_status)

{
  ezb_err_t eVar1;
  
  if (psa_status == -0x87) {
    eVar1 = 2;
  }
  else {
    if (-0x87 < psa_status) {
      return -(uint)(psa_status != 0);
    }
    eVar1 = 0x13;
    if ((psa_status != -0x95) && (eVar1 = 1, psa_status != -0x8a)) {
      return -1;
    }
  }
  return eVar1;
}

