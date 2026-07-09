/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> test_utils.o -> ezb_nwk_leave_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_nwk_leave_request(undefined1 *param_1)

{
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  byte bStack_14;
  
  uStack_1c = *param_1;
  uStack_1b = param_1[1];
  uStack_1a = param_1[2];
  uStack_19 = param_1[3];
  uStack_18 = param_1[4];
  uStack_17 = param_1[5];
  uStack_16 = param_1[6];
  uStack_15 = param_1[7];
  bStack_14 = (byte)(((byte)param_1[8] >> 1 & 1) << 1) | bStack_14 & 0xfc | param_1[8] & 1;
  nwk_leave_request(&uStack_1c);
  return;
}

