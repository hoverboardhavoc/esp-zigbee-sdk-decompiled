/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_comm_close_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 bdb_comm_close_network(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 uStack_1c;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  code *pcStack_18;
  undefined4 uStack_14;
  
  iVar1 = zdo_dev_joined();
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    uStack_1c = 0xfffc;
    uStack_19 = 1;
    uStack_1a = 0;
    pcStack_18 = zdo_comm_permit_joining_req_cb;
    uStack_14 = 0;
    uVar2 = zdo_nwk_mgmt_permit_joining_req(&uStack_1c);
  }
  return uVar2;
}

