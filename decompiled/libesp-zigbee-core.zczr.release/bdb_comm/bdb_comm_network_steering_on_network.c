/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_network_steering_on_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_network_steering_on_network(void)

{
  int iVar1;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  uStack_1c = 0x1b4fffc;
  uStack_14 = 0;
  pcStack_18 = bdb_comm_permit_joining_req_cb;
  iVar1 = zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
  if (iVar1 != 0) {
    uStack_20 = 0;
    uStack_24 = 0xffffffff;
    bdb_comm_permit_joining_req_cb(&uStack_24,0);
  }
  return;
}

