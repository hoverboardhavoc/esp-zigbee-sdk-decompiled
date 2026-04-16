/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_retrans.o -> aps_retrans_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_retrans_task(aps_tx_context_t *tx_ctx)

{
  uint8_t w_sz;
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  zmsg_queue_t *pzVar9;
  aps_retrans_ent_t *retrans;
  
  pzVar9 = &tx_ctx->tx_q;
  iVar4 = zmsg_queue_get_head(pzVar9);
  if (iVar4 != 0) {
    uVar5 = bitmap_find_first_zero_bit(tx_ctx->ent_in_use,0x20);
    uVar1 = uVar5 & 0xff;
    if (uVar1 < 0x20) {
      uVar2 = 1 << (uVar5 & 7) & 0xff;
      uVar6 = __atomic_fetch_or_1(tx_ctx->ent_in_use + (uVar1 >> 3),uVar2,5);
      uVar5 = uVar1;
      if ((uVar2 & uVar6) == 0) goto _L0;
      do {
        __assert_func(0,0,0,0);
        uVar5 = uVar1;
_L0:
        uVar1 = uVar5 * 0x20;
        retrans = tx_ctx->ents + uVar5;
        memset(retrans,0,0x20);
        aps_retrans_start_fast_poll();
        zmsg_queue_dequeue(pzVar9,iVar4);
        iVar7 = core_globals_get();
        uVar3 = *(undefined1 *)(iVar7 + 2);
        pzVar9 = (zmsg_queue_t *)&tx_ctx->ents[uVar5 - 1].dst_addr;
        milli_timer_init(&tx_ctx->ents[uVar5].tm,aps_retrans_send,retrans);
        *(undefined1 *)((int)pzVar9 + 0x39) = uVar3;
        *(int *)((int)pzVar9 + 0x1c) = iVar4;
        uVar3 = aps_frame_get_aps_cntr(iVar4);
        *(undefined1 *)((int)pzVar9 + 0x22) = uVar3;
        zmsg_get_footer(*(undefined4 *)((int)pzVar9 + 0x1c),&tx_ctx->ents[uVar5].dst_addr,2);
        zmsg_remove_footer(*(undefined4 *)((int)pzVar9 + 0x1c),2);
        zmsg_get_footer(*(undefined4 *)((int)pzVar9 + 0x1c),&tx_ctx->ents[uVar5].blk_sz,1);
        zmsg_remove_footer(*(undefined4 *)((int)pzVar9 + 0x1c),1);
        iVar7 = zmsg_get_length(*(undefined4 *)((int)pzVar9 + 0x1c));
        iVar8 = zmsg_get_offset(*(undefined4 *)((int)pzVar9 + 0x1c));
        w_sz = *(uint8_t *)((int)pzVar9 + 0x39);
      } while (7 < (byte)(w_sz - 1));
      (retrans->w).blk_nr =
           (uint8_t)((int)((iVar7 - iVar8) + (uint)*(byte *)((int)pzVar9 + 0x35) + -1) /
                    (int)(uint)*(byte *)((int)pzVar9 + 0x35));
      (retrans->w).blk_start = '\0';
      aps_tx_window_reset_slots(&tx_ctx->ents[uVar5].w,w_sz);
      aps_retrans_send(retrans);
      tasklet_post(tx_ctx);
      return;
    }
  }
  return;
}

