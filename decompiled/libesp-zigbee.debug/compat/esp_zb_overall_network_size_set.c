/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_overall_network_size_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_overall_network_size_set(ushort param_1)

{
  int iStack_24;
  ushort uStack_20;
  ushort uStack_1e;
  int iStack_1c;
  uint uStack_18;
  undefined2 uStack_14;
  
  uStack_14 = 0;
  iStack_24 = (uint)param_1 << 0x10;
  _uStack_20 = CONCAT22(param_1,param_1);
  iStack_1c = (uint)param_1 << 0x10;
  uStack_18 = (uint)param_1;
  ezb_config_memory(&iStack_24);
  esp_zigbee_err_to_esp();
  return;
}

