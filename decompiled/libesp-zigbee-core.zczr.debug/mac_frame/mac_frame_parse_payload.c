/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_parse_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_frame_parse_payload(int *param_1,int param_2,char *param_3)

{
  if (param_1 == (int *)0x0) {
    return 2;
  }
  if (param_3 != (char *)0x0) {
    if ((param_2 - 3U & 0xff) < 0x7c) {
      *(int *)(param_3 + 4) = *param_1 + param_2;
      *param_3 = ((char)param_1[1] - (char)param_2) + -2;
      return 0;
    }
    return 0x10;
  }
  return 2;
}

