/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_network_status_to_str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * nwk_network_status_to_str(uint param_1)

{
  if (param_1 == 0xc) {
    return "MTO-Route failure";
  }
  if (param_1 < 0xd) {
    if (param_1 == 2) {
      return "Link failure";
    }
    if (2 < param_1) {
      if (param_1 == 9) {
        return "ParentLink failure";
      }
      if (param_1 == 0xb) {
        return "SourceRoute failure";
      }
      return "Unknown";
    }
    if (param_1 == 0) {
      return "Legacy no route";
    }
    if (param_1 == 1) {
      return "Legacy link failure";
    }
    return "Unknown";
  }
  if (param_1 == 0x10) {
    return "Address update";
  }
  if (0x10 < param_1) {
    if (param_1 == 0x13) {
      return "Command unknown";
    }
    if (param_1 == 0x14) {
      return "PANID conflict";
    }
    return "Unknown";
  }
  if (param_1 == 0xd) {
    return "Address conflict";
  }
  if (param_1 == 0xf) {
    return "PANID update";
  }
  return "Unknown";
}

