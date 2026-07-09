/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_route_disc_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_route_disc_done(uint param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ushort uStack_22;
  
  puVar1 = s_nwk_fwd;
  while ((undefined4 **)puVar1 != &s_nwk_fwd) {
    puVar2 = puVar1;
    if ((*(ushort *)((int)puVar1 + 0x16) & 0x10) != 0) {
      zmsg_read_le16_isra_0(puVar1,2,&uStack_22);
      if (uStack_22 == param_1) {
        if (param_2 == 0) {
          *(ushort *)((int)puVar1 + 0x16) = *(ushort *)((int)puVar1 + 0x16) & 0xffef;
          tasklet_post(&s_nwk_fwd);
        }
        else {
          puVar2 = (undefined4 *)puVar1[1];
          zmsg_queue_dequeue(&s_nwk_fwd,puVar1);
          nwk_fwd_finish_tx(puVar1,param_2);
        }
      }
    }
    puVar1 = (undefined4 *)*puVar2;
  }
  return;
}

