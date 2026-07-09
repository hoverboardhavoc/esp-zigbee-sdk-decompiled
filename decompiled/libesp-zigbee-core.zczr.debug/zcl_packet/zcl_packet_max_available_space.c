/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_max_available_space
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short zcl_packet_max_available_space(undefined4 param_1,int param_2)

{
  short sVar1;
  short sVar2;
  
  zcl_cluster_fragment_is_supported();
  sVar1 = aps_get_max_asdu(param_1,0);
  if (param_2 == 0) {
    sVar2 = 3;
  }
  else {
    sVar2 = 5;
  }
  return sVar1 - sVar2;
}

