/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_direct_tx_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_direct_tx_task(void)

{
  int iVar1;
  int iVar2;
  uint uStack_18;
  uint uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  iVar1 = nwk_fwd_prepare_next_direct_tx(&uStack_18);
  if (iVar1 != 0) {
    if (((uStack_14 & 0x1000000) != 0) &&
       (iVar2 = nwk_mesh_generate_rrec(uStack_18 & 0xffff,uStack_18 >> 0x10), iVar2 != 0)) {
      nwk_fwd_mac_data_req(uStack_14 >> 0x10 & 0xff,uStack_14 & 0xffff,0);
    }
    zmsg_queue_dequeue(&s_nwk_fwd,iVar1);
    nwk_fwd_mac_data_req(iVar1,uStack_14 >> 0x10 & 0xff,uStack_14 & 0xffff,0);
    tasklet_post(&s_nwk_fwd);
  }
  return;
}

