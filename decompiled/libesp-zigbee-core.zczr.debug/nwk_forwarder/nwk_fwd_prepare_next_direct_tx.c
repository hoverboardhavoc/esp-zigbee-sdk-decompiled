/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_prepare_next_direct_tx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * nwk_fwd_prepare_next_direct_tx(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = s_nwk_fwd;
  do {
    if ((undefined4 **)puVar1 == &s_nwk_fwd) {
      return (undefined4 *)0x0;
    }
    if ((*(ushort *)((int)puVar1 + 0x16) & 0x10) == 0) {
      iVar2 = nwk_fwd_update_route(puVar1,param_1);
      if (iVar2 == 0) {
        return puVar1;
      }
      if (iVar2 == 0xc) {
        *(ushort *)((int)puVar1 + 0x16) = *(ushort *)((int)puVar1 + 0x16) | 0x10;
      }
      else {
        puVar3 = (undefined4 *)puVar1[1];
        zmsg_queue_dequeue(&s_nwk_fwd,puVar1);
        nwk_fwd_finish_tx(puVar1,iVar2);
        puVar1 = puVar3;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

