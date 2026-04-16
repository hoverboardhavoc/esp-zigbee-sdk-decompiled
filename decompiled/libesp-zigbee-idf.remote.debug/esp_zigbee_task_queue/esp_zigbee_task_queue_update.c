/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_task_queue.o -> esp_zigbee_task_queue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zigbee_task_queue_update(esp_zigbee_mainloop_context_t *ctx)

{
  int iVar1;
  __fd_mask *p_Var2;
  
  iVar1 = s_task_queue_event_fd;
  if (-1 < s_task_queue_event_fd) {
    if ((uint)s_task_queue_event_fd < 0x40) {
      p_Var2 = (ctx->read_fds).__fds_bits +
               ((int)((s_task_queue_event_fd >> 0x1f & 0x1fU) + s_task_queue_event_fd) >> 5);
      *p_Var2 = *p_Var2 | 1 << (s_task_queue_event_fd & 0x1fU);
    }
    if (ctx->max_fd < iVar1) {
      ctx->max_fd = iVar1;
    }
  }
  iVar1 = ezb_tasklet_has_pendings();
  if (iVar1 != 0) {
    *(undefined4 *)&(ctx->timeout).tv_sec = 0;
    *(undefined4 *)((int)&(ctx->timeout).tv_sec + 4) = 0;
    (ctx->timeout).tv_usec = 0;
  }
  return;
}

