/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> basic_input_output_value.o -> multistate_basic_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint multistate_basic_cluster_srv_check_value_handler(int param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 == 0x51) {
    bVar1 = *param_2;
    bVar2 = 1;
  }
  else {
    if (param_1 != 0x6f) {
      if (param_1 != 0x4a) {
        return 0;
      }
      return (-(uint)(*(short *)param_2 != 0) & 0xffffff79) + 0x87;
    }
    bVar1 = *param_2;
    bVar2 = 0xf;
  }
  return -(uint)(bVar2 < bVar1) & 0x87;
}

