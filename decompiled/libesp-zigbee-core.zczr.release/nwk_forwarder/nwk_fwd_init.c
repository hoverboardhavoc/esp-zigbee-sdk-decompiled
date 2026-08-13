/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  zmsg_queue_init(&s_nwk_fwd);
  zmsg_tmque_init(&s_nwk_fwd,nwk_fwd_handle_tmque_timeout);
  tasklet_init(&s_nwk_fwd,nwk_fwd_direct_tx_task,0);
  puVar1 = &s_nwk_fwd;
  memset(&s_nwk_fwd,0,0x2d0);
  do {
    iVar2 = nwk_neighbor_table_get_capacity();
    uVar3 = mm_calloc(iVar2 + 7U >> 3,1);
    puVar1[0x10] = uVar3;
    puVar1 = puVar1 + 2;
  } while (puVar1 != (undefined4 *)&DAT_000116c4);
  return;
}

