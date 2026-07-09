/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_permit_joining_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_permit_joining_req_cb(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 != 0) {
    log_write(2,"bdb_comm.c","Broadcast PermitJoiningReq failed(0x%x)");
  }
  iVar1 = nwk_is_device_zczr();
  if ((iVar1 != 0) && (uVar2 = nwk_permit_joining(0xb4), uVar2 != 0)) {
    log_write(1,"bdb_comm.c","nwk_permit_joining(BDBC_MIN_COMMISSIONING_TIME) failed (c:%d,e:0x%x)",
              (int)uVar2 >> 8 & 0xff,uVar2 & 0xff);
  }
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xd4c) = 0;
  bdb_comm_finish_network_steering();
  return;
}

