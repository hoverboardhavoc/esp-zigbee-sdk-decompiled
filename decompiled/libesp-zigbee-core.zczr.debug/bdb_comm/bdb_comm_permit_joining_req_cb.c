/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_permit_joining_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bdb_comm_permit_joining_req_cb
               (ezb_zdo_nwk_mgmt_permit_joining_req_result_t *result,void *unused)

{
  int iVar1;
  uint uVar2;
  
  if (result->error != 0) {
    unused = (void *)log_write(2,"bdb_comm.c","Broadcast PermitJoiningReq failed(0x%x)");
  }
  iVar1 = nwk_is_device_zczr(unused);
  if ((iVar1 != 0) && (uVar2 = nwk_permit_joining(0xb4), uVar2 != 0)) {
    log_write(1,"bdb_comm.c","nwk_permit_joining(BDBC_MIN_COMMISSIONING_TIME) failed (c:%d,e:0x%x)",
              (int)uVar2 >> 8 & 0xff,uVar2 & 0xff);
  }
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xda0) = 0;
  bdb_comm_finish_network_steering();
  return;
}

