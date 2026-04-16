/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_retrans_task(aps_tx_context_t *tx_ctx)

{
  zmsg_t *msg;
  aps_retrans_ent_t *ent;
  int iVar1;
  
  msg = (zmsg_t *)zmsg_queue_get_head(&tx_ctx->tx_q);
  if ((msg != (zmsg_t *)0x0) && (ent = aps_retrans_ent_new(tx_ctx), ent != (aps_retrans_ent_t *)0x0)
     ) {
    zmsg_queue_dequeue(&tx_ctx->tx_q,msg);
    iVar1 = core_globals_get();
    aps_retrans_ent_init(ent,*(uint8_t *)(iVar1 + 2));
    aps_retrans_ent_set_msg(ent,msg);
    aps_retrans_send(ent);
    tasklet_post(tx_ctx);
  }
  return;
}

