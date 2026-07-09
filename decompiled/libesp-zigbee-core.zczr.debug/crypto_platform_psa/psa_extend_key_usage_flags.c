/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_psa.o -> psa_extend_key_usage_flags
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void psa_extend_key_usage_flags(uint *param_1)

{
  if ((int)(*param_1 << 0x13) < 0) {
    *param_1 = *param_1 | 0x400;
  }
  if ((int)(*param_1 << 0x12) < 0) {
    *param_1 = *param_1 | 0x800;
  }
  return;
}

