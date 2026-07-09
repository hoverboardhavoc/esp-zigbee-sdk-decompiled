/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> basic_input_output_value.o -> binary_basic_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 binary_basic_cluster_srv_check_value_handler(int param_1,byte *param_2)

{
  if (param_1 != 0x55) {
    if (param_1 == 0x6f) {
      if (*param_2 < 0x10) {
        return 0;
      }
      return 0x87;
    }
    if (param_1 != 0x51) {
      return 0;
    }
  }
  if (*param_2 < 2) {
    return 0;
  }
  return 0x87;
}

