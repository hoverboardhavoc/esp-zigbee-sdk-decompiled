/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> psa_extend_key_usage_flags
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void psa_extend_key_usage_flags(psa_key_usage_t *usage_flags)

{
  if ((int)(*usage_flags << 0x13) < 0) {
    *usage_flags = *usage_flags | 0x400;
  }
  if ((int)(*usage_flags << 0x12) < 0) {
    *usage_flags = *usage_flags | 0x800;
  }
  return;
}

