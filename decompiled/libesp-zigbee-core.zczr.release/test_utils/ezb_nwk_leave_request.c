/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> test_utils.o -> ezb_nwk_leave_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_nwk_leave_request(void *param_1)

{
  undefined1 auStack_1c [8];
  byte bStack_14;
  
  memcpy(auStack_1c,param_1,8);
  bStack_14 = bStack_14 & 0xfc | *(byte *)((int)param_1 + 8) & 3;
  nwk_leave_request(auStack_1c);
  return;
}

