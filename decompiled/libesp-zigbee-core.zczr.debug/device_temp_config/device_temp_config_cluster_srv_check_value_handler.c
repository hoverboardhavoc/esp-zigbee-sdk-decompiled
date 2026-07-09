/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> device_temp_config.o -> device_temp_config_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 device_temp_config_cluster_srv_check_value_handler(uint param_1,byte *param_2)

{
  if (param_1 == 0x10) {
    if (*param_2 < 3) {
      return 0;
    }
    return 0x87;
  }
  if (0x10 < param_1) {
    if (param_1 == 0x11) {
      if (*(short *)param_2 == -0x8000) {
        return 0;
      }
      if (((int)*(short *)param_2 + 200U & 0xffff) < 0x191) {
        return 0;
      }
      return 0x87;
    }
    if (param_1 != 0x12) {
      return 0;
    }
    if (*(short *)param_2 != -0x8000) {
      if (((int)*(short *)param_2 + 200U & 0xffff) < 0x191) {
        return 0;
      }
      return 0x87;
    }
    return 0;
  }
  if (param_1 == 1) {
    if (*(short *)param_2 == -0x8000) {
      return 0;
    }
    if (((int)*(short *)param_2 + 200U & 0xffff) < 0x191) {
      return 0;
    }
    return 0x87;
  }
  if (param_1 != 2) {
    if (param_1 != 0) {
      return 0;
    }
    if (*(short *)param_2 != -0x8000) {
      if (((int)*(short *)param_2 + 200U & 0xffff) < 0x191) {
        return 0;
      }
      return 0x87;
    }
    return 0;
  }
  if (*(short *)param_2 == -0x8000) {
    return 0;
  }
  if (((int)*(short *)param_2 + 200U & 0xffff) < 0x191) {
    return 0;
  }
  return 0x87;
}

