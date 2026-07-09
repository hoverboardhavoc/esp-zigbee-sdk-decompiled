/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_server_sync_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_time_server_sync_start(undefined4 param_1)

{
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined2 *puStack_20;
  code *pcStack_1c;
  undefined4 uStack_18;
  undefined2 auStack_14 [8];
  
  uStack_2c = 0xfffd;
  uStack_28 = 0x104fffd;
  uStack_24 = 1;
  auStack_14[0] = 10;
  puStack_20 = auStack_14;
  pcStack_1c = zcl_time_server_sync_callback;
  uStack_18 = param_1;
  ezb_zdo_match_desc_req(&uStack_2c);
  return;
}

