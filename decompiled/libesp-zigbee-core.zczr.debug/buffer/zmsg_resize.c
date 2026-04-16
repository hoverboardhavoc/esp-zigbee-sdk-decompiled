/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_resize
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t zmsg_resize(zmsg_t *msg,uint16_t length)

{
  uint16_t uVar1;
  uint16_t uVar2;
  ushort uVar3;
  ezb_err_t eVar4;
  buffer_t *bufs;
  int iVar5;
  buffer_t *src_buf;
  
  bufs = (buffer_t *)&msg->chunks;
  uVar1 = msg->header;
  uVar2 = msg->tail;
  uVar3 = 0;
  src_buf = bufs;
  do {
    if ((ushort)(uVar2 + uVar1 + length) <= uVar3) {
      if (bufs == src_buf) {
        src_buf = buffers_get_last(bufs);
      }
      buffer_move_tail(bufs,src_buf,msg->tail);
      eVar4 = 0;
_L0:
      free_bufpool_buffers(*(buffer_t **)&bufs->field_0);
      bufs->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)0x0;
      return eVar4;
    }
    if (*(int *)&bufs->field_0 == 0) {
      iVar5 = mempool_malloc(0);
      bufs->field_0 = (anon_union_4_2_77b2d3ce_for_buffer_s_0)iVar5;
      if (iVar5 == 0) {
        eVar4 = 1;
        goto _L0;
      }
    }
    else {
      src_buf = *(buffer_t **)&src_buf->field_0;
    }
    bufs = *(buffer_t **)&bufs->field_0;
    uVar3 = uVar3 + 0xac;
  } while( true );
}

